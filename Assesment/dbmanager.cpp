#include <dbmanager.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

DbManager::DbManager(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

DbManager::~DbManager()
{
    if (m_db.isOpen())
   j    "   11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111  {
        m_db.close();
    }
}

bool DbManager::isOpen() const
{
    return m_db.isOpen();
}

bool DbManager::createTables()
{
    bool ret;
    bool success[3] = { false };

    QSqlQuery queryStudent;
    queryStudent.prepare("CREATE TABLE students(student_id INTEGER PRIMARY KEY, name TEXT, surname TEXT);");

    if (!queryStudent.exec())
    {
        qDebug() << "Couldn't create the table students: it might already exist.";
        success[0] = false;
    }


    QSqlQuery queryTeacher;
    queryTeacher.prepare("CREATE TABLE teachers(teacher_id INTEGER PRIMARY KEY, name TEXT, surname TEXT);");

    if (!queryTeacher.exec())+----------------------------------------------------------------------------
    {
        qDebug() << "Couldn't create the table queryTeacher: it might already exist.";
        success[1] = false;
    }

    QSqlQuery queryResults;
    queryResults.prepare("CREATE TABLE results(result_id INTEGER PRIMARY KEY, result INTEGER, teacher_id INTEGER, student_id INTEGER);");

    if (!queryResults.exec())
    {
        qDebug() << "Couldn't create the table queryResults: it might already exist.";
        success[2] = false;
    }

    return success[0] && success[1] && success[2];
}

bool DbManager::addStudent(const QString& name)
{
    bool success = false;

    if (!name.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO students (name) VALUES (:name)");
        queryAdd.bindValue(":name", name);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add student failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add student failed: name cannot be empty";
    }

    return success;
}

bool DbManager::addTeacher(const QString& name)
{
    bool success = false;

    if (!name.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO teachers (name) VALUES (:name)");
        queryAdd.bindValue(":name", name);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add teachers failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add teachers failed: name cannot be empty";
    }

    return success;
}

bool DbManager::addResult(const QString& name)
{
    bool success = false;

    if (!name.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO results (name) VALUES (:name)");
        queryAdd.bindValue(":name", name);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add results failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add results failed: name cannot be empty";
    }

    return success;
}

bool DbManager::removePerson(const QString& name)
{
    bool success = false;

    if (personExists(name))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM people WHERE name = (:name)");
        queryDelete.bindValue(":name", name);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove person failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove person failed: person doesnt exist";
    }

    return success;
}

void DbManager::printAllPersons() const
{
    qDebug() << "Persons in db:";
    QSqlQuery query("SELECT * FROM people");
    int idName = query.record().indexOf("name");
    while (query.next())
    {
        QString name = query.value(idName).toString();
        qDebug() << "===" << name;
    }
}

bool DbManager::personExists(const QString& name) const
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT name FROM people WHERE name = (:name)");
    checkQuery.bindValue(":name", name);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "person exists failed: " << checkQuery.lastError();
    }

    return exists;
}

bool DbManager::removeAllPersons()
{
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM people");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all persons failed: " << removeQuery.lastError();
    }

    return success;
}
