#ifndef DB_CONNECT_H
#define DB_CONNECT_H

sqlite3 *db_connect(const char* filename);
char *get_db_path();

#endif
