#ifndef MYSQL_H
#define MYSQL_H

// how to install mysql connector for c++ on ubuntu
// sudo apt update
// sudo apt install libmysqlcppconn-dev

#include <vector>
#include <string>

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "PersonModel.h"

class MySql {
    public: 
        // MySql();
        MySql(std::string ipaddress = "127.0.0.1", std::string port = "3306", std::string username = "robert", std::string password = "bob59145", std::string database = "example");
        void connectToDatabase();
        std::vector<PersonModel> getAll();

    private:
        // sql::Statement *stmt;
        // sql::ResultSet *res;
        std::string ipaddress;
        std::string port;
        std::string username;
        std::string password;
        std::string database;
        
};

#endif