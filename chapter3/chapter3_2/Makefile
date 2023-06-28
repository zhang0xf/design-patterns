CC = clang++
WORKDIR = .
INCFLAG = -I$(WORKDIR)
SRCDIR = $(WORKDIR)
CFLAGS = -Wall -Wextra -Werror -g
LIBS = -lstdc++ -std=c++11

SRCS = $(wildcard $(SRCDIR)/*.cpp)
NODIR = $(notdir $(SRCS))
OBJS = $(patsubst %.cpp, %.o, $(NODIR))

BIN = main

$(BIN):$(OBJS)
	$(CC) $(LIBS) $^ -o $@

%.o:$(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $(INCFLAG) -c $< -o $@

.PHONY:clean

clean:
	rm ./main ./map_site.o ./maze_game.o ./maze_game_main.o ./maze_builder.o
	