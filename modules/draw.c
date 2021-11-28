#include<stdio.h>
#include<sqlite3.h>
#include"../db/crud.h"


// Not main draw func using as callback
int draw_todo(void *NotUsed, int argc, char **argv, char **ColName){
    NotUsed = 0;

    printf("\n");
    printf("id: %s\n", argv[0]);
    for(int i = 1; i < 3; i++){
        printf("%s: %s", ColName[i],argv[i]);
    }
    printf("\n");
    return 0;
}

void draw_main(){
    printf("###  MAIN SCREEN  ###\n\n");
    printf("todos: See uncompleted tasks\n");
    printf("completed: See completed tasks\n");
    printf("add: Add task\n");
    printf("remove <id>: Remove task by id\n");
    printf("complete <id>: Complete task by id\n");
    printf("help: View help\n");
    printf("exit: Exit from ctodo\n");
}

void draw_uncompleted_todos(sqlite3 *db){
    printf("### TODOS ###\n");
    //printf("There all todos from db\n");
    get_all(db, draw_todo, 0);
}

void draw_completed_todos(sqlite3 *db){
    printf("###  COMPLETED TODOS ###\n");
    get_all(db, draw_todo, 1);
}

void draw_unknown_cmd(){
    printf("###  UNKNOWN COMMAND! ###\n");
    printf("Type 'main' to return on main screen\n");
}

void draw_add_todo(sqlite3 *db){
    char title[200];
    char desc[5000];
        
    printf("### ADD TASK ###\n\n");

    printf("Title (max 200): ");
    fgets(title, 200, stdin);

    printf("Description (max 5000): ");
    fgets(desc, 5000, stdin);
    printf("%s\n", create_task(db, title, desc));
}

void draw_help_screen(){
    printf("### USER MANUAL ###\n\n");

    printf("main: Open main screen\n");
    printf("all: View all tasks\n");
    printf("exit <arg>: Exit from ctodo, <arg> maybe 'clear',"\
            " this is clear screen before exit\n");
}
