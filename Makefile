SRCS = Helper-methods.cpp infix-to-postfix.cpp Tree.cpp main.cpp
HDRS = Helper-methods.h infix-to-postfix.h Tree.h
OBJS = $(SRCS:.cpp=.o)
EXE = calculator

CFLAGS = -std=c11 -Wall -Werror -g++
$(EXE): $(OBJS)
	$(CXX) -o $@ $(OBJS)
valgrind:
	valgrind ./$(EXE)
clean:
	-rm $(OBJS) $(EXE)
