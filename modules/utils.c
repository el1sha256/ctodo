#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sqlite3.h>
#include"./crud.h"

enum gui_states {
    MAIN_SCREEN = 1,
    ALL_TODOS,
    ADD_TASK
};



void draw_screen(int screen){
    //Clear screen (Linux, Windows)
    system("@cls||clear");
    switch(screen){
        case MAIN_SCREEN:
            printf("/all: See all tasks\n");
            printf("/add: Add task\n");
            printf("/last: See last task\n");
            printf("Command: ");
            break;
    }
}

int exec_command(char* raw_command, sqlite3* db){
    struct s_command{
        char command[10];
        char arg[100];
    }typedef s_command;

    s_command cmd;
    sscanf(raw_command, "%s %s", cmd.command, cmd.arg);
    if(!strcmp(cmd.command, "/all")){
        printf("Print All todos\n");
        get_all(db);
    }
    else if(!strcmp(cmd.command, "/clear")){
        system("@cls||clear");
    }
    else if(!strcmp(cmd.command, "/add")){
        system("@cls||clear");
    }
    else{
        printf("Unknown command\n");
    };
    return 0;
}
