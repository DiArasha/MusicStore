#include "formguitar.h"
#include "ui_formguitar.h"
#include "QMessageBox"
#include "guitar.h"
#include <QDate>
#include "CustomColorPlaceholderLineEdit.h"
#include <QKeyEvent>
#include <QWidget>
#include <QKeySequence>
#include "QDebug"
#include <QShortcut>
#include "guitarprint.h"

FormGuitar::FormGuitar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormGuitar)
{
    ui->setupUi(this);

    CreateObjects();

          QRegExp reg1("^[0-9][0-9][0-9][0-9]$");
                QValidator* validator1 = new QRegExpValidator(reg1);
                lineEdit_6->setValidator(validator1);

    pushButton_2->setEnabled(false);

connect(comboBox_2, &QComboBox::currentTextChanged,  this, &FormGuitar::on_comboBox_2_currentIndexChanged);
connect(lineEdit_4, &CustomColorPlaceholderLineEdit::textChanged, this, &FormGuitar::on_lineEdit_4_textChanged);
connect(spinBox_2, &QDoubleSpinBox::textChanged, this, &FormGuitar::on_spinBox_2_textChanged);
connect(comboBox_2, &QComboBox::textActivated, this, &FormGuitar::on_comboBox_2_activated);
connect(pushButton_2, &QPushButton::clicked, this, &FormGuitar::on_pushButton_2_clicked);

lineEdit_4->installEventFilter(this);
spinBox_2->installEventFilter(this);
comboBox_2->installEventFilter(this);
lineEdit_6->installEventFilter(this);
pushButton_2->installEventFilter(this);

}

FormGuitar::~FormGuitar()
{
    delete ui;
}

void FormGuitar::CreateObjects()
{
    layoutWidget = new QWidget(this);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(20, 0, 341, 281));
    verticalLayout_2 = new QVBoxLayout(layoutWidget);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    verticalLayout_2->setContentsMargins(0, 0, 0, 0);
    gridLayout_2 = new QGridLayout();
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    label_5 = new QLabel(layoutWidget);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setText(QString::fromUtf8("Наименование"));

    gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

    lineEdit_4 = new CustomColorPlaceholderLineEdit(layoutWidget);
    lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
    lineEdit_4 -> setCustomPlaceholderText("***");
    lineEdit_4 -> setCustomPlaceholderColor(QColor(Qt::red));

    gridLayout_2->addWidget(lineEdit_4, 0, 1, 1, 1);

    label_6 = new QLabel(layoutWidget);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setText(QString::fromUtf8("Цена"));

    gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

    spinBox_2 = new QDoubleSpinBox(layoutWidget);
    spinBox_2->setObjectName(QString::fromUtf8("lineEdit_5"));
    spinBox_2->setSpecialValueText( "***" );
        spinBox_2 -> setStyleSheet("QWidget{color:red;}");
        spinBox_2->setMaximum(20000);


    gridLayout_2->addWidget(spinBox_2, 1, 1, 1, 1);

    label_7 = new QLabel(layoutWidget);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setText(QString::fromUtf8("Материал корпуса"));

    gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

    comboBox_2 = new QComboBox(layoutWidget);
    comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
    comboBox_2->setStyleSheet("QWidget{color:red;}");
    comboBox_2->setPlaceholderText(QStringLiteral("***"));
    comboBox_2->addItem("Ольха");
    comboBox_2->addItem("Липа");
    comboBox_2->addItem("Агатис");
    for (size_t i = 0; i < comboBox_2->count(); i++)
            {
                comboBox_2->setItemData(i, QBrush(QColor(Qt::black)), Qt::ForegroundRole);
            }

    gridLayout_2->addWidget(comboBox_2, 2, 1, 1, 1);

    label_8 = new QLabel(layoutWidget);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    label_8->setText(QString::fromUtf8("Год выпуска"));

    gridLayout_2->addWidget(label_8, 3, 0, 1, 1);

    lineEdit_6 = new QLineEdit(layoutWidget);
    lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

    gridLayout_2->addWidget(lineEdit_6, 3, 1, 1, 1);


    verticalLayout_2->addLayout(gridLayout_2);

    pushButton_2 = new QPushButton(layoutWidget);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setText(QString::fromUtf8("Сохранить"));

    verticalLayout_2->addWidget(pushButton_2);
}

bool FormGuitar::SpinBoxFocus(QObject *target)
{
    bool flag = false;
    if (target == spinBox_2 && flag == false)
    {
        spinBox_2->setSpecialValueText( "" );
        spinBox_2->selectAll();
        spinBox_2->setStyleSheet("QWidget{color:black;}");
        flag = true;
     return true;
    }
}

bool FormGuitar::FocusSetUp(QObject *target, QEvent *event)
{
    listWid = {lineEdit_4, spinBox_2, comboBox_2};
    int Ind = 0;
    bool Est = 0;
    int NumList = 0;
    QKeyEvent *keyEvent = (QKeyEvent *)event;
    if ((QApplication::keyboardModifiers() & Qt::ShiftModifier)&&(keyEvent->key() == Qt::Key_Right))
    {
        if (target == lineEdit_6)
        {
            lineEdit_4->setFocus();
        }
        else
        {
            for ( Ind = 0; Ind < listWid.length(); Ind++)
            {
                if (target == listWid[Ind])
                {
                    Est = 1;
                    NumList = Ind;
                    break;
                }
            }
            if ((Est == 1)&&(NumList < listWid.length() - 1))
            {
                listWid[NumList+1]->setFocus();
            }
            if ((Est == 1)&&(NumList == listWid.length() - 1))
            {
                listWid[0]->setFocus();
            }
            if (Est == 0)
            {
                listWid[0]->setFocus();
            }
        }
        return true;
    }
    else if ((QApplication::keyboardModifiers() & Qt::ShiftModifier)&&(keyEvent->key() == Qt::Key_Left))
    {

            for ( Ind = 0; Ind < listWid.length(); Ind++)
            {
                if (target == listWid[Ind])
                {
                    Est = 1;
                    NumList = Ind;
                    break;
                }
            }
            if ((Est == 1)&&(NumList > 0))
            {
                listWid[NumList-1]->setFocus();
            }
            if ((Est == 1)&&(NumList == 0))
            {
                listWid[listWid.length() - 1]->setFocus();
            }
            if (Est == 0)
            {
                listWid[listWid.length() - 1]->setFocus();
            }
        return true;
    }
}


bool FormGuitar::eventFilter(QObject *target, QEvent *event)
{

        if (event != nullptr && event->type() == QEvent::KeyPress)
        {
            FocusSetUp(target, event);
        }

        if (event != nullptr && event->type() == QEvent::FocusIn)
        {
            SpinBoxFocus(target);
        }

return QWidget::eventFilter(target, event);
}


void focusInEvent(QFocusEvent *event)
{

}


void FormGuitar::ButtonActive()
{
    if ((lineEdit_4->text().isEmpty())||(spinBox_2->text().isEmpty())||(comboBox_2->currentText()=="***"))
    {
        pushButton_2->setEnabled(false);
    }
    else
    {
        pushButton_2->setEnabled(true);
    }
}


void FormGuitar::on_lineEdit_4_textChanged(const QString &arg1)
{
    ButtonActive();
}


void FormGuitar::on_spinBox_2_textChanged(const QString &arg1)
{
    if (spinBox_2->text().length() > 0 && spinBox_2->text()[0] == "0")
    {
         spinBox_2->text() = spinBox_2->text().remove(1,1);
    }
    spinBox_2->setStyleSheet("QWidget{color:black;}");

    ButtonActive();
}


void FormGuitar::PrintInfo()
{
    Guitar guitar;

    guitar.name = lineEdit_4->text();
    guitar.costStr = spinBox_2->text();
    guitar.material = comboBox_2->currentText();
    guitar.dateStr = lineEdit_6->text();
    guitar.date = guitar.dateStr.toInt();

    GuitarPrint guitarPrint;
    QString info = guitarPrint.Info(guitar);

    QMessageBox::information(this,"Сведения о гитаре",info);
    close();

}


void FormGuitar::on_pushButton_2_clicked()
{

    //proverka
    QDate cd = QDate::currentDate();
    int year = cd.year();
    QString YearStr = lineEdit_6->text();
    int YearInt = YearStr.toInt();
    if (((YearInt < 1900)||(YearInt > year))&&(!lineEdit_6->text().isEmpty()))
    {
        QMessageBox::information(this,"Ошибка","Год должен быть указан в промежутке 1900-н.в.");
        return;
    }
    PrintInfo();
}


void FormGuitar::on_comboBox_2_activated(const QString &arg1)
{
    ButtonActive();
}


void FormGuitar::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    ///qDebug() << "AAAAAAAAAA";
    comboBox_2->setStyleSheet("QWidget{color:black;}");
}
