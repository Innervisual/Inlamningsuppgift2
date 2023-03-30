PROG = main.exe
TEST_PROG = test_main.exe
SRC = main.c card_reader.c safeinput.c
TEST_SRC = test_card_reader.c card_reader.c safeinput.c
CFLAGS = -g
LIBS =

all: $(PROG)

test: $(TEST_PROG)

test_card_reader.exe: test_card_reader.c card_reader.c safeinput.c
	cc -o test_card_reader.exe -g test_card_reader.c card_reader.c safeinput.c

test: test_card_reader.exe
	./test_card_reader.exe

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(SRC) $(LIBS)

$(TEST_PROG): $(TEST_SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $(TEST_SRC) $(LIBS)

clean:
	rm -f $(PROG) $(TEST_PROG)

.PHONY: all clean test

