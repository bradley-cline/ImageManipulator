/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *ImageBrowser;
    QLineEdit *lblImageFile;
    QPushButton *btnBrowse;
    QFrame *line_3;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *lblOriginalImage;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *lblProcessedImage;
    QHBoxLayout *ActionButtons;
    QPushButton *btnFlip;
    QPushButton *btnGreyscale;
    QPushButton *btnAverage;
    QFrame *line;
    QPushButton *btnReset;
    QPushButton *btnProcess;
    QFrame *line_2;
    QHBoxLayout *Average;
    QLabel *lblAverageLabel;
    QLabel *lblAverage;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *CommandHistory;
    QLabel *lblLastCommandLabel;
    QLabel *lblLastCommand;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(761, 440);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ImageBrowser = new QHBoxLayout();
        ImageBrowser->setObjectName(QString::fromUtf8("ImageBrowser"));
        lblImageFile = new QLineEdit(centralwidget);
        lblImageFile->setObjectName(QString::fromUtf8("lblImageFile"));
        lblImageFile->setReadOnly(true);

        ImageBrowser->addWidget(lblImageFile);

        btnBrowse = new QPushButton(centralwidget);
        btnBrowse->setObjectName(QString::fromUtf8("btnBrowse"));

        ImageBrowser->addWidget(btnBrowse);


        verticalLayout_2->addLayout(ImageBrowser);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(0, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lblOriginalImage = new QLabel(frame);
        lblOriginalImage->setObjectName(QString::fromUtf8("lblOriginalImage"));
        lblOriginalImage->setMinimumSize(QSize(350, 235));
        lblOriginalImage->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblOriginalImage);


        gridLayout->addWidget(frame, 1, 0, 1, 1);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lblProcessedImage = new QLabel(frame_2);
        lblProcessedImage->setObjectName(QString::fromUtf8("lblProcessedImage"));
        lblProcessedImage->setMinimumSize(QSize(350, 235));
        lblProcessedImage->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lblProcessedImage);


        gridLayout->addWidget(frame_2, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        ActionButtons = new QHBoxLayout();
        ActionButtons->setObjectName(QString::fromUtf8("ActionButtons"));
        btnFlip = new QPushButton(centralwidget);
        btnFlip->setObjectName(QString::fromUtf8("btnFlip"));
        btnFlip->setEnabled(false);

        ActionButtons->addWidget(btnFlip);

        btnGreyscale = new QPushButton(centralwidget);
        btnGreyscale->setObjectName(QString::fromUtf8("btnGreyscale"));
        btnGreyscale->setEnabled(false);

        ActionButtons->addWidget(btnGreyscale);

        btnAverage = new QPushButton(centralwidget);
        btnAverage->setObjectName(QString::fromUtf8("btnAverage"));
        btnAverage->setEnabled(false);

        ActionButtons->addWidget(btnAverage);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        ActionButtons->addWidget(line);

        btnReset = new QPushButton(centralwidget);
        btnReset->setObjectName(QString::fromUtf8("btnReset"));
        btnReset->setEnabled(false);

        ActionButtons->addWidget(btnReset);

        btnProcess = new QPushButton(centralwidget);
        btnProcess->setObjectName(QString::fromUtf8("btnProcess"));
        btnProcess->setEnabled(false);

        ActionButtons->addWidget(btnProcess);


        verticalLayout_2->addLayout(ActionButtons);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        Average = new QHBoxLayout();
        Average->setObjectName(QString::fromUtf8("Average"));
        lblAverageLabel = new QLabel(centralwidget);
        lblAverageLabel->setObjectName(QString::fromUtf8("lblAverageLabel"));
        QFont font;
        font.setBold(false);
        lblAverageLabel->setFont(font);

        Average->addWidget(lblAverageLabel);

        lblAverage = new QLabel(centralwidget);
        lblAverage->setObjectName(QString::fromUtf8("lblAverage"));
        lblAverage->setEnabled(false);

        Average->addWidget(lblAverage);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Average->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(Average);

        CommandHistory = new QHBoxLayout();
        CommandHistory->setObjectName(QString::fromUtf8("CommandHistory"));
        lblLastCommandLabel = new QLabel(centralwidget);
        lblLastCommandLabel->setObjectName(QString::fromUtf8("lblLastCommandLabel"));

        CommandHistory->addWidget(lblLastCommandLabel);

        lblLastCommand = new QLabel(centralwidget);
        lblLastCommand->setObjectName(QString::fromUtf8("lblLastCommand"));

        CommandHistory->addWidget(lblLastCommand);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        CommandHistory->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(CommandHistory);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lblImageFile->setPlaceholderText(QCoreApplication::translate("MainWindow", "Browse for an image file to manipulate", nullptr));
        btnBrowse->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Processed Image", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Original Image", nullptr));
        lblOriginalImage->setText(QString());
        lblProcessedImage->setText(QString());
        btnFlip->setText(QCoreApplication::translate("MainWindow", "Flip Vertically", nullptr));
        btnGreyscale->setText(QCoreApplication::translate("MainWindow", "To Greyscale", nullptr));
        btnAverage->setText(QCoreApplication::translate("MainWindow", "Average Pixels", nullptr));
        btnReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        btnProcess->setText(QCoreApplication::translate("MainWindow", "Process Image", nullptr));
        lblAverageLabel->setText(QCoreApplication::translate("MainWindow", "Pixel Average:", nullptr));
        lblAverage->setText(QCoreApplication::translate("MainWindow", "Not calculated yet", nullptr));
        lblLastCommandLabel->setText(QCoreApplication::translate("MainWindow", "Last Command:", nullptr));
        lblLastCommand->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
