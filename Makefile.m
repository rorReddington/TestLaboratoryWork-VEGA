CC 		:= g++
SOURCES := main.c vector.c
TARGET	:= programm


.PHONY: all clean

all: main

main: 
	$(CC) $(SOURCES) -o $(TARGET)
        
clean:
	rm -f *.o main vector