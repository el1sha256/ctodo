#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sqlite3.h>
#include"./crud.h"
#include"./draw.h"

enum gui_states {
    MAIN_SCREEN = 1,
    ALL_TODOS,
    ADD_TASK
};

extern int gui_state;
extern int screen_update_require;


void draw_screen(int screen){
    //Clear screen (Linux, Windows)
    system("@cls||clear");
    switch(screen){
        case MAIN_SCREEN:
            draw_main();
            break;
        case ALL_TODOS:
            draw_all_todos();
            break;
    }
    printf(">>> ");
}

int exec_command(char* raw_command, sqlite3* db){
    struct s_command{
        char command[10];
        char arg[100];
    }typedef s_command;

    s_command cmd;
    sscanf(raw_command, "%s %s", cmd.command, cmd.arg);
    if(!strcmp(cmd.command, "/all")){
        gui_state = ALL_TODOS;
    }
    else if(!strcmp(cmd.command, "/main")){
        gui_state = MAIN_SCREEN;
    }
    else if(!strcmp(cmd.command, "/exit")){
        if(!strcmp(cmd.arg, "clear")){
            system("@cls||clear");
        }
        exit(1);
    }
    else if(!strcmp(cmd.command, "/add")){
        system("@cls||clear");
    }
    else{
        printf("Unknown command\n");
    };
    screen_update_require = 1;
    return 0;
}
