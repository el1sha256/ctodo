#ifndef UTILS_H
#define UTILS_H

enum gui_states {
    MAIN_SCREEN = 1,
    TODOS,
    ADD_TASK
};

void draw_screen(int screen, sqlite3 *db);

int exec_command(char*, sqlite3*);
#endif
