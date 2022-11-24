#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#define HOST "127.0.0.1:3360"
#define USER "dmartiro"
#define PASS "@Alkatras1998"
#define DB "users"

typedef sql::Connection SqlConnect;
typedef sql::Driver     Drive;
typedef sql::ResultSet  QueryResult;

std::vector<int> inter_id;
std::vector<long long> rf_id;
std::vector<unsigned int> card_id;
std::vector<std::string> fname;
std::vector<std::string> lname;

