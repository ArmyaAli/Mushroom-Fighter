FLAGS = -Wall -g
INCLUDE = -Iinclude
LIBS = -l:raylib.a -lWinmm -lopengl32 -lgdi32
LIB_PATHS= -Llib

default:	src\main.c 
	gcc ${FLAGS} src\main.c ${LIB_PATHS} ${LIBS} ${INCLUDE} -o .\build\av.exe && .\build\av.exe

build:	src\main.c 
	gcc ${FLAGS} src\main.c -o .\build\av.exe

run:	src\main.c 
	.\build\av.exe
