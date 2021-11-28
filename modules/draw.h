#ifndef DRAW_H
#define DRAW_H

void draw_main();

void draw_uncompleted_todos(sqlite3 *db);

void draw_completed_todos(sqlite3 *db);

void draw_unknown_cmd();

void draw_add_todo(sqlite3 *db);

void draw_help_screen();
#endif
