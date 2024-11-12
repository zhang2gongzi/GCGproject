#ifndef _CFILL
#define _CFILL

#include "gsharp.h"
#include <stdio.h>
#include <QPainter>
class CFill
{
public:
	CFill();
	virtual ~CFill();
	void SetPoint(QPointF *p, int);//��ʼ������Ͷ�����Ŀ
	void CreateBucket();//����Ͱ
	void CreateEdge();//�߱�
	void AddET(CAET *);//�ϲ�ET��
	void ETOrder();//ET������
	void Gouraud(QImage *image);//�������
	void ClearMemory();//�����ڴ�
	void DeleteAETChain(CAET* pAET);//ɾ���߱�
protected:
	int     PNum;//�������
	QPointF    *P;//�������궯̬����
	CAET    *pHeadE, *pCurrentE, *pEdge; //��Ч�߱���ָ��
	CBucket *pHeadB, *pCurrentB;        //Ͱ����ָ��
};

#endif // !_CFILL
