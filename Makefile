SRCS = Helper-methods.c infix-to-postfix.c Tree.c main.c
HDRS = Helper-methods.h infix-to-postfix.h Tree.h
OBJS = $(SRCS:.c=.o)
EXE = calculator

CFLAGS = -std=c11 -Wall -Werror -g++
$(EXE): $(OBJS)
	$(CXX) -o $@ $(OBJS)
valgrind:
	valgrind ./$(EXE)
clean:
	-rm $(OBJS) $(EXE)