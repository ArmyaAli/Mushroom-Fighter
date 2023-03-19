FLAGS = -Wall -g
INCLUDE = -Iinclude
LIBS = -l:raylib.a -lWinmm -lopengl32 -lgdi32
LIB_PATHS= -Llib
FILES= src\main.c src\core\asset_loader.c src\core\animations.c src\core\logger.c src\menu.c src\core\state.c

default:	src\main.c 
	gcc ${FLAGS} $(FILES) ${LIB_PATHS} ${LIBS} ${INCLUDE} -o .\build\av.exe && .\build\av.exe

build:	src\main.c 
	gcc ${FLAGS} src\main.c -o .\build\av.exe

run:	src\main.c 
	.\build\av.exe
