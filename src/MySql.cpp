#include <string>
#include <vector>

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "MySql.h"
#include "PersonModel.h"

sql::Connection *connection;

// MySql::MySql(){}
MySql::MySql(std::string ipaddress, std::string port, std::string username, std::string password, std::string database) : 
ipaddress(ipaddress), port(port), username(username), password(password), database(database) 
{
    //MySql::connectToDatabase();
}

void MySql::connectToDatabase() {
    std::string address = "tcp://" + ipaddress + ":" + port;

    sql::mysql::MySQL_Driver *driver;
    // sql::Connection *con;
    // sql::Statement *stmt;
    // sql::ResultSet *res;

    driver = sql::mysql::get_mysql_driver_instance();
    connection = driver->connect("tcp://127.0.0.1:3306", "robert", "bob59145");
    // con->setSchema("example");
    // connection = con;

    // stmt = con->createStatement();
    // stmt->execute("INSERT INTO persons (name, surname, email, password) VALUES ('Robert', 'Shredow', 'rshredow@gmail.com', '59145')");
    // res = stmt->executeQuery("SELECT * FROM persons");

    // std::string output = "";
    // while (res->next()) {
    //     output += "ID: " + std::to_string(res->getInt("id")) + "\t Name: " + res->getString("name") + " " + res->getString("surname") 
    //         + "\t Email: " + res->getString("email") + "\t Password: " + res->getString("password") 
    //         + "\n";
    // }

    // delete res;
    // delete stmt;
    // delete con;

    // return output;
}

std::vector<PersonModel> MySql::getAll() {
    sql::Statement *stmt;
    sql::ResultSet *res;

    connection->setSchema("example");
    stmt = connection->createStatement();
    res = stmt->executeQuery("SELECT * FROM persons");

    std::vector<PersonModel> personVector;

    while (res->next()) {
        personVector.push_back(PersonModel(res->getInt("id"), res->getString("name"), res->getString("surname"), res->getString("email"), res->getString("password")));
    }

    delete res;
    delete stmt;

    return personVector;
}