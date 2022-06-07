main: main.c ./db/connection.c ./modules/utils.c ./db/crud.c ./modules/draw.c ./db/service_db.c
	gcc -g -Wall -l sqlite3 main.c ./db/connection.c ./modules/utils.c ./db/crud.c ./modules/draw.c\
  ./db/service_db.c -o ctodo 
	sudo cp ctodo /usr/bin

