FLAGS = -Wall -g
INCLUDE = -Iinclude
LIBS = -l:raylib.a -lWinmm -lopengl32 -lgdi32
LIB_PATHS= -Llib

default:	main.c 
	gcc ${FLAGS} main.c ${LIB_PATHS} ${LIBS} ${INCLUDE} -o .\build\av.exe && .\build\av.exe

build:	main.c 
	gcc ${FLAGS} main.c -o .\build\av.exe

run:	main.c 
	.\build\av.exe
