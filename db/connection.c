#include<sqlite3.h>
#include<stdio.h>
#include<stdlib.h>

sqlite3 *db_connect(const char* filename){
    static sqlite3 *db;
    int rc;

    rc = sqlite3_open(filename, &db);

    if( rc ){
        printf("Fail when open connection with db\n;");
        exit(1);
    }
    return db;
}
