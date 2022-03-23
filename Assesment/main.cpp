#include <QtGui>
#include <QApplication>
#include <QLabel>

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

class MyMainWindow : public QObject
{
private:
    QWidget *qwtMain;
    QPushButton *qpbSave;
    QTableView *qtvStudent;
    QTableView *tableView;
    QTableView *tableView_2;

    void setupUi(QMainWindow *qmwMain)
    {
        if (qmwMain->objectName().isEmpty())
            qmwMain->setObjectName(QString::fromUtf8("qmwMain"));
        qmwMain->resize(741, 582);
        qwtMain = new QWidget(qmwMain);
        qwtMain->setObjectName(QString::fromUtf8("qwtMain"));
        qpbSave = new QPushButton(qwtMain);
        qpbSave->setObjectName(QString::fromUtf8("qpbSave"));
        qpbSave->setGeometry(QRect(11, 543, 93, 28));
        qtvStudent = new QTableView(qwtMain);
        qtvStudent->setObjectName(QString::fromUtf8("qtvStudent"));
        qtvStudent->setGeometry(QRect(11, 11, 256, 192));
        tableView = new QTableView(qwtMain);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(340, 100, 256, 192));
        tableView_2 = new QTableView(qwtMain);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(140, 320, 256, 192));
        qmwMain->setCentralWidget(qwtMain);

        retranslateUi(qmwMain);

        QMetaObject::connectSlotsByName(qmwMain);
    } // setupUi

    void retranslateUi(QMainWindow *qmwMain)
    {
        qmwMain->setWindowTitle(QCoreApplication::translate("qmwMain", "MainWindow", nullptr));
        qpbSave->setText(QCoreApplication::translate("qmwMain", "PushButton", nullptr));
    } // retranslateUi

    void setupUIElementContents()
    {
    }

    void setupUISignals()
    {
    }

public:
    MyMainWindow(QMainWindow *qMainWindow)
    {
        qwtMain = qMainWindow;

        this->setupUi(qMainWindow);
        this->setupUIElementContents();
        this->setupUISignals();
    }

    ~MyMainWindow()
    {
    }
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QMainWindow qm(nullptr);

    MyMainWindow mmw(&qm);

    qm.show();
    return app.exec();
}