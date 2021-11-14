#include<sqlite3.h>
#include<stdio.h>
#include<stdlib.h>
#include"db/connection.h"
#include"modules/utils.h"




int main(){
    sqlite3 *db = db_connect("db/hello.sqlite3");
    int is_exit = 1;
    char command[200];
    int gui_state = MAIN_SCREEN;
    int screen_update_require = 1;

    while (is_exit){
        if(screen_update_require){
            draw_screen(gui_state);
            screen_update_require = 0;
        }
        //draw_screen(MAIN_SCREEN);
        fgets(command, 200, stdin);
        exec_command(command, db);
    } 

    sqlite3_close(db);
    return 0;
}
