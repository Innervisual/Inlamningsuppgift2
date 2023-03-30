PROG = main.exe
TEST_PROG = test_main.exe
SRC = main.c card_reader.c safeinput.c
OBJ = main.o card_reader.o safeinput.o
TEST_SRC = test_card_reader.c card_reader.c safeinput.c
TEST_OBJ = test_card_reader.o card_reader.o safeinput.o
CFLAGS = -O3 -Wall -Werror
CFLAGS2 = -g -Wall -Werror
DEPS =
OBJ_CODE =
LIBGTEST = C:\msys64\mingw64\lib\libgtest_main.a C:\msys64\mingw64\lib\libgtest.a

all: $(PROG)

test: $(TEST_PROG)

test_card_reader.exe: test_card_reader.c card_reader.c safeinput.c
	cc -o test_card_reader.exe -g test_card_reader.c card_reader.c safeinput.c

test: test_card_reader.exe
	./test_card_reader.exe

$(PROG): $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(OBJ) $(LIBS)

$(TEST_PROG): $(TEST_OBJ)
	$(CC) -o $@ $(CFLAGS2) $(LDFLAGS) $(TEST_OBJ) $(LIBGTEST)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(PROG) $(TEST_PROG) $(OBJ) $(TEST_OBJ)

.PHONY: all clean test


