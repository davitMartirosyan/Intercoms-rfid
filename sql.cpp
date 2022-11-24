#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <vector>
#define HOST "127.0.0.1:3360"
#define USER "dmartiro"
#define PASS "@Alkatras1998"
#define DB "users"

void havayi(sql::Connection *con);

std::vector<int> inter_id;
std::vector<long long> rf_id;
std::vector<unsigned int> card_id;
std::vector<std::string> fname;
std::vector<std::string> lname;

typedef sql::Connection conn;

void havayi(conn *con)
{
    con->setSchema(DB);
}

int main(int argc, const char **argv)
{
    try
    {
        sql::Driver *driver = get_driver_instance();
        sql::Connection *con = driver->connect(HOST, USER, PASS);
        havayi(con);
        sql::Statement *stmt = con->createStatement();
        sql::ResultSet *res = stmt->executeQuery("SELECT * FROM users");
        while(res->next())
        {
            std::cout 
                      << res->getString("id") << " "
                      << res->getString("fname") << " "
                      << res->getString("lname")
                      << std::endl;
        }
    }
    catch(sql::SQLException &e)
    {
        std::cout << "# ERR: SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ << ") on Line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code: " << e.getErrorCode();
        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Done." << std::endl;
    return EXIT_SUCCESS;
    
}