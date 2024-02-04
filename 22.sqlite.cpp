#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <string>

#define DATABASE_PATH_SOURCE "/home/eduard/Projects/iu7/C/b0501/test.db"

using std::cout, std::endl;

int callbackNumOfRows(void *sumOfRows, int colCount, char **columns, char **colNames)
{
    *((unsigned long int *)sumOfRows) = strtol(columns[0], NULL, 10);
    return 0;
}

int main()
{
    unsigned long int sumOfRows;
    sqlite3 *db;    // указатель на базу данных
    // открываем подключение к базе данных, открываем поток, заполняем структуру по работе с файлом
    int result  = sqlite3_open(DATABASE_PATH_SOURCE, &db);
    // если подключение успешно установлено
    if(result == SQLITE_OK) 
    {
        cout << "Connection with database established" << endl;
    }
    else
    {
        // выводим сообщение об ошибке
        fprintf(stderr, "Error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    char *err_msg = 0; // указатель на сообщение об ошибки
    std::string sqlNumOfRows = "SELECT Count(*) as rowsnum FROM persons"; // команда запроса в базу данных
    // Основная функция запроса
    result = sqlite3_exec(db, sqlNumOfRows.c_str(), callbackNumOfRows, &sumOfRows, &err_msg);  //sumOfRows передается в функцию обратного вызова в качестве параметра
    if (result != SQLITE_OK)
    {
        printf("SQL error: %s\n", err_msg);
        sqlite3_free(err_msg); // очистка указателя на строку с ошибкой
        sqlite3_close(db);
        exit(1);
    }
    // закрываем подключение
    sqlite3_close(db);
    db = NULL;

    cout << "sum of rows: " << sumOfRows << endl;

    return 0;
}