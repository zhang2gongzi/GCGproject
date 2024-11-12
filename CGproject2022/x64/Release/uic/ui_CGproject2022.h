/********************************************************************************
** Form generated from reading UI file 'CGproject2022.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CGPROJECT2022_H
#define UI_CGPROJECT2022_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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
            CGproject2022Class->setObjectName(QStringLiteral("CGproject2022Class"));
        CGproject2022Class->resize(800, 600);
        actionDDALine = new QAction(CGproject2022Class);
        actionDDALine->setObjectName(QStringLiteral("actionDDALine"));
        actionMidLine = new QAction(CGproject2022Class);
        actionMidLine->setObjectName(QStringLiteral("actionMidLine"));
        actionBresenhamLine = new QAction(CGproject2022Class);
        actionBresenhamLine->setObjectName(QStringLiteral("actionBresenhamLine"));
        actionMidCir = new QAction(CGproject2022Class);
        actionMidCir->setObjectName(QStringLiteral("actionMidCir"));
        actionBresenhamCir = new QAction(CGproject2022Class);
        actionBresenhamCir->setObjectName(QStringLiteral("actionBresenhamCir"));
        actionMidEllipse = new QAction(CGproject2022Class);
        actionMidEllipse->setObjectName(QStringLiteral("actionMidEllipse"));
        actionWu = new QAction(CGproject2022Class);
        actionWu->setObjectName(QStringLiteral("actionWu"));
        actionScanLine = new QAction(CGproject2022Class);
        actionScanLine->setObjectName(QStringLiteral("actionScanLine"));
        actionEdgeFill = new QAction(CGproject2022Class);
        actionEdgeFill->setObjectName(QStringLiteral("actionEdgeFill"));
        actionFloodFill = new QAction(CGproject2022Class);
        actionFloodFill->setObjectName(QStringLiteral("actionFloodFill"));
        actionDraw = new QAction(CGproject2022Class);
        actionDraw->setObjectName(QStringLiteral("actionDraw"));
        actionTranslation = new QAction(CGproject2022Class);
        actionTranslation->setObjectName(QStringLiteral("actionTranslation"));
        actionRotate = new QAction(CGproject2022Class);
        actionRotate->setObjectName(QStringLiteral("actionRotate"));
        actionZoom = new QAction(CGproject2022Class);
        actionZoom->setObjectName(QStringLiteral("actionZoom"));
        actionCohen_Sutherland = new QAction(CGproject2022Class);
        actionCohen_Sutherland->setObjectName(QStringLiteral("actionCohen_Sutherland"));
        actionMidLineClipping = new QAction(CGproject2022Class);
        actionMidLineClipping->setObjectName(QStringLiteral("actionMidLineClipping"));
        actionBarskey = new QAction(CGproject2022Class);
        actionBarskey->setObjectName(QStringLiteral("actionBarskey"));
        actionSecondOrderBezier = new QAction(CGproject2022Class);
        actionSecondOrderBezier->setObjectName(QStringLiteral("actionSecondOrderBezier"));
        actionThirdOrderBezier = new QAction(CGproject2022Class);
        actionThirdOrderBezier->setObjectName(QStringLiteral("actionThirdOrderBezier"));
        actionSecondOrderBSpline = new QAction(CGproject2022Class);
        actionSecondOrderBSpline->setObjectName(QStringLiteral("actionSecondOrderBSpline"));
        actionThirdOrderBSpline = new QAction(CGproject2022Class);
        actionThirdOrderBSpline->setObjectName(QStringLiteral("actionThirdOrderBSpline"));
        centralWidget = new QWidget(CGproject2022Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CGproject2022Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CGproject2022Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 26));
        menuChapter1 = new QMenu(menuBar);
        menuChapter1->setObjectName(QStringLiteral("menuChapter1"));
        menuChapter2 = new QMenu(menuBar);
        menuChapter2->setObjectName(QStringLiteral("menuChapter2"));
        menuChapter3 = new QMenu(menuBar);
        menuChapter3->setObjectName(QStringLiteral("menuChapter3"));
        menuChapter6 = new QMenu(menuBar);
        menuChapter6->setObjectName(QStringLiteral("menuChapter6"));
        CGproject2022Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CGproject2022Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CGproject2022Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CGproject2022Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
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
        CGproject2022Class->setWindowTitle(QApplication::translate("CGproject2022Class", "CGproject2022", Q_NULLPTR));
        actionDDALine->setText(QApplication::translate("CGproject2022Class", "DDALine", Q_NULLPTR));
        actionMidLine->setText(QApplication::translate("CGproject2022Class", "MidLine", Q_NULLPTR));
        actionBresenhamLine->setText(QApplication::translate("CGproject2022Class", "BresenhamLine", Q_NULLPTR));
        actionMidCir->setText(QApplication::translate("CGproject2022Class", "MidCir", Q_NULLPTR));
        actionBresenhamCir->setText(QApplication::translate("CGproject2022Class", "BresenhamCir", Q_NULLPTR));
        actionMidEllipse->setText(QApplication::translate("CGproject2022Class", "MidEllipse", Q_NULLPTR));
        actionWu->setText(QApplication::translate("CGproject2022Class", "Wu", Q_NULLPTR));
        actionScanLine->setText(QApplication::translate("CGproject2022Class", "ScanLine", Q_NULLPTR));
        actionEdgeFill->setText(QApplication::translate("CGproject2022Class", "EdgeFill", Q_NULLPTR));
        actionFloodFill->setText(QApplication::translate("CGproject2022Class", "FloodFill", Q_NULLPTR));
        actionDraw->setText(QApplication::translate("CGproject2022Class", "Draw", Q_NULLPTR));
        actionTranslation->setText(QApplication::translate("CGproject2022Class", "Translation", Q_NULLPTR));
        actionRotate->setText(QApplication::translate("CGproject2022Class", "Rotate", Q_NULLPTR));
        actionZoom->setText(QApplication::translate("CGproject2022Class", "Zoom", Q_NULLPTR));
        actionCohen_Sutherland->setText(QApplication::translate("CGproject2022Class", "Cohen-Sutherland", Q_NULLPTR));
        actionMidLineClipping->setText(QApplication::translate("CGproject2022Class", "MidLineClipping", Q_NULLPTR));
        actionBarskey->setText(QApplication::translate("CGproject2022Class", "Barskey", Q_NULLPTR));
        actionSecondOrderBezier->setText(QApplication::translate("CGproject2022Class", "SecondOrderBezier", Q_NULLPTR));
        actionThirdOrderBezier->setText(QApplication::translate("CGproject2022Class", "ThirdOrderBezier", Q_NULLPTR));
        actionSecondOrderBSpline->setText(QApplication::translate("CGproject2022Class", "SecondOrderBSpline", Q_NULLPTR));
        actionThirdOrderBSpline->setText(QApplication::translate("CGproject2022Class", "ThirdOrderBSpline", Q_NULLPTR));
        menuChapter1->setTitle(QApplication::translate("CGproject2022Class", "Chapter1", Q_NULLPTR));
        menuChapter2->setTitle(QApplication::translate("CGproject2022Class", "Chapter2", Q_NULLPTR));
        menuChapter3->setTitle(QApplication::translate("CGproject2022Class", "Chapter3", Q_NULLPTR));
        menuChapter6->setTitle(QApplication::translate("CGproject2022Class", "Chapter6", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CGproject2022Class: public Ui_CGproject2022Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CGPROJECT2022_H
