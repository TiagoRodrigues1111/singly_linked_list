CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = simplemain.o singlelinkedlist.o
TARGET = single_linked_list_test

# Default target
all: $(TARGET)

run: $(TARGET)
	./$(TARGET)



$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)



simplemain.o: simplemain.c singlelinkedlist.h
	$(CC) $(CFLAGS) -c simplemain.c





singlelinkedlist.o: singlelinkedlist.c singlelinkedlist.h
	$(CC) $(CFLAGS) -c singlelinkedlist.c



clean:
	rm -f $(OBJ) $(OBJ_ll) $(TARGET)



rebuild: clean all
