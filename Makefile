OBJS = src/main.cpp src/App.cpp src/Board.cpp src/Bot.cpp src/Game.cpp src/Util.cpp
CC = g++
COMPILER_FLAGS = -w
LINKER_FLAGS = `sdl2-config --libs`
INCLUDE = -I"/usr/include/SDL2"
EXECUTABLE = tictactoe

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(INCLUDE) $(LINKER_FLAGS) -o $(EXECUTABLE)
