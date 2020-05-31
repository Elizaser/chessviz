CC = gcc

CFLAGS = -Wall -Werror -c -MP -MMD -std=c99
FLAGS= -Wall -Werror -std=c99

SRC=src/


BUILD = build/
DIRT=buildt/
OBJECTS = $(BUILD)printb.o  $(BUILD)console.o $(BUILD)main.o 
OBJECTS_TEST=$(DIRT)main_test.o

BIN = bin/
EXE = $(BIN)main

.PHONY: all default clean test
all: bin build buildt default test
default: $(EXE)
test: $(BIN)main_test
	$(BIN)main_test
$(EXE): $(OBJECTS)
	$(CC) $(FLAGS)  $(OBJECTS) -o $@ 
$(BUILD)main.o:  $(SRC)main.c   $(SRC)console.h  
	$(CC) $(CFLAGS) $(SRC)main.c -o $@
$(BUILD)printb.o: $(SRC)printb.c $(SRC)printb.h  
	$(CC) $(CFLAGS) $(SRC)printb.c -o $@
$(BUILD)console.o:  $(SRC)printb.h $(SRC)console.c   $(SRC)console.h  
	$(CC) $(CFLAGS) $(SRC)console.c -o $@
$(BIN)main_test: $(OBJECTS_TEST)
	$(CC) $(FLAGS) $(OBJECTS_TEST) -o $@
$(DIRT)main_test.o: test/main.c thirdparty/ctest.h  
	$(CC) $(CFLAGS) -I thirdparty -I src -c test/main.c -o $@

bin:
	mkdir bin 
build:
	mkdir build
buildt:
	mkdir buildt
run:
	./bin/main pole.txt
clean:
	rm   build/*.o build/*.d bin/main  
