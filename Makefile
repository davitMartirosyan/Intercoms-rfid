
all : 
	g++  -I/usr/include/cppconn -o sql sql.cpp -L/usr/lib -lmysqlcppconn