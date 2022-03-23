#include "ADatabaseOperations.h"

void ADatabaseOperations::setupUi(QDialog *qdModifyScreen)
{
    if (qdModifyScreen->objectName().isEmpty())
        qdModifyScreen->setObjectName(QString::fromUtf8("qdModifyScreen"));
    qdModifyScreen->resize(718, 490);
    groupBox_3 = new QGroupBox(qdModifyScreen);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    groupBox_3->setGeometry(QRect(10, 440, 701, 31));
    widget = new QWidget(groupBox_3);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(0, 0, 691, 31));
    horizontalLayout = new QHBoxLayout(widget);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalLayout->setContentsMargins(0, 0, 0, 0);
    qpbInsert = new QPushButton(widget);
    qpbInsert->setObjectName(QString::fromUtf8("qpbInsert"));

    horizontalLayout->addWidget(qpbInsert);

    qpbUpdate = new QPushButton(widget);
    qpbUpdate->setObjectName(QString::fromUtf8("qpbUpdate"));

    horizontalLayout->addWidget(qpbUpdate);

    qpbDelete = new QPushButton(widget);
    qpbDelete->setObjectName(QString::fromUtf8("qpbDelete"));

    horizontalLayout->addWidget(qpbDelete);

    groupBox_4 = new QGroupBox(qdModifyScreen);
    groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
    groupBox_4->setGeometry(QRect(10, 340, 691, 81));
    widget1 = new QWidget(groupBox_4);
    widget1->setObjectName(QString::fromUtf8("widget1"));
    widget1->setGeometry(QRect(0, 10, 691, 71));
    horizontalLayout_2 = new QHBoxLayout(widget1);
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
    groupBox = new QGroupBox(widget1);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    qlNameResult = new QLabel(groupBox);
    qlNameResult->setObjectName(QString::fromUtf8("qlNameResult"));
    qlNameResult->setGeometry(QRect(10, 0, 101, 16));
    QFont font;
    font.setPointSize(10);
    qlNameResult->setFont(font);
    qleNameResult = new QLineEdit(groupBox);
    qleNameResult->setObjectName(QString::fromUtf8("qleNameResult"));
    qleNameResult->setGeometry(QRect(10, 20, 210, 30));

    horizontalLayout_2->addWidget(groupBox);

    groupBox_2 = new QGroupBox(widget1);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    qlSurname = new QLabel(groupBox_2);
    qlSurname->setObjectName(QString::fromUtf8("qlSurname"));
    qlSurname->setGeometry(QRect(10, 0, 101, 16));
    qlSurname->setFont(font);
    qleSurname = new QLineEdit(groupBox_2);
    qleSurname->setObjectName(QString::fromUtf8("qleSurname"));
    qleSurname->setGeometry(QRect(10, 20, 210, 30));

    horizontalLayout_2->addWidget(groupBox_2);

    groupBox_5 = new QGroupBox(qdModifyScreen);
    groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
    groupBox_5->setGeometry(QRect(10, 10, 691, 331));
    verticalLayout_2 = new QVBoxLayout(groupBox_5);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    qtvListSTR = new QTableView(groupBox_5);
    qtvListSTR->setObjectName(QString::fromUtf8("qtvListSTR"));

    verticalLayout_2->addWidget(qtvListSTR);

    widget2 = new QWidget(qdModifyScreen);
    widget2->setObjectName(QString::fromUtf8("widget2"));
    widget2->setGeometry(QRect(0, 0, 2, 2));
    verticalLayout = new QVBoxLayout(widget2);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    retranslateUi(qdModifyScreen);

    QMetaObject::connectSlotsByName(qdModifyScreen);
} // setupUi

void ADatabaseOperations::retranslateUi(QDialog *qdModifyScreen)
{
    qdModifyScreen->setWindowTitle(QCoreApplication::translate("qdModifyScreen", "Dialog", nullptr));
    groupBox_3->setTitle(QString());
    qpbInsert->setText(QCoreApplication::translate("qdModifyScreen", "Insert", nullptr));
    qpbUpdate->setText(QCoreApplication::translate("qdModifyScreen", "Update", nullptr));
    qpbDelete->setText(QCoreApplication::translate("qdModifyScreen", "Delete", nullptr));
    groupBox_4->setTitle(QString());
    groupBox->setTitle(QString());
    qlNameResult->setText(QCoreApplication::translate("qdModifyScreen", "TextLabel", nullptr));
    groupBox_2->setTitle(QString());
    qlSurname->setText(QCoreApplication::translate("qdModifyScreen", "TextLabel", nullptr));
    groupBox_5->setTitle(QString());
} // retranslateUi

void ADatabaseOperations::setupUIElementContents()
{
}

void ADatabaseOperations::setupUISignals()
{
    connect(qpbInsert, &QPushButton::clicked, this, &ADatabaseOperations::insertBtn_Clicked);
    connect(qpbDelete, &QPushButton::clicked, this, &ADatabaseOperations::deleteBtn_Clicked);
    connect(qpbUpdate, &QPushButton::clicked, this, &ADatabaseOperations::updateBtn_Clicked);
}

void ADatabaseOperations::updateBtn_Clicked()
{
    //"UPDATE employee SET salary = 70000 WHERE id = 1003"

    int index = qtvListSTR->selectionModel()->currentIndex().row();
    qlonglong qllSelectedItem = qtvListSTR->model()->index(index, 0).data().toLongLong();

    if (objName == "qaStudent")
    {
        QSqlQuery query;
        query.exec(QString("UPDATE tblStudent SET name = '%1', surname = '%2' WHERE student_id = %3").arg(qleNameResult->text(), qleSurname->text(), QString::number(qllSelectedItem)));

        qsqmStudentTableView->setQuery("SELECT * FROM [tblStudent]", qsdDatabase);
        qtvListSTR->setModel(qsqmStudentTableView);
    }
    else if (objName == "qaTeacher")
    {
        QSqlQuery query;
        query.exec(QString("UPDATE tblTeacher SET name = '%1', surname = '%2' WHERE teacher_id = %3").arg(qleNameResult->text(), qleSurname->text(), QString::number(qllSelectedItem)));

        qsqmTeacherTableView->setQuery("SELECT * FROM [tblTeacher]", qsdDatabase);
        qtvListSTR->setModel(qsqmTeacherTableView);
    }
    else if (objName == "qaResult")
    {
        QSqlQuery query;
        query.exec(QString("UPDATE tblResult SET result = '%1' WHERE result_id = %3").arg(qleNameResult->text(), QString::number(qllSelectedItem)));

        qsqmResultTableView->setQuery("SELECT * FROM [tblResult]", qsdDatabase);
        qtvListSTR->setModel(qsqmResultTableView);
    }
}

void ADatabaseOperations::deleteBtn_Clicked()
{
    int index = qtvListSTR->selectionModel()->currentIndex().row();

    qlonglong qllSelectedItem = qtvListSTR->model()->index(index, 0).data().toLongLong();

    if (objName == "qaStudent")
    {
        QSqlQuery query;
        query.exec(QString("DELETE FROM tblStudent WHERE student_id = '%1'").arg(qllSelectedItem));

        qsqmStudentTableView->setQuery("SELECT * FROM [tblStudent]", qsdDatabase);
        qtvListSTR->setModel(qsqmStudentTableView);
    }
    else if (objName == "qaTeacher")
    {
        QSqlQuery query;
        query.exec(QString("DELETE FROM tblTeacher WHERE teacher_id = '%1'").arg(qllSelectedItem));

        qsqmTeacherTableView->setQuery("SELECT * FROM [tblTeacher]", qsdDatabase);
        qtvListSTR->setModel(qsqmTeacherTableView);
    }
    else if (objName == "qaResult")
    {
        QSqlQuery query;
        query.exec(QString("DELETE FROM tblResult WHERE result_id = '%1'").arg(qllSelectedItem));

        qsqmResultTableView->setQuery("SELECT * FROM [tblResult]", qsdDatabase);
        qtvListSTR->setModel(qsqmResultTableView);
    }
}

void ADatabaseOperations::insertBtn_Clicked()
{

    if (objName == "qaStudent")
    {
        if (qleNameResult->text() == "" || qleSurname->text() == "")
        {
            QMessageBox msgBox;
            msgBox.setText("Please fill all fields.");
            msgBox.exec();
        }
        else
        {
            QSqlQuery query;
            query.exec(QString("INSERT INTO tblStudent(name, surname) VALUES ('%1', '%2')").arg(qleNameResult->text(), qleSurname->text()));

            qsqmStudentTableView->setQuery("SELECT * FROM [tblStudent]", qsdDatabase);
            qtvListSTR->setModel(qsqmStudentTableView);
        }
    }
    else if (objName == "qaTeacher")
    {
        if (qleNameResult->text() == "" || qleSurname->text() == "")
        {
            QMessageBox msgBox;
            msgBox.setText("Please fill all fields.");
            msgBox.exec();
        }
        else
        {
            QSqlQuery query;
            query.exec(QString("INSERT INTO tblTeacher(name, surname) VALUES ('%1', '%2')").arg(qleNameResult->text(), qleSurname->text()));

            qsqmTeacherTableView->setQuery("SELECT * FROM [tblTeacher]", qsdDatabase);
            qtvListSTR->setModel(qsqmTeacherTableView);
        }
    }
    else if (objName == "qaResult")
    {
        if (qleNameResult->text() == "")
        {
            QMessageBox msgBox;
            msgBox.setText("Please fill all fields.");
            msgBox.exec();
        }
        else
        {
            QSqlQuery query;
            query.exec(QString("INSERT INTO tblResult(result) VALUES ('%1')").arg(qleNameResult->text()));

            qsqmResultTableView->setQuery("SELECT * FROM [tblResult]", qsdDatabase);
            qtvListSTR->setModel(qsqmResultTableView);
        }
    }
}

ADatabaseOperations::ADatabaseOperations(QString objectName)
{
    objName = objectName;
    this->setupUi(this);
    this->setupUIElementContents();
    this->setupUISignals();

    qsdDatabase = QSqlDatabase::addDatabase("QSQLITE");
    qsdDatabase.setDatabaseName(QString("%1%2%3%4%5").arg(QApplication::applicationDirPath(), QDir::separator(), "..", QDir::separator(), "assessment.db"));

    qsqmStudentTableView = new QSqlQueryModel(this);
    qsqmTeacherTableView = new QSqlQueryModel(this);
    qsqmResultTableView = new QSqlQueryModel(this);

    if (!qsdDatabase.open())
    {
        qDebug() << "Error while opening database";
    }

    qsqmStudentTableView->setQuery("SELECT * FROM [tblStudent]", qsdDatabase);
    qsqmTeacherTableView->setQuery("SELECT * FROM [tblTeacher]", qsdDatabase);
    qsqmResultTableView->setQuery("SELECT * FROM [tblResult]", qsdDatabase);
    // qDebug() << objectName;
    if (objectName == "qaStudent")
    {
        qlNameResult->setText("Name");
        qlSurname->setText("Surname");
        groupBox_2->setVisible(true);
        qtvListSTR->setModel(qsqmStudentTableView);
    }
    else if (objectName == "qaTeacher")
    {
        qlNameResult->setText("Name");
        qlSurname->setText("Surname");
        groupBox_2->setVisible(true);
        qtvListSTR->setModel(qsqmTeacherTableView);
    }
    else if (objectName == "qaResult")
    {
        qlNameResult->setText("Result");
        groupBox_2->setVisible(false);
        qtvListSTR->setModel(qsqmResultTableView);
    }
}

ADatabaseOperations::~ADatabaseOperations()
{
}