#include<sqlite3.h>
#include<stdio.h>
#include"../db/connection.h"

struct scheme{
    int id;
    char* title;
    char* desc;
    int add_time;
    int complete_time;
}typedef scheme;

void get_all(sqlite3* db){
    int rc = 0;
    char *sql_err = 0;
    char *SQL = "insert into todos values(0, \"first\", \"desc for first"\
                 "todo\", 453, 3444)";
    sqlite3_exec(db, SQL, 0, 0, &sql_err);
    if(rc){
        fprintf(stderr, "Insert SQL err: %s", sql_err);
    }
}

scheme* add_task(sqlite3* db,
            char* title,
            char* desc,
            int add_time,
            int complete_time
        )
{
    
    char* SQL = "";
}
