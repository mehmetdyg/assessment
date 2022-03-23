#include <QtGui>
#include <QApplication>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QListView>
#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "ADatabaseOperations.h"

class AMain : public QWidget
{
public:
    QAction *qaStudent;
    QAction *qaTeacher;
    QAction *qaResult;
    QWidget *qwtMain;
    QVBoxLayout *verticalLayout;
    QSplitter *qstMain;
    QGroupBox *qgbTeacher;
    QLabel *qlTeacher;
    QSplitter *splitter;
    QComboBox *qcbTeacher;
    QGroupBox *qgbResult;
    QLabel *qlStudent;
    QLabel *qlResults;
    QWidget *widget;
    QHBoxLayout *qhlResult;
    QTableView *qtvStudents;
    QTableView *qtvResults;
    QMenuBar *qmbMenu;
    QMenu *qmMenu;

    QSqlDatabase qsdDatabase;

    QSqlQueryModel *qsqmTeacherComboBox;
    QSqlQueryModel *qsqmStudentTableView;
    QSqlQueryModel *qsqmResultTableView;

    QString objName = "";

    void setupUi(QMainWindow *qmwMain)
    {
        if (qmwMain->objectName().isEmpty())
            qmwMain->setObjectName(QString::fromUtf8("qmwMain"));
        qmwMain->resize(721, 721);
        qaStudent = new QAction(qmwMain);
        qaStudent->setObjectName(QString::fromUtf8("qaStudent"));
        qaTeacher = new QAction(qmwMain);
        qaTeacher->setObjectName(QString::fromUtf8("qaTeacher"));
        qaResult = new QAction(qmwMain);
        qaResult->setObjectName(QString::fromUtf8("qaResult"));
        qwtMain = new QWidget(qmwMain);
        qwtMain->setObjectName(QString::fromUtf8("qwtMain"));
        verticalLayout = new QVBoxLayout(qwtMain);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        qstMain = new QSplitter(qwtMain);
        qstMain->setObjectName(QString::fromUtf8("qstMain"));
        qstMain->setOrientation(Qt::Vertical);
        qgbTeacher = new QGroupBox(qstMain);
        qgbTeacher->setObjectName(QString::fromUtf8("qgbTeacher"));
        qgbTeacher->setMaximumSize(QSize(16777215, 200));
        qlTeacher = new QLabel(qgbTeacher);
        qlTeacher->setObjectName(QString::fromUtf8("qlTeacher"));
        qlTeacher->setGeometry(QRect(10, 10, 251, 16));
        QFont font;
        font.setPointSize(10);
        qlTeacher->setFont(font);
        splitter = new QSplitter(qgbTeacher);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(10, 40, 530, 58));
        splitter->setOrientation(Qt::Horizontal);
        qcbTeacher = new QComboBox(splitter);
        qcbTeacher->setObjectName(QString::fromUtf8("qcbTeacher"));
        QFont font1;
        font1.setPointSize(16);
        qcbTeacher->setFont(font1);
        splitter->addWidget(qcbTeacher);
        qstMain->addWidget(qgbTeacher);
        qgbResult = new QGroupBox(qstMain);
        qgbResult->setObjectName(QString::fromUtf8("qgbResult"));
        qlStudent = new QLabel(qgbResult);
        qlStudent->setObjectName(QString::fromUtf8("qlStudent"));
        qlStudent->setGeometry(QRect(10, 20, 251, 16));
        qlStudent->setFont(font);
        qlResults = new QLabel(qgbResult);
        qlResults->setObjectName(QString::fromUtf8("qlResults"));
        qlResults->setGeometry(QRect(360, 20, 251, 16));
        qlResults->setFont(font);
        widget = new QWidget(qgbResult);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 50, 681, 481));
        qhlResult = new QHBoxLayout(widget);
        qhlResult->setObjectName(QString::fromUtf8("qhlResult"));
        qhlResult->setContentsMargins(0, 0, 0, 0);
        qtvStudents = new QTableView(widget);
        qtvStudents->setObjectName(QString::fromUtf8("qtvStudents"));

        qhlResult->addWidget(qtvStudents);

        qtvResults = new QTableView(widget);
        qtvResults->setObjectName(QString::fromUtf8("qtvResults"));

        qhlResult->addWidget(qtvResults);

        qstMain->addWidget(qgbResult);

        verticalLayout->addWidget(qstMain);

        qmwMain->setCentralWidget(qwtMain);
        qmbMenu = new QMenuBar(qmwMain);
        qmbMenu->setObjectName(QString::fromUtf8("qmbMenu"));
        qmbMenu->setGeometry(QRect(0, 0, 721, 26));
        qmMenu = new QMenu(qmbMenu);
        qmMenu->setObjectName(QString::fromUtf8("qmMenu"));
        qmwMain->setMenuBar(qmbMenu);

        qmbMenu->addAction(qmMenu->menuAction());
        qmMenu->addAction(qaStudent);
        qmMenu->addAction(qaTeacher);
        qmMenu->addAction(qaResult);

        retranslateUi(qmwMain);

        QMetaObject::connectSlotsByName(qmwMain);
    } // setupUi

    void retranslateUi(QMainWindow *qmwMain)
    {
        qmwMain->setWindowTitle(QCoreApplication::translate("qmwMain", "MainWindow", nullptr));
        qaStudent->setText(QCoreApplication::translate("qmwMain", "Student", nullptr));
        qaTeacher->setText(QCoreApplication::translate("qmwMain", "Teacher", nullptr));
        qaResult->setText(QCoreApplication::translate("qmwMain", "Result", nullptr));
        qgbTeacher->setTitle(QString());
        qlTeacher->setText(QCoreApplication::translate("qmwMain", "Selected Teacher", nullptr));
        qgbResult->setTitle(QString());
        qlStudent->setText(QCoreApplication::translate("qmwMain", "Students", nullptr));
        qlResults->setText(QCoreApplication::translate("qmwMain", "Results", nullptr));
        qmMenu->setTitle(QCoreApplication::translate("qmwMain", "File", nullptr));
    } // retranslateUi

    void setupUIElementContents()
    {
    }

    void qcbTeacher_ItemChanged(int index)
    {
        qDebug() << "item changed";
        qlonglong qllTeacherID = qcbTeacher->model()->index(index, 0).data().toLongLong();
        qsqmStudentTableView->setQuery(QString(
                                           "SELECT     [tblStudent].[student_id], [name], [surname] "
                                           "FROM       [tblStudent] "
                                           "INNER JOIN [tblStudentTeacherRelation] ON [tblStudentTeacherRelation].[student_id] = [tblStudent].[student_id] "
                                           "WHERE      [tblStudentTeacherRelation].[teacher_id] = %1 ")
                                           .arg(qllTeacherID),
                                       qsdDatabase);
        qtvStudents->setModel(qsqmStudentTableView);
        qtvStudents->hideColumn(0);
    }

    void qtvStudents_clicked(QModelIndex index)
    {
        qlonglong qllStudentID = qtvStudents->model()->index(index.row(), 0).data().toLongLong();
        // qlonglong qllTeacherID = qcbTeacher->model()->index(qcbTeacher->currentIndex(), 0).data().toLongLong();
        qsqmResultTableView->setQuery(QString(
                                          "SELECT     [tblResult].[result] "
                                          "FROM       [tblResult] "
                                          "INNER JOIN [tblStudent] ON [tblStudent].[student_id] = [tblResult].[student_id] "
                                          "INNER JOIN [tblTeacher] ON [tblTeacher].[teacher_id] = [tblResult].[teacher_id] "
                                          "WHERE      [tblStudent].[student_id] = %1 "
                                          "--AND        [tblTeacher].[teacher_id] = %2 ") // TODO
                                          .arg(qllStudentID),
                                      qsdDatabase);
        qtvResults->setModel(qsqmResultTableView);
    }

    void setupUISignals()
    {
        connect(this->qtvStudents, &QTableView::clicked, this, &AMain::qtvStudents_clicked);
        connect(this->qcbTeacher, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &AMain::qcbTeacher_ItemChanged);

        connect(qaStudent, &QAction::triggered, this, [=]()
                {
            objName = qaStudent->objectName();
            openDatabaseDialog(); });

        connect(qaTeacher, &QAction::triggered, this, [=]()
                {
            objName = qaTeacher->objectName();
            openDatabaseDialog(); });

        connect(qaResult, &QAction::triggered, this, [=]()
                {
            objName = qaResult->objectName();
            openDatabaseDialog(); });
    }

    void openDatabaseDialog()
    {
        ADatabaseOperations *ado = new ADatabaseOperations(objName);
        ado->exec();
    }

public:
    AMain(QMainWindow *qMainWindow)
    {
        qwtMain = qMainWindow;

        this->setupUi(qMainWindow);
        this->setupUIElementContents();
        this->setupUISignals();

        qsdDatabase = QSqlDatabase::addDatabase("QSQLITE");
        qsdDatabase.setDatabaseName(QString("%1%2%3%4%5").arg(QApplication::applicationDirPath(), QDir::separator(), "..", QDir::separator(), "assessment.db"));

        if (!qsdDatabase.open())
        {
            qDebug() << "Error while opening database";
        }

        qsqmStudentTableView = new QSqlQueryModel(this);
        qsqmResultTableView = new QSqlQueryModel(this);

        qsqmTeacherComboBox = new QSqlQueryModel(this);
        qsqmTeacherComboBox->setQuery("SELECT  [teacher_id], ([name] || ' ' || [surname]) "
                                      "FROM    [tblTeacher] ",
                                      qsdDatabase);
        qcbTeacher->setModel(qsqmTeacherComboBox);
        qcbTeacher->setModelColumn(1);
        qcbTeacher->setCurrentIndex(0);
    }

    ~AMain()
    {
    }
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QMainWindow qm(nullptr);

    AMain mmw(&qm);

    qm.show();
    return app.exec();
}