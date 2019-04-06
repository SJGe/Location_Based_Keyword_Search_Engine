//
// Created by Shijie Ge on 2019-03-21.
//

#ifndef MYSQL_TEST_MYDB_H
#define MYSQL_TEST_MYDB_H

#include "/usr/local/mysql/include/mysql.h"
//#include <mysql/include/mysql.h>
#include <string>
using namespace std;

class MyDb {
public:
    MyDb();
    ~MyDb();

    bool initDB(string host, string user, string pwd, string db_name, int port);
    bool exeSQL(string sql);

private:
    MYSQL *mysql;
    MYSQL_RES *result;
    MYSQL_ROW row;
};

#endif //MYSQL_TEST_MYDB_H
