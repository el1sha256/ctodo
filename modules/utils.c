#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sqlite3.h>
#include"../db/crud.h"
#include"./draw.h"

enum gui_states {
    MAIN_SCREEN = 1,
    HELP_SCREEN,
    ALL_TODOS,
    ADD_TASK,
    UNKNOWN_CMD
};

extern int gui_state;
extern int screen_update_require;


void draw_screen(int screen, sqlite3* db){
    //Clear screen (Linux, Windows)
    system("@cls||clear");
    switch(screen){
        case MAIN_SCREEN:
            draw_main();
            break;
        case HELP_SCREEN:
            draw_help_screen();
            break;
        case ALL_TODOS:
            draw_all_todos(db);
            break;
        case ADD_TASK:
            draw_add_todo(db);
            break;
        case UNKNOWN_CMD:
            draw_unknown_cmd();
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
    if(!strcmp(cmd.command, "all")){
        gui_state = ALL_TODOS;
    }
    else if(!strcmp(cmd.command, "main")){
        gui_state = MAIN_SCREEN;
    }
    else if(!strcmp(cmd.command, "exit")){
        if(!strcmp(cmd.arg, "clear")){
            system("@cls||clear");
        }
        exit(0);
    }
    else if(!strcmp(cmd.command, "add")){
        gui_state = ADD_TASK;
    }
    else if(!strcmp(cmd.command, "help")){
        gui_state = HELP_SCREEN;
    }
    else if(!strcmp(cmd.command, "remove")){
        remove_task(db, atoi(cmd.arg));
    }
    else{
        gui_state = UNKNOWN_CMD;
    };
    screen_update_require = 1;
    return 0;
}

