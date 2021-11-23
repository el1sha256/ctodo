#ifndef CRUD_H
#define CRUD_H

void get_all(sqlite3* db, int(*callback)(void*, int, char**, char**));

char *create_task(sqlite3 *db, char* title, char* desc);

char *remove_task(sqlite3 *db, int id);

#endif
