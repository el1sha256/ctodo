#ifndef UTILS_H
#define UTILS_H

int create_config_file(const char* name);

int create_dir_if_not_exist(const char* path_to_dir);


enum gui_states {
    MAIN_SCREEN = 1,
    ALL_TODOS,
};

void draw_screen(int screen);

#endif
