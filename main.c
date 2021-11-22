#include<sqlite3.h>
#include<stdio.h>
#include<stdlib.h>
#include"db/connection.h"
#include"modules/utils.h"
#include"modules/crud.h"

int gui_state = MAIN_SCREEN;
int screen_update_require = 1;

int main(){
    sqlite3 *db = db_connect(get_db_path());
    int is_exit = 1;
    char command[200];
    while (is_exit){
        if(screen_update_require){
            fprintf(stderr, "\n if cond\n");
            draw_screen(gui_state);
            screen_update_require = 0;
        }
        fgets(command, 200, stdin);
        exec_command(command, db);
    } 

    sqlite3_close(db);
    return 0;
}
