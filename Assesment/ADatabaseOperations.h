#ifndef ADatabaseOperations_h
#define ADatabaseOperations_h

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QDebug>
#include <QTimer>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDir>

class ADatabaseOperations : public QDialog
{
private:
    QGroupBox *groupBox_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *qpbInsert;
    QPushButton *qpbUpdate;
    QPushButton *qpbDelete;
    QGroupBox *groupBox_4;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QLabel *qlNameResult;
    QLineEdit *qleNameResult;
    QGroupBox *groupBox_2;
    QLabel *qlSurname;
    QLineEdit *qleSurname;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_2;
    QTableView *qtvListSTR;
    QWidget *widget2;
    QVBoxLayout *verticalLayout;
    QSqlDatabase qsdDatabase;

    QSqlQueryModel *qsqmStudentTableView;
    QSqlQueryModel *qsqmTeacherTableView;
    QSqlQueryModel *qsqmResultTableView;
    QString objName = "";

    void setupUi(QDialog *qdModifyScreen);
    void retranslateUi(QDialog *qdModifyScreen);
    void setupUIElementContents();
    void setupUISignals();
    void insertBtn_Clicked();
    void deleteBtn_Clicked();
    void updateBtn_Clicked();

public:
    ADatabaseOperations(QString objectName);
    ~ADatabaseOperations();
};

#endif