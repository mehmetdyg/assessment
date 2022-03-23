#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMinimumSize(300, 300);
    this->setMaximumSize(550, 550);

    vBoxLayout = new QVBoxLayout();
    initializeGUI();

    connect(cb, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=](){

        switch(cb->currentIndex())
        {
        case 0:
            IdLabel->setText("Student ID");
            NameLabel->setVisible(true);
            SurnameLabel->setVisible(true);
            NameLabel->setText("Student Name");
            SurnameLabel->setText("Student Surname");
            result->setVisible(false);
            student_id->setVisible(false);
            teacher_id->setVisible(false);
            resultLabel->setVisible(false);
            student_idLabel->setVisible(false);
            teacher_idLabel->setVisible(false);
            nameLE->setVisible(true);
            surnameLE->setVisible((true));
            break;
        case 1:
            IdLabel->setText("Teacher ID");
            NameLabel->setVisible(true);
            SurnameLabel->setVisible(true);
            NameLabel->setText("Teacher Name");
            SurnameLabel->setText("Teacher Surname");
            result->setVisible(false);
            student_id->setVisible(false);
            teacher_id->setVisible(false);
            resultLabel->setVisible(false);
            student_idLabel->setVisible(false);
            teacher_idLabel->setVisible(false);
            nameLE->setVisible(true);
            surnameLE->setVisible((true));
            break;
        case 2:
            IdLabel->setText("Result ID");
            NameLabel->setVisible(false);
            SurnameLabel->setVisible(false);
            result->setVisible(true);
            student_id->setVisible(true);
            teacher_id->setVisible(true);
            resultLabel->setVisible(true);
            student_idLabel->setVisible(true);
            teacher_idLabel->setVisible(true);
            nameLE->setVisible(false);
            surnameLE->setVisible((false));
            break;
        }
    });



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeGUI()
{
    cb = new QComboBox();
    cb->addItem("Student");
    cb->addItem("Teacher");
    cb->addItem("Result");
    cb->setCurrentIndex(0);

    result = new QLineEdit("");
    teacher_id = new QLineEdit("");
    student_id = new QLineEdit("");

    IdLabel = new QLabel("Student ID");
    NameLabel = new QLabel("Student Name");
    SurnameLabel = new QLabel("Student Surname");
    resultLabel = new QLabel("Result");
    teacher_idLabel = new QLabel("Teacher ID");
    student_idLabel = new QLabel("Student ID");

    result->setVisible(false);
    student_id->setVisible(false);
    teacher_id->setVisible(false);
    resultLabel->setVisible(false);
    student_idLabel->setVisible(false);
    teacher_idLabel->setVisible(false);


    idLE = new QLineEdit();
    nameLE = new QLineEdit();
    surnameLE = new QLineEdit();
    QPushButton *pB = new QPushButton("Add");

    vBoxLayout->addWidget(cb);
    vBoxLayout->addWidget(IdLabel);
    vBoxLayout->addWidget(idLE);
    vBoxLayout->addWidget(NameLabel);
    vBoxLayout->addWidget(nameLE);
    vBoxLayout->addWidget(SurnameLabel);
    vBoxLayout->addWidget(surnameLE);
    vBoxLayout->addWidget(resultLabel);
    vBoxLayout->addWidget(result);
    vBoxLayout->addWidget(student_idLabel);
    vBoxLayout->addWidget(student_id);
    vBoxLayout->addWidget(teacher_idLabel);
    vBoxLayout->addWidget(teacher_id);

    vBoxLayout->addWidget(pB);

    connect(pB, &QPushButton::clicked, this, [=](){
        //TODO DB Insert
    });


    ui->insertTab->setLayout(vBoxLayout);
}

