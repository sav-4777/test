CC = g++
CFLAGS = -g -O2 -Wall


PROG = test
OBJS = main.o
       
       
$(PROG): $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS)  -o $(PROG)

$(OBJS): main.cpp
	$(CC) $(CFLAGS)  -c main.cpp
	
clean:
	rm -rf meminfo_* $(OBJS) $(PROG)
