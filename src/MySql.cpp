#include "MySql.h"

#include <string>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

// MySql::MySql(){}
MySql::MySql(std::string ipaddress, std::string port, std::string username, std::string password, std::string database) : 
ipaddress(ipaddress), port(port), username(username), password(password), database(database) 
{
    //MySql::connectToDatabase();
}

std::string MySql::connectToDatabase() {
    std::string address = "tcp://" + ipaddress + ":" + port;

    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "robert", "bob59145");
    con->setSchema("example");

    stmt = con->createStatement();
    // stmt->execute("INSERT INTO persons (name, surname, email, password) VALUES ('Robert', 'Shredow', 'rshredow@gmail.com', '59145')");
    res = stmt->executeQuery("SELECT * FROM persons");

    std::string output = "";
    while (res->next()) {
        output += "Name: " + res->getString("name") + " " + res->getString("surname") 
            + "\t Email: " + res->getString("email") + "\t Password: " + res->getString("password") 
            + "\n";
    }

    delete res;
    delete stmt;
    delete con;

    return output;
}

// std::string MySql::getAll() {
//     stmt = con->createStatement();
//     res = stmt->executeQuery("SELECT * FROM persons");

//     std::string output = "";

//     while (res->next()) {
//         // Process the results
//         output += "Name: " + res->getString("name") + " " + res->getString("surname") 
//             + "\t Email: " + res->getString("email") + "\t Password: " + res->getString("password");
//     }

//     return output;
// }

/*
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

int main() {
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "robert", "bob59145");
    con->setSchema("example");

    stmt = con->createStatement();
    // stmt->execute("INSERT INTO persons (name, surname, email, password) VALUES ('Robert', 'Shredow', 'rshredow@gmail.com', '59145')");
    res = stmt->executeQuery("SELECT * FROM persons");

    while (res->next()) {
        // Process the results
        std::cout << "Name: " << res->getString("name") << " " << res->getString("surname") 
            << "\t Email: " << res->getString("email") << "\t Password: " << res->getString("password") 
            << std::endl;
    }

    delete res;
    delete stmt;
    delete con;

    return 0;
}
*/