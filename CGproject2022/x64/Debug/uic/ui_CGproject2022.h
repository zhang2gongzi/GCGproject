/********************************************************************************
** Form generated from reading UI file 'CGproject2022.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CGPROJECT2022_H
#define UI_CGPROJECT2022_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CGproject2022Class
{
public:
    QAction *actionDDALine;
    QAction *actionMidLine;
    QAction *actionBresenhamLine;
    QAction *actionMidCir;
    QAction *actionBresenhamCir;
    QAction *actionMidEllipse;
    QAction *actionWu;
    QAction *actionScanLine;
    QAction *actionEdgeFill;
    QAction *actionFloodFill;
    QAction *actionDraw;
    QAction *actionTranslation;
    QAction *actionRotate;
    QAction *actionZoom;
    QAction *actionCohen_Sutherland;
    QAction *actionMidLineClipping;
    QAction *actionBarskey;
    QAction *actionSecondOrderBezier;
    QAction *actionThirdOrderBezier;
    QAction *actionSecondOrderBSpline;
    QAction *actionThirdOrderBSpline;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuChapter1;
    QMenu *menuChapter2;
    QMenu *menuChapter3;
    QMenu *menuChapter6;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CGproject2022Class)
    {
        if (CGproject2022Class->objectName().isEmpty())
            CGproject2022Class->setObjectName(QString::fromUtf8("CGproject2022Class"));
        CGproject2022Class->resize(800, 600);
        actionDDALine = new QAction(CGproject2022Class);
        actionDDALine->setObjectName(QString::fromUtf8("actionDDALine"));
        actionMidLine = new QAction(CGproject2022Class);
        actionMidLine->setObjectName(QString::fromUtf8("actionMidLine"));
        actionBresenhamLine = new QAction(CGproject2022Class);
        actionBresenhamLine->setObjectName(QString::fromUtf8("actionBresenhamLine"));
        actionMidCir = new QAction(CGproject2022Class);
        actionMidCir->setObjectName(QString::fromUtf8("actionMidCir"));
        actionBresenhamCir = new QAction(CGproject2022Class);
        actionBresenhamCir->setObjectName(QString::fromUtf8("actionBresenhamCir"));
        actionMidEllipse = new QAction(CGproject2022Class);
        actionMidEllipse->setObjectName(QString::fromUtf8("actionMidEllipse"));
        actionWu = new QAction(CGproject2022Class);
        actionWu->setObjectName(QString::fromUtf8("actionWu"));
        actionScanLine = new QAction(CGproject2022Class);
        actionScanLine->setObjectName(QString::fromUtf8("actionScanLine"));
        actionEdgeFill = new QAction(CGproject2022Class);
        actionEdgeFill->setObjectName(QString::fromUtf8("actionEdgeFill"));
        actionFloodFill = new QAction(CGproject2022Class);
        actionFloodFill->setObjectName(QString::fromUtf8("actionFloodFill"));
        actionDraw = new QAction(CGproject2022Class);
        actionDraw->setObjectName(QString::fromUtf8("actionDraw"));
        actionTranslation = new QAction(CGproject2022Class);
        actionTranslation->setObjectName(QString::fromUtf8("actionTranslation"));
        actionRotate = new QAction(CGproject2022Class);
        actionRotate->setObjectName(QString::fromUtf8("actionRotate"));
        actionZoom = new QAction(CGproject2022Class);
        actionZoom->setObjectName(QString::fromUtf8("actionZoom"));
        actionCohen_Sutherland = new QAction(CGproject2022Class);
        actionCohen_Sutherland->setObjectName(QString::fromUtf8("actionCohen_Sutherland"));
        actionMidLineClipping = new QAction(CGproject2022Class);
        actionMidLineClipping->setObjectName(QString::fromUtf8("actionMidLineClipping"));
        actionBarskey = new QAction(CGproject2022Class);
        actionBarskey->setObjectName(QString::fromUtf8("actionBarskey"));
        actionSecondOrderBezier = new QAction(CGproject2022Class);
        actionSecondOrderBezier->setObjectName(QString::fromUtf8("actionSecondOrderBezier"));
        actionThirdOrderBezier = new QAction(CGproject2022Class);
        actionThirdOrderBezier->setObjectName(QString::fromUtf8("actionThirdOrderBezier"));
        actionSecondOrderBSpline = new QAction(CGproject2022Class);
        actionSecondOrderBSpline->setObjectName(QString::fromUtf8("actionSecondOrderBSpline"));
        actionThirdOrderBSpline = new QAction(CGproject2022Class);
        actionThirdOrderBSpline->setObjectName(QString::fromUtf8("actionThirdOrderBSpline"));
        centralWidget = new QWidget(CGproject2022Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        CGproject2022Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CGproject2022Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 26));
        menuChapter1 = new QMenu(menuBar);
        menuChapter1->setObjectName(QString::fromUtf8("menuChapter1"));
        menuChapter2 = new QMenu(menuBar);
        menuChapter2->setObjectName(QString::fromUtf8("menuChapter2"));
        menuChapter3 = new QMenu(menuBar);
        menuChapter3->setObjectName(QString::fromUtf8("menuChapter3"));
        menuChapter6 = new QMenu(menuBar);
        menuChapter6->setObjectName(QString::fromUtf8("menuChapter6"));
        CGproject2022Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CGproject2022Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CGproject2022Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CGproject2022Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CGproject2022Class->setStatusBar(statusBar);

        menuBar->addAction(menuChapter1->menuAction());
        menuBar->addAction(menuChapter2->menuAction());
        menuBar->addAction(menuChapter3->menuAction());
        menuBar->addAction(menuChapter6->menuAction());
        menuChapter1->addAction(actionDDALine);
        menuChapter1->addAction(actionMidLine);
        menuChapter1->addAction(actionBresenhamLine);
        menuChapter1->addAction(actionMidCir);
        menuChapter1->addAction(actionBresenhamCir);
        menuChapter1->addAction(actionMidEllipse);
        menuChapter1->addAction(actionWu);
        menuChapter2->addAction(actionScanLine);
        menuChapter2->addAction(actionEdgeFill);
        menuChapter2->addAction(actionFloodFill);
        menuChapter3->addAction(actionDraw);
        menuChapter3->addAction(actionTranslation);
        menuChapter3->addAction(actionRotate);
        menuChapter3->addAction(actionZoom);
        menuChapter3->addAction(actionCohen_Sutherland);
        menuChapter3->addAction(actionMidLineClipping);
        menuChapter3->addAction(actionBarskey);
        menuChapter6->addAction(actionSecondOrderBezier);
        menuChapter6->addAction(actionThirdOrderBezier);
        menuChapter6->addAction(actionSecondOrderBSpline);
        menuChapter6->addAction(actionThirdOrderBSpline);

        retranslateUi(CGproject2022Class);

        QMetaObject::connectSlotsByName(CGproject2022Class);
    } // setupUi

    void retranslateUi(QMainWindow *CGproject2022Class)
    {
        CGproject2022Class->setWindowTitle(QApplication::translate("CGproject2022Class", "CGproject2022", nullptr));
        actionDDALine->setText(QApplication::translate("CGproject2022Class", "DDALine", nullptr));
        actionMidLine->setText(QApplication::translate("CGproject2022Class", "MidLine", nullptr));
        actionBresenhamLine->setText(QApplication::translate("CGproject2022Class", "BresenhamLine", nullptr));
        actionMidCir->setText(QApplication::translate("CGproject2022Class", "MidCir", nullptr));
        actionBresenhamCir->setText(QApplication::translate("CGproject2022Class", "BresenhamCir", nullptr));
        actionMidEllipse->setText(QApplication::translate("CGproject2022Class", "MidEllipse", nullptr));
        actionWu->setText(QApplication::translate("CGproject2022Class", "Wu", nullptr));
        actionScanLine->setText(QApplication::translate("CGproject2022Class", "ScanLine", nullptr));
        actionEdgeFill->setText(QApplication::translate("CGproject2022Class", "EdgeFill", nullptr));
        actionFloodFill->setText(QApplication::translate("CGproject2022Class", "FloodFill", nullptr));
        actionDraw->setText(QApplication::translate("CGproject2022Class", "Draw", nullptr));
        actionTranslation->setText(QApplication::translate("CGproject2022Class", "Translation", nullptr));
        actionRotate->setText(QApplication::translate("CGproject2022Class", "Rotate", nullptr));
        actionZoom->setText(QApplication::translate("CGproject2022Class", "Zoom", nullptr));
        actionCohen_Sutherland->setText(QApplication::translate("CGproject2022Class", "Cohen-Sutherland", nullptr));
        actionMidLineClipping->setText(QApplication::translate("CGproject2022Class", "MidLineClipping", nullptr));
        actionBarskey->setText(QApplication::translate("CGproject2022Class", "Barskey", nullptr));
        actionSecondOrderBezier->setText(QApplication::translate("CGproject2022Class", "SecondOrderBezier", nullptr));
        actionThirdOrderBezier->setText(QApplication::translate("CGproject2022Class", "ThirdOrderBezier", nullptr));
        actionSecondOrderBSpline->setText(QApplication::translate("CGproject2022Class", "SecondOrderBSpline", nullptr));
        actionThirdOrderBSpline->setText(QApplication::translate("CGproject2022Class", "ThirdOrderBSpline", nullptr));
        menuChapter1->setTitle(QApplication::translate("CGproject2022Class", "Chapter1", nullptr));
        menuChapter2->setTitle(QApplication::translate("CGproject2022Class", "Chapter2", nullptr));
        menuChapter3->setTitle(QApplication::translate("CGproject2022Class", "Chapter3", nullptr));
        menuChapter6->setTitle(QApplication::translate("CGproject2022Class", "Chapter6", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CGproject2022Class: public Ui_CGproject2022Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CGPROJECT2022_H
