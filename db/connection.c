#include<sqlite3.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include"service_db.h"

sqlite3 *db_connect(const char* filename){
    sqlite3 *db;
    int rc, ct;
    //char *exec_err = 0;

    rc = sqlite3_open(filename, &db);

    if( rc ){
        printf("Fail when open connection with db\n;");
        exit(1);
    }
    ct = db_create_todos_table(db);

    return db;
}


char *get_db_path(){
    int path_l = 300;
    char username[100];
    char *path = malloc(path_l);
    getlogin_r(username, sizeof(username));
//    fprintf(stderr, "%s\n", username);

    snprintf(path, path_l, "%s%s%s", "/home/", username, "/.config/ctodo.sqlite3");
    return path;
}
