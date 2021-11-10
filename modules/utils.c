#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>


enum gui_states {
    MAIN_SCREEN = 1,
    ALL_TODOS,
};

void draw_screen(int screen){
    //Clear screen (Linux, Windows)
    system("@cls||clear");
    switch(screen){
        case MAIN_SCREEN:
            printf("/all: See all notes\n");
            printf("/last: See last note\n");
            printf("Command: ");
            break;
    }
}
