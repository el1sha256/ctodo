main: main.c ./db/connection.c ./modules/utils.c
	gcc -g -Wall -l sqlite3 main.c ./db/connection.c ./modules/utils.c -o main

wc: main.c
	gcc -g -Wall main.c -o wc
