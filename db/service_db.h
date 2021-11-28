#ifndef SERVICE_DB_H
#define SERVICE_DB_H

int db_create_todos_table(sqlite3 *db);
int db_delete_todos_table(sqlite3 *db);

#endif
