#include<sqlite3.h>
#include<stdio.h>
#include<stdlib.h>
#include"db/connection.h"
#include"modules/utils.h"
#include"db/crud.h"

int gui_state = MAIN_SCREEN;
int screen_update_require = 1;

int main(){
    char command[200];
    sqlite3 *db = db_connect(get_db_path());
    while (1){
        if(screen_update_require){
            draw_screen(gui_state, db);
            screen_update_require = 0;
        }
        fgets(command, 200, stdin);
        exec_command(command, db);
    } 

    sqlite3_close(db);
    return 0;
}
