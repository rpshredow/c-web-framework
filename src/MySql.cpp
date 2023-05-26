#include "MySql.h"

#include <string>

MySql::MySql(){}
MySql::MySql(std::string ipaddress, std::string port, std::string username, std::string password) : 
ipaddress(ipaddress), port(port), username(username), password(password) {}

void MySql::connectToDatabase() {
    std::string address = "tcp://" + ipaddress + ":" + port;

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect(address, username, password);
    con->setSchema("example");
}

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