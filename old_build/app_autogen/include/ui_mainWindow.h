/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_15;
    QTabWidget *tabWidget_2;
    QWidget *CreateTab_2;
    QVBoxLayout *verticalLayout_16;
    QFrame *LoadFrame_2;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_20;
    QComboBox *ModelsComboBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *iPosComboBox;
    QComboBox *jPosComboBox;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_2;
    QComboBox *ColorsComboBox;
    QPushButton *loadModelBtn;
    QFrame *MaterialFrame_2;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_21;
    QComboBox *MaterialsPairsComboBox;
    QPushButton *ChangeMaterialBtn;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *label_24;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *GlossyRadioBtn;
    QRadioButton *MatteRadioBtn;
    QWidget *TransformTab_2;
    QHBoxLayout *horizontalLayout_13;
    QFrame *frame_7;
    QVBoxLayout *verticalLayout_19;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_22;
    QLabel *label_35;
    QComboBox *AllModelsComboBox;
    QFrame *frame_8;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_23;
    QGridLayout *gridLayout_3;
    QComboBox *MoveTo_jPosComboBox;
    QComboBox *MoveTo_iPosComboBox;
    QLabel *label_25;
    QPushButton *MoveModelBtn;
    QFrame *frame_9;
    QVBoxLayout *verticalLayout_21;
    QLabel *label_26;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_27;
    QDoubleSpinBox *AngleModelDSP;
    QPushButton *RotateModelBtn;
    QFrame *MaterialFrame_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_34;
    QPushButton *DelModelBtn;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_16;
    QFrame *frame_10;
    QVBoxLayout *verticalLayout_22;
    QFrame *frame_11;
    QVBoxLayout *verticalLayout_23;
    QLabel *label_28;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_29;
    QDoubleSpinBox *AngleCameraDSB;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *LeftCameraBtn;
    QVBoxLayout *verticalLayout_24;
    QPushButton *UpCameraBtn;
    QPushButton *DownCameraBtn;
    QPushButton *RightCameraBtn;
    QFrame *frame_12;
    QVBoxLayout *verticalLayout_25;
    QLabel *label_30;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_31;
    QSpinBox *MoveCameraDSP;
    QPushButton *ZoomCameraBtn;
    QPushButton *MoveAwayCameraBtn;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_33;
    QLabel *PairMaterialLabel;
    QLabel *label_32;
    QTableWidget *TableWidget;
    QPushButton *drawBtn;
    QVBoxLayout *layoutForGraphicsView;
    QMenuBar *menubar;
    QMenu *exitMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(627, 578);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_4 = new QWidget(centralwidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setMinimumSize(QSize(350, 0));
        widget_4->setMaximumSize(QSize(400, 16777215));
        verticalLayout_15 = new QVBoxLayout(widget_4);
        verticalLayout_15->setSpacing(0);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_15->setSizeConstraint(QLayout::SetMinimumSize);
        tabWidget_2 = new QTabWidget(widget_4);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget_2->sizePolicy().hasHeightForWidth());
        tabWidget_2->setSizePolicy(sizePolicy);
        CreateTab_2 = new QWidget();
        CreateTab_2->setObjectName(QString::fromUtf8("CreateTab_2"));
        verticalLayout_16 = new QVBoxLayout(CreateTab_2);
        verticalLayout_16->setSpacing(0);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_16->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        LoadFrame_2 = new QFrame(CreateTab_2);
        LoadFrame_2->setObjectName(QString::fromUtf8("LoadFrame_2"));
        LoadFrame_2->setFrameShape(QFrame::StyledPanel);
        LoadFrame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_17 = new QVBoxLayout(LoadFrame_2);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        label_20 = new QLabel(LoadFrame_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        verticalLayout_17->addWidget(label_20);

        ModelsComboBox = new QComboBox(LoadFrame_2);
        ModelsComboBox->setObjectName(QString::fromUtf8("ModelsComboBox"));

        verticalLayout_17->addWidget(ModelsComboBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(LoadFrame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        iPosComboBox = new QComboBox(LoadFrame_2);
        iPosComboBox->setObjectName(QString::fromUtf8("iPosComboBox"));

        horizontalLayout->addWidget(iPosComboBox);

        jPosComboBox = new QComboBox(LoadFrame_2);
        jPosComboBox->setObjectName(QString::fromUtf8("jPosComboBox"));

        horizontalLayout->addWidget(jPosComboBox);


        verticalLayout_17->addLayout(horizontalLayout);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_2 = new QLabel(LoadFrame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_12->addWidget(label_2);

        ColorsComboBox = new QComboBox(LoadFrame_2);
        ColorsComboBox->setObjectName(QString::fromUtf8("ColorsComboBox"));

        horizontalLayout_12->addWidget(ColorsComboBox);


        verticalLayout_17->addLayout(horizontalLayout_12);

        loadModelBtn = new QPushButton(LoadFrame_2);
        loadModelBtn->setObjectName(QString::fromUtf8("loadModelBtn"));

        verticalLayout_17->addWidget(loadModelBtn);


        verticalLayout_16->addWidget(LoadFrame_2);

        MaterialFrame_2 = new QFrame(CreateTab_2);
        MaterialFrame_2->setObjectName(QString::fromUtf8("MaterialFrame_2"));
        MaterialFrame_2->setFrameShape(QFrame::StyledPanel);
        MaterialFrame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_18 = new QVBoxLayout(MaterialFrame_2);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        label_21 = new QLabel(MaterialFrame_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        verticalLayout_18->addWidget(label_21);

        MaterialsPairsComboBox = new QComboBox(MaterialFrame_2);
        MaterialsPairsComboBox->setObjectName(QString::fromUtf8("MaterialsPairsComboBox"));

        verticalLayout_18->addWidget(MaterialsPairsComboBox);

        ChangeMaterialBtn = new QPushButton(MaterialFrame_2);
        ChangeMaterialBtn->setObjectName(QString::fromUtf8("ChangeMaterialBtn"));

        verticalLayout_18->addWidget(ChangeMaterialBtn);


        verticalLayout_16->addWidget(MaterialFrame_2);

        frame = new QFrame(CreateTab_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_24 = new QLabel(frame);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        verticalLayout->addWidget(label_24);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        GlossyRadioBtn = new QRadioButton(frame);
        GlossyRadioBtn->setObjectName(QString::fromUtf8("GlossyRadioBtn"));
        GlossyRadioBtn->setChecked(true);

        horizontalLayout_4->addWidget(GlossyRadioBtn);

        MatteRadioBtn = new QRadioButton(frame);
        MatteRadioBtn->setObjectName(QString::fromUtf8("MatteRadioBtn"));
        MatteRadioBtn->setEnabled(true);

        horizontalLayout_4->addWidget(MatteRadioBtn);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_16->addWidget(frame);

        tabWidget_2->addTab(CreateTab_2, QString());
        TransformTab_2 = new QWidget();
        TransformTab_2->setObjectName(QString::fromUtf8("TransformTab_2"));
        horizontalLayout_13 = new QHBoxLayout(TransformTab_2);
        horizontalLayout_13->setSpacing(0);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        frame_7 = new QFrame(TransformTab_2);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        verticalLayout_19 = new QVBoxLayout(frame_7);
        verticalLayout_19->setSpacing(0);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        verticalLayout_19->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_22 = new QLabel(frame_7);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_14->addWidget(label_22);

        label_35 = new QLabel(frame_7);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy1);
        label_35->setMaximumSize(QSize(30, 16777215));
        label_35->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_14->addWidget(label_35);

        AllModelsComboBox = new QComboBox(frame_7);
        AllModelsComboBox->setObjectName(QString::fromUtf8("AllModelsComboBox"));

        horizontalLayout_14->addWidget(AllModelsComboBox);


        verticalLayout_19->addLayout(horizontalLayout_14);

        frame_8 = new QFrame(frame_7);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        verticalLayout_20 = new QVBoxLayout(frame_8);
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        label_23 = new QLabel(frame_8);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        verticalLayout_20->addWidget(label_23);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        MoveTo_jPosComboBox = new QComboBox(frame_8);
        MoveTo_jPosComboBox->setObjectName(QString::fromUtf8("MoveTo_jPosComboBox"));

        gridLayout_3->addWidget(MoveTo_jPosComboBox, 0, 2, 1, 1);

        MoveTo_iPosComboBox = new QComboBox(frame_8);
        MoveTo_iPosComboBox->setObjectName(QString::fromUtf8("MoveTo_iPosComboBox"));

        gridLayout_3->addWidget(MoveTo_iPosComboBox, 0, 1, 1, 1);

        label_25 = new QLabel(frame_8);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_3->addWidget(label_25, 0, 0, 1, 1);


        verticalLayout_20->addLayout(gridLayout_3);

        MoveModelBtn = new QPushButton(frame_8);
        MoveModelBtn->setObjectName(QString::fromUtf8("MoveModelBtn"));

        verticalLayout_20->addWidget(MoveModelBtn);


        verticalLayout_19->addWidget(frame_8);

        frame_9 = new QFrame(frame_7);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        verticalLayout_21 = new QVBoxLayout(frame_9);
        verticalLayout_21->setObjectName(QString::fromUtf8("verticalLayout_21"));
        label_26 = new QLabel(frame_9);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        verticalLayout_21->addWidget(label_26);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_27 = new QLabel(frame_9);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        horizontalLayout_15->addWidget(label_27);

        AngleModelDSP = new QDoubleSpinBox(frame_9);
        AngleModelDSP->setObjectName(QString::fromUtf8("AngleModelDSP"));
        QFont font;
        font.setPointSize(12);
        AngleModelDSP->setFont(font);
        AngleModelDSP->setFrame(true);
        AngleModelDSP->setDecimals(1);
        AngleModelDSP->setMinimum(-10000.000000000000000);
        AngleModelDSP->setMaximum(10000.000000000000000);
        AngleModelDSP->setSingleStep(10.000000000000000);
        AngleModelDSP->setValue(-30.000000000000000);

        horizontalLayout_15->addWidget(AngleModelDSP);


        verticalLayout_21->addLayout(horizontalLayout_15);

        RotateModelBtn = new QPushButton(frame_9);
        RotateModelBtn->setObjectName(QString::fromUtf8("RotateModelBtn"));

        verticalLayout_21->addWidget(RotateModelBtn);


        verticalLayout_19->addWidget(frame_9);

        MaterialFrame_3 = new QFrame(frame_7);
        MaterialFrame_3->setObjectName(QString::fromUtf8("MaterialFrame_3"));
        MaterialFrame_3->setFrameShape(QFrame::StyledPanel);
        MaterialFrame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(MaterialFrame_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_34 = new QLabel(MaterialFrame_3);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        horizontalLayout_3->addWidget(label_34);

        DelModelBtn = new QPushButton(MaterialFrame_3);
        DelModelBtn->setObjectName(QString::fromUtf8("DelModelBtn"));

        horizontalLayout_3->addWidget(DelModelBtn);


        verticalLayout_19->addWidget(MaterialFrame_3);


        horizontalLayout_13->addWidget(frame_7);

        tabWidget_2->addTab(TransformTab_2, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_16 = new QHBoxLayout(tab_2);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        frame_10 = new QFrame(tab_2);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        verticalLayout_22 = new QVBoxLayout(frame_10);
        verticalLayout_22->setSpacing(0);
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        verticalLayout_22->setContentsMargins(0, 0, 0, 0);
        frame_11 = new QFrame(frame_10);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        verticalLayout_23 = new QVBoxLayout(frame_11);
        verticalLayout_23->setObjectName(QString::fromUtf8("verticalLayout_23"));
        label_28 = new QLabel(frame_11);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        verticalLayout_23->addWidget(label_28);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_29 = new QLabel(frame_11);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        horizontalLayout_17->addWidget(label_29);

        AngleCameraDSB = new QDoubleSpinBox(frame_11);
        AngleCameraDSB->setObjectName(QString::fromUtf8("AngleCameraDSB"));
        AngleCameraDSB->setFont(font);
        AngleCameraDSB->setFrame(true);
        AngleCameraDSB->setDecimals(1);
        AngleCameraDSB->setMinimum(1.000000000000000);
        AngleCameraDSB->setMaximum(10000.000000000000000);
        AngleCameraDSB->setSingleStep(10.000000000000000);
        AngleCameraDSB->setValue(30.000000000000000);

        horizontalLayout_17->addWidget(AngleCameraDSB);


        verticalLayout_23->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        LeftCameraBtn = new QPushButton(frame_11);
        LeftCameraBtn->setObjectName(QString::fromUtf8("LeftCameraBtn"));

        horizontalLayout_18->addWidget(LeftCameraBtn);

        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setObjectName(QString::fromUtf8("verticalLayout_24"));
        UpCameraBtn = new QPushButton(frame_11);
        UpCameraBtn->setObjectName(QString::fromUtf8("UpCameraBtn"));

        verticalLayout_24->addWidget(UpCameraBtn);

        DownCameraBtn = new QPushButton(frame_11);
        DownCameraBtn->setObjectName(QString::fromUtf8("DownCameraBtn"));

        verticalLayout_24->addWidget(DownCameraBtn);


        horizontalLayout_18->addLayout(verticalLayout_24);

        RightCameraBtn = new QPushButton(frame_11);
        RightCameraBtn->setObjectName(QString::fromUtf8("RightCameraBtn"));

        horizontalLayout_18->addWidget(RightCameraBtn);


        verticalLayout_23->addLayout(horizontalLayout_18);


        verticalLayout_22->addWidget(frame_11);

        frame_12 = new QFrame(frame_10);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        verticalLayout_25 = new QVBoxLayout(frame_12);
        verticalLayout_25->setObjectName(QString::fromUtf8("verticalLayout_25"));
        label_30 = new QLabel(frame_12);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        verticalLayout_25->addWidget(label_30);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_31 = new QLabel(frame_12);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        horizontalLayout_19->addWidget(label_31);

        MoveCameraDSP = new QSpinBox(frame_12);
        MoveCameraDSP->setObjectName(QString::fromUtf8("MoveCameraDSP"));
        MoveCameraDSP->setFont(font);
        MoveCameraDSP->setFrame(true);
        MoveCameraDSP->setMinimum(1);
        MoveCameraDSP->setMaximum(1000);
        MoveCameraDSP->setSingleStep(10);
        MoveCameraDSP->setValue(20);

        horizontalLayout_19->addWidget(MoveCameraDSP);


        verticalLayout_25->addLayout(horizontalLayout_19);

        ZoomCameraBtn = new QPushButton(frame_12);
        ZoomCameraBtn->setObjectName(QString::fromUtf8("ZoomCameraBtn"));

        verticalLayout_25->addWidget(ZoomCameraBtn);

        MoveAwayCameraBtn = new QPushButton(frame_12);
        MoveAwayCameraBtn->setObjectName(QString::fromUtf8("MoveAwayCameraBtn"));

        verticalLayout_25->addWidget(MoveAwayCameraBtn);


        verticalLayout_22->addWidget(frame_12);


        horizontalLayout_16->addWidget(frame_10);

        tabWidget_2->addTab(tab_2, QString());

        verticalLayout_15->addWidget(tabWidget_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_33 = new QLabel(widget_4);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        horizontalLayout_2->addWidget(label_33);

        PairMaterialLabel = new QLabel(widget_4);
        PairMaterialLabel->setObjectName(QString::fromUtf8("PairMaterialLabel"));

        horizontalLayout_2->addWidget(PairMaterialLabel);


        verticalLayout_15->addLayout(horizontalLayout_2);

        label_32 = new QLabel(widget_4);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        verticalLayout_15->addWidget(label_32);

        TableWidget = new QTableWidget(widget_4);
        TableWidget->setObjectName(QString::fromUtf8("TableWidget"));
        TableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        TableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        TableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        TableWidget->horizontalHeader()->setStretchLastSection(true);
        TableWidget->verticalHeader()->setVisible(false);
        TableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout_15->addWidget(TableWidget);

        drawBtn = new QPushButton(widget_4);
        drawBtn->setObjectName(QString::fromUtf8("drawBtn"));

        verticalLayout_15->addWidget(drawBtn);


        gridLayout->addWidget(widget_4, 0, 1, 1, 1);

        layoutForGraphicsView = new QVBoxLayout();
        layoutForGraphicsView->setObjectName(QString::fromUtf8("layoutForGraphicsView"));

        gridLayout->addLayout(layoutForGraphicsView, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 627, 22));
        exitMenu = new QMenu(menubar);
        exitMenu->setObjectName(QString::fromUtf8("exitMenu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(exitMenu->menuAction());

        retranslateUi(MainWindow);

        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \321\204\320\270\320\263\321\203\321\200\321\213", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\267\320\270\321\206\320\270\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\276\321\200\320\276\320\275\320\260", nullptr));
        loadModelBtn->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \321\206\320\262\320\265\321\202\320\276\320\262\320\276\320\263\320\276 \320\275\320\260\320\261\320\276\321\200\320\260", nullptr));
        ChangeMaterialBtn->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202\320\265\321\200\320\270\320\260\320\273 \321\210\320\260\321\205\320\274\320\260\321\202\320\275\320\276\320\271 \320\264\320\276\321\201\320\272\320\270", nullptr));
        GlossyRadioBtn->setText(QCoreApplication::translate("MainWindow", "\320\223\320\273\321\217\320\275\321\206\320\265\320\262\321\213\320\271", nullptr));
        MatteRadioBtn->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202\320\276\320\262\321\213\320\271", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(CreateTab_2), QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "\320\244\320\270\320\263\321\203\321\200\320\260", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "id=", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260 \320\277\320\276\320\267\320\270\321\206\320\270\321\216", nullptr));
        MoveModelBtn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\201\321\202\320\270\321\202\321\214", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\262\321\200\320\260\321\211\320\265\320\275\320\270\321\217 (\320\263\321\200\320\260\320\264\321\203\321\201\321\213)", nullptr));
        RotateModelBtn->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\260\321\202\321\214", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265", nullptr));
        DelModelBtn->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(TransformTab_2), QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\262\321\200\320\260\321\211\320\265\320\275\320\270\321\217 (\320\263\321\200\320\260\320\264\321\203\321\201\321\213)", nullptr));
        LeftCameraBtn->setText(QCoreApplication::translate("MainWindow", "\320\222\320\273\320\265\320\262\320\276", nullptr));
        UpCameraBtn->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\321\200\321\205", nullptr));
        DownCameraBtn->setText(QCoreApplication::translate("MainWindow", "\320\222\320\275\320\270\320\267", nullptr));
        RightCameraBtn->setText(QCoreApplication::translate("MainWindow", "\320\222\320\277\321\200\320\260\320\262\320\276", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "dx:", nullptr));
        ZoomCameraBtn->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\261\320\273\320\270\320\267\320\270\321\202\321\214", nullptr));
        MoveAwayCameraBtn->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\320\232\320\260\320\274\320\265\321\200\320\260", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202\320\276\320\262\320\276\320\271 \320\275\320\260\320\261\320\276\321\200:", nullptr));
        PairMaterialLabel->setText(QString());
        label_32->setText(QCoreApplication::translate("MainWindow", "\320\244\320\270\320\263\321\203\321\200\321\213 \320\275\320\260 \321\201\321\206\320\265\320\275\320\265", nullptr));
        drawBtn->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214", nullptr));
        exitMenu->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
