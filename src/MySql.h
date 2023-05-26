#ifndef MYSQL_H
#define MYSQL_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include <string>

class MySql {
    public: 
        MySql();
        MySql(std::string ipaddress, std::string port, std::string username, std::string password);
        void connectToDatabase();

    private:
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;
        std::string ipaddress;
        std::string port;
        std::string username;
        std::string password;
        
};

#endif