#include <iostream>
#include <string>

// #include <mysqlx/xdevapi.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>


// using namespace mysqlx;


int main()
{
    try 
    {
        sql::Driver *driver = get_driver_instance();
        std::unique_ptr<sql::Connection> con(
        driver->connect("tcp://127.0.0.1:33060", "user", "password")); // FILL IN HERE
        con->setSchema("db");
        if (con != NULL) 
        {
            std::cout << "MySQL Connected successfully!\n";
        }


        // Session sess(SessionOption::HOST,"127.0.0.1", SessionOption::PORT,33060, SessionOption::USER, "user", SessionOption::PWD,"password");
    } catch (const std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}