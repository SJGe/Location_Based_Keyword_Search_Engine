//
// Created by Shijie Ge on 2019-03-21.
//

#include "MyDb.h"
#include <iostream>
#include <string>
using namespace std;

MyDb::MyDb() {
    mysql = mysql_init(NULL);
    if(!mysql) {
        cout << "Error:" << mysql_error(mysql);
        exit(1);
    }
}

MyDb::~MyDb() {
    if(mysql) {
        mysql_close(mysql);
    }
}

bool MyDb::initDB(string host, string user, string pwd, string db_name, int port = 3306) {
    mysql = mysql_real_connect(mysql, host.c_str(), user.c_str(), pwd.c_str(), db_name.c_str(), port, NULL, 0);
    if(!mysql) {
        cout << "Error: " << mysql_error(mysql);
        exit(1);
    }
    return true;
}

bool MyDb::exeSQL(string sql) {
    if(mysql_query(mysql, sql.c_str())) {
        cout << "Query Error: " << mysql_error(mysql);
        return false;
    }

    result = mysql_store_result(mysql);

    if(result) {
        int num_fields = mysql_num_fields(result);
        unsigned long long num_rows = mysql_num_rows(result);

        for(unsigned long long i = 0;i<num_rows;i++) {
            row = mysql_fetch_row(result);
            if(!row) {
                break;
            }

            for(int j=0;j<num_fields;j++) {
                cout << row[j] << "\t\t";
            }
            cout << endl;
        }
    } else {
        if(mysql_field_count(mysql) == 0) {
            unsigned long long num_rows = mysql_affected_rows(mysql);
            return num_rows;
        } else {
            cout << "Get result error" << mysql_error(mysql);
            return false;
        }
    }
    return true;
}

