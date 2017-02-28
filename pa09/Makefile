CFLAGS = -g -Wall -Wshadow
GCC = gcc 
SRCS = answer09.c main.c
OBJS = $(SRCS:%.c=%.o)
VALGRIND = valgrind --leak-check=full --tool=memcheck --verbose

comp1 : $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o a
memcheck: a
	$(VALGRIND) a
clean:
	rm -f *.o 
