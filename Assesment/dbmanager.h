#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QString>

/**
 * DbManager sets up the connection with SQL database
 * and performs some basics queries. The class requires
 * existing SQL database. You can create it with sqlite:
 * 1. $ sqlite3 people.db
 * 2. sqilte> CREATE TABLE people(ids integer primary key, name text);
 * 3. sqlite> .quit
 */
class DbManager
{
public:

    DbManager(const QString& path);

    ~DbManager();

    bool isOpen() const;

    bool createTables();

    bool addStudent(const QString& name);
    bool addTeacher(const QString& name);
    bool addResult(const QString& name);

    bool removePerson(const QString& name);

    bool personExists(const QString& name) const;

    void printAllPersons() const;

    bool removeAllPersons();

private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
