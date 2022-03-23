#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QBoxLayout>
#include <QLineEdit>
#include <QDebug>
#include <QComboBox>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initializeGUI();

private:
    Ui::MainWindow *ui;
    QComboBox *cb;
    QString id = "Student ID";
    QString name = "Student Name";
    QString surname = "Student Surname";

    QLabel *IdLabel;
    QLabel *NameLabel;
    QLabel *SurnameLabel;
    QLabel *resultLabel;
    QLabel *teacher_idLabel;
    QLabel *student_idLabel;

    QLineEdit *idLE;
    QLineEdit *result;
    QLineEdit *teacher_id;
    QLineEdit *student_id;
    QLineEdit *nameLE;
    QLineEdit *surnameLE;
    QVBoxLayout *vBoxLayout;
};
#endif // MAINWINDOW_H
