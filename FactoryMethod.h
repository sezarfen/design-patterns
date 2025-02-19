#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H

/*
 * Factory Method Pattern provides an interface for generating
 * objects but leaves the actual object instantiation to derived classes.
 * This allows for flexibility in object creation and promotes
 * loose coupling between the client code and the concrete products.
*/

#include <iostream>

class DatabaseConnection{
public:
    virtual void connectToDatabase() = 0;
    virtual ~DatabaseConnection(){

    }
};

class SQLiteDatabaseConnection : public DatabaseConnection{
public:
    void connectToDatabase() override{
        std::cout << "Connection to SQLite database" << std::endl;
    }
};


class MySqlDatabaseConnection : public DatabaseConnection{
public:
    void connectToDatabase() override{
        std::cout << "Connection to MySql database" << std::endl;
    }
};

class DatabaseFactory{
public:
    virtual DatabaseConnection * generateDatabaseConnection() = 0;
    virtual ~DatabaseFactory(){

    }
};

class SQLiteDatabaseFactory : public DatabaseFactory{
public:
    DatabaseConnection * generateDatabaseConnection() override{
        return new SQLiteDatabaseConnection();
    }
};

class MySqlDatabaseFactory : public DatabaseFactory{
public:
    DatabaseConnection * generateDatabaseConnection() override{
        return new MySqlDatabaseConnection();
    }
};

#endif // FACTORYMETHOD_H
