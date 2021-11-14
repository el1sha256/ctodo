#include<sqlite3.h>
#include<stdio.h>
#include"connection.h"

//void get_all(sqlite3 db){
//    int rc = 0;
//    char *sql_err = 0;
//    char *SQL = "insert into todos values(0, \"first\", \"desc for first"\
//                 "todo\", 453, 3444)";
//    sqlite3_exec(db, SQL, 0, 0, &sql_err);
//    if(rc){
//        fprintf(stderr, "Insert SQL err: ", sql_err);
//    }
//}

int get_all(){
    fprintf(stderr, "hello");
}
