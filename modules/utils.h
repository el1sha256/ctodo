#ifndef UTILS_H
#define UTILS_H

enum gui_states {
    MAIN_SCREEN = 1,
    ALL_TODOS,
};

void draw_screen(int screen);

int exec_command(char*, sqlite3*);

#endif
