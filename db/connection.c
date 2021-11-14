#include<sqlite3.h>
#include<stdio.h>
#include<stdlib.h>

sqlite3 *db_connect(const char* filename){
    sqlite3 *db;
    int rc;
    char *exec_err = 0;

    rc = sqlite3_open(filename, &db);

    if( rc ){
        printf("Fail when open connection with db\n;");
        exit(1);
    }
    char *SQL = "create table if not exists todos("\
                 "id    int primary key    not null,"\
                 "title text               not null,"\
                 "desc  text                       ,"\
                 "date_add int             not null,"\
                 "date_to_complete int            );"\
                 "create table if not exists service("\
                 "id    int primary key not null,"\
                 "max_id int default 0);"\
                 "insert into service values(0, 0);";

    rc = sqlite3_exec(db, SQL, 0, 0, &exec_err);
    if(rc){
        fprintf(stderr, "SQL error: %s", exec_err);
        sqlite3_free(exec_err);
        exit(1);
    }
    return db;
}

