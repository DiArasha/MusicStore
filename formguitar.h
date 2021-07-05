#ifndef FORMGUITAR_H
#define FORMGUITAR_H

#include <QWidget>
#include "CustomColorPlaceholderLineEdit.h"
#include "CustomColorPlaceholderComboBox.h"


#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace Ui {
class FormGuitar;
}

class FormGuitar : public QWidget
{
    Q_OBJECT

public:
    explicit FormGuitar(QWidget *parent = nullptr);

    void CreateObjects();

    ~FormGuitar();

protected:

        bool eventFilter(QObject *target, QEvent *event);

public slots:
    void on_spinBox_2_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void PrintInfo();

    bool FocusSetUp(QObject *target, QEvent *event);

    bool SpinBoxFocus(QObject *target);

//    void keyPressEvent(QKeyEvent *event1);

//    void keyPressEvent2(QKeyEvent *event2);

//    void slotShortcutShiftRight();


private:
    Ui::FormGuitar *ui;
//    QShortcut       *keyShiftRight;

    //CustomColorPlaceholderLineEdit *lineEdit_4;

void ButtonActive();

    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    CustomColorPlaceholderLineEdit *lineEdit_4;
    QLabel *label_6;
        QDoubleSpinBox *spinBox_2;
//    CustomColorPlaceholderLineEdit *lineEdit_5;
    QLabel *label_7;
    QComboBox *comboBox_2;
    QLabel *label_8;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_2;

    QList<QWidget *> listWid;


};

#endif // FORMGUITAR_H
