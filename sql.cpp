#include "includes/connections.h"

QueryResult *querySelect(SqlConnect *con, const char *query);
SqlConnect *setConnection(Drive *driver);

int main(int argc, const char **argv)
{
    try
    {
        Drive *driver = get_driver_instance();
        SqlConnect *con = setConnection(driver);
        QueryResult *query = querySelect(con, "SELECT * FROM users");
        while(query->next())
        {
            std::cout << query->getString("fname") << " "
                << query->getString("lname") << std::endl;
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
    return EXIT_SUCCESS;
}

SqlConnect *setConnection(Drive *driver)
{
    SqlConnect *con = driver->connect(HOST, USER, PASS);
    con->setSchema(DB);
    return (con);
}

QueryResult *querySelect(SqlConnect *con, const char *query)
{
    sql::Statement *stmt = con->createStatement();
    QueryResult *res = stmt->executeQuery(query);
    return (res);
}