# sql::driver - работает
run_1.mysql:
	g++ -std=c++17 -I /usr/include/mysql-cppconn-8/jdbc  -L /usr/lib64  ./1.mysql.cpp -lmysqlcppconn  -o ./build/1.mysql && ./build/1.mysql

# mysqlx/xdevapi.h - не работает
run_2.mysql:
	g++ -std=c++17 -I /usr/include/mysql-cppconn-8/  -L /usr/lib64  ./1.mysql.cpp -lmysqlcppconn8  -o ./build/1.mysql && ./build/1.mysql
