#include<sqlite3.h>
#include<stdio.h>
#include"../db/connection.h"


void get_all(sqlite3* db, int(*callback)(void*, int, char**, char**)){
    char *errMsg = 0;
    int rc;
    char *sql = "SELECT * FROM todos;";
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if(rc != SQLITE_OK){
        fprintf(stderr, "Sql err: %s\n", errMsg);
    }
}

char *create_task(sqlite3 *db, char* title, char* desc){
    char *errMsg = 0;
    int rc;
    char *prepare_sql = "INSERT INTO todos values("\
                         "NULL, \"%s\", \"%s\", %d, %d);";
    //improve string size
    int sizeof_sql = sizeof(prepare_sql)+5200;
    char sql[sizeof_sql];
    snprintf(sql, sizeof_sql, prepare_sql, title, desc, 0, 0);
    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if(rc != SQLITE_OK){
        return errMsg;
    }else{
        return "Added!";
    }
}

char *remove_task(sqlite3 *db, int id){
    char *errMsg = 0;
    int rc;
    char *prepare_sql = "DELETE from todos where id=%d;";
    char sql[sizeof(prepare_sql)+1000];
    sprintf(sql, prepare_sql, id);
    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if(rc != SQLITE_OK){
        return errMsg;
    }else{
        return 0;
    }
}

