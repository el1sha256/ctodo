#include<sqlite3.h>
#include<stdio.h>
#include<stdlib.h>


int db_create_todos_table(sqlite3 *db){
    char *exec_err = 0;
    int rc; 
    char *SQL = "create table if not exists todos("\
                 "id integer primary key autoincrement,"\
                 "title text not null,"\
                 "description text,"\
                 "date_add integer not null,"\
                 "date_to_complete integer,"\
                 "is_completed integer);";

    rc = sqlite3_exec(db, SQL, 0, 0, &exec_err);
    if(rc){
        fprintf(stderr, "SQL error: %s", exec_err);
        sqlite3_free(exec_err);
        // Fix this
        exit(1);
    }
    return 0;
}

int db_delete_todos_table(sqlite3* db){
    char *errMsg = 0;
    int rc;
    char *sql = "drop table todos;";

    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);

    if (rc != SQLITE_OK){
        fprintf(stderr, "%s\n", errMsg);
        sqlite3_free(errMsg);
        return 1;
    }
    return 0;
}
