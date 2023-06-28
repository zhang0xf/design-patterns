CC = clang++
WORKDIR = .
INCFLAG = -I$(WORKDIR)
SRCDIR = $(WORKDIR)
CFLAGS = -Wall -Wextra -Werror -g
# LIBS = -lstdc++ -std=c++11

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
	rm ./boolean_exp.o ./boolean_exp_main.o ./main