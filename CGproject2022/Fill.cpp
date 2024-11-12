#include "Fill.h"


CFill::CFill()
{
	PNum = 0;
	P = NULL;
	pEdge = NULL;
	pHeadB = NULL;
	pHeadE = NULL;
	pCurrentB = NULL;
	pCurrentE = NULL;
}

CFill::~CFill()
{
	if (P != NULL)
	{
		delete[] P;
		P = NULL;
	}
	ClearMemory();
}
void CFill::SetPoint(QPointF *p, int m)
{
	P = new QPointF[m];//����һά��̬����
	for (int i = 0; i < m; i++)
	{
		P[i] = p[i];
	}
	PNum = m;//��¼��������
}
void CFill::CreateBucket()//����Ͱ��
{
	int yMin, yMax;
	yMin = yMax = P[0].y();
	for (int i = 0; i < PNum; i++)
	{
		if (P[i].y() < yMin)
		{
			yMin = P[i].y();

		}
		if (P[i].y() > yMax)
		{
			yMax = P[i].y();
		}
	}

	for (int y = yMin; y <= yMax; y++)
	{
		if (yMin == y)
		{
			pHeadB = new CBucket;
			pCurrentB = pHeadB;
			pCurrentB->ScanLine = yMin;
			pCurrentB->pET = NULL;
			pCurrentB->pNext = NULL;
		}
		else
		{
			pCurrentB->pNext = new CBucket;
			pCurrentB = pCurrentB->pNext;
			pCurrentB->ScanLine = y;
			pCurrentB->pET = NULL;
			pCurrentB->pNext = NULL;
		}
	}
}
void CFill::CreateEdge()//�����߱������������뵽��Ӧ��Ͱ�ڵ�
{
	for (int i = 0; i < PNum; i++)
	{
		pCurrentB = pHeadB;
		int j = (i + 1) % PNum;
		if (P[i].y() < P[j].y())
		{
			pEdge = new CAET;
			pEdge->x = P[i].x();
			pEdge->yMax = P[j].y();
			pEdge->k = (double)(P[j].x() - P[i].x()) / ((double)(P[j].y() - P[i].y()));

			pEdge->pNext = NULL;
			while (pCurrentB->ScanLine != P[i].y())
			{
				pCurrentB = pCurrentB->pNext;
			}
		}

		if (P[j].y() < P[i].y())
		{
			pEdge = new CAET;
			pEdge->x = P[j].x();
			pEdge->yMax = P[i].y();
			pEdge->k = (double)(P[i].x() - P[j].x()) / ((double)(P[i].y() - P[j].y()));
			pEdge->pNext = NULL;
			while (pCurrentB->ScanLine != P[j].y())
			{
				pCurrentB = pCurrentB->pNext;
			}
		}

		if (P[j].y() != P[i].y())
		{
			pCurrentE = pCurrentB->pET;
			if (pCurrentE == NULL)
			{
				pCurrentE = pEdge;
				pCurrentB->pET = pCurrentE;
			}
			else
			{
				while (NULL != pCurrentE->pNext)
				{
					pCurrentE = pCurrentE->pNext;
				}
				pCurrentE->pNext = pEdge;
			}
		}
	}
}
void CFill::AddET(CAET *pNewEdge)//�ϲ�ET��
{
	CAET *pCE = pHeadE;//�߱�ͷ���
	if (pCE == NULL)//���߱�Ϊ�գ���pNewEdge��Ϊ�߱�ͷ���
	{
		pHeadE = pNewEdge;
		pCE = pHeadE;
	}
	else//��pNewEdge���ӵ��߱�ĩβ��δ����
	{
		while (pCE->pNext != NULL)
		{
			pCE = pCE->pNext;
		}
		pCE->pNext = pNewEdge;
	}
}
void CFill::ETOrder()//�߱��ð�������㷨
{
	CAET *pT1, *pT2;
	int Count = 1;
	pT1 = pHeadE;
	if (pT1 == NULL)//û�бߣ�����Ҫ����
	{
		return;
	}
	if (pT1->pNext == NULL)//�����ET��û������ET��
	{
		return;//ֻ��һ���ߣ�����Ҫ����
	}
	while (pT1->pNext != NULL)//ͳ�Ʊ߽��ĸ���
	{
		Count++;
		pT1 = pT1->pNext;
	}
	for (int i = 0; i < Count - 1; i++)//ð������
	{
		CAET **pPre = &pHeadE;//pPre��¼���������ڵ��ǰ��һ���ڵ㣬��һ��Ϊͷ�ڵ�
		pT1 = pHeadE;
		for (int j = 0; j < Count - 1 - i; j++)
		{
			pT2 = pT1->pNext;

			if ((pT1->x > pT2->x) || ((pT1->x == pT2->x) && (pT1->k > pT2->k)))//�����������򽻻���ǰ�����߽���λ��
			{
				pT1->pNext = pT2->pNext;
				pT2->pNext = pT1;
				*pPre = pT2;
				pPre = &(pT2->pNext);//����λ��Ϊ�´α���׼��
			}
			else//��������ǰ�����߽���λ�ã�����pPre��pT1
			{
				pPre = &(pT1->pNext);
				pT1 = pT1->pNext;
			}
		}
	}
}
void CFill::Gouraud(QImage *image)//�������
{
	CAET *pT1 = NULL, *pT2 = NULL;
	pHeadE = NULL;
	for (pCurrentB = pHeadB; pCurrentB != NULL; pCurrentB = pCurrentB->pNext)
	{
		for (pCurrentE = pCurrentB->pET; pCurrentE != NULL; pCurrentE = pCurrentE->pNext)
		{
			pEdge = new CAET;
			pEdge->x = pCurrentE->x;
			pEdge->yMax = pCurrentE->yMax;
			pEdge->k = pCurrentE->k;
			pEdge->pNext = NULL;
			AddET(pEdge);
		}

		ETOrder();
		pT1 = pHeadE;
		if (pT1 == NULL)
		{
			return;
		}
		while (pCurrentB->ScanLine >= pT1->yMax)
		{
			CAET *pAETTEmp = pT1;
			pT1 = pT1->pNext;
			delete pAETTEmp;
			pHeadE = pT1;
			if (pHeadE == NULL)
			{
				return;
			}

		}
		if (pT1->pNext != NULL)
		{
			pT2 = pT1;
			pT1 = pT2->pNext;
		}

		while (pT1 != NULL)
		{
			if (pCurrentB->ScanLine >= pT1->yMax)
			{
				CAET *pAETTemp = pT1;
				pT2->pNext = pT1->pNext;
				pT1 = pT2->pNext;
				delete pAETTemp;
			}
			else
			{
				pT2 = pT1;
				pT1 = pT2->pNext;
			}
		}
		bool In = false;
		int xb, xe;
		for (pT1 = pHeadE; pT1 != NULL; pT1 = pT1->pNext)
		{
			if (false == In)
			{
				xb = (int)pT1->x;
				In = true;
			}
			else
			{
				xe = (int)pT1->x;
				for (int x = xb; x < xe; x++)
				{
					image->setPixel(x, pCurrentB->ScanLine, qRgb(255, 0, 255));
				}
				In = false;

			}
		}
		for (pT1 = pHeadE; pT1 != NULL; pT1 = pT1->pNext)
		{
			pT1->x = pT1->x + pT1->k;
		}
	}
}
void CFill::ClearMemory()//��ȫɾ������Ͱ��Ͱ�����ӵı�
{
	DeleteAETChain(pHeadE);//ɾ���߱�
	CBucket *pBucket = pHeadB;
	while (pBucket != NULL)//���ÿһ��Ͱ
	{
		CBucket *pBucketTemp = pBucket->pNext;
		DeleteAETChain(pBucket->pET);//ɾ��Ͱ����ı�
		delete pBucket;
		pBucket = pBucketTemp;
	}
	pHeadB = NULL;
	pHeadE = NULL;
}
void CFill::DeleteAETChain(CAET *pAET)//ɾ���߱�
{
	while (pAET != NULL)
	{
		CAET *pAETTemp = pAET->pNext;
		delete pAET;
		pAET = pAETTemp;
	}
}