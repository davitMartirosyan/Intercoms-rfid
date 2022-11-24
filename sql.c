#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>


int main(int argc, char **argv)
{
    MYSQL *conn;

    static char *host = "localhost";
    static char *user = "dmartiro";
    static char *pass = "@Alkatras1998";
    static char *dbname = "ac";

    unsigned int port = 3360;
    static char *unix_socket = NULL;
    unsigned int flag = 0;

    conn = mysql_init(NULL);
    if(!mysql_real_connect(conn, host, user, pass, dbname, port, unix_socket, flag))
    {
        fprintf(stderr, "Connection Failed: %s [%d]\n", mysql_error(conn), mysql_errno(conn));
        return (1);
    }
    printf("Has been succesfully connected!\n");
    exit(0);
}