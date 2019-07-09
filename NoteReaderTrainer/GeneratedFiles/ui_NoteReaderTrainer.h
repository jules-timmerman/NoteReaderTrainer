/********************************************************************************
** Form generated from reading UI file 'NoteReaderTrainer.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEREADERTRAINER_H
#define UI_NOTEREADERTRAINER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoteReaderTrainerClass
{
public:

    void setupUi(QWidget *NoteReaderTrainerClass)
    {
        if (NoteReaderTrainerClass->objectName().isEmpty())
            NoteReaderTrainerClass->setObjectName(QString::fromUtf8("NoteReaderTrainerClass"));
        NoteReaderTrainerClass->resize(600, 400);

        retranslateUi(NoteReaderTrainerClass);

        QMetaObject::connectSlotsByName(NoteReaderTrainerClass);
    } // setupUi

    void retranslateUi(QWidget *NoteReaderTrainerClass)
    {
        NoteReaderTrainerClass->setWindowTitle(QCoreApplication::translate("NoteReaderTrainerClass", "NoteReaderTrainer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoteReaderTrainerClass: public Ui_NoteReaderTrainerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEREADERTRAINER_H
