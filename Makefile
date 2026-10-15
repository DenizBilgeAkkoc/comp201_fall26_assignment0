CC = gcc
CFLAGS = -std=c99 -Wall -Wextra
TARGET = assignment0
OBJECTS = main.o myprogram.o mylibrary.o

.PHONY: all test clean

all: $(TARGET)

# Linking: combine the three object files into one executable.
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Compilation: compile each source file independently.
# Header prerequisites ensure changes to declarations trigger recompilation.
main.o: main.c myprogram.h mylibrary.h
	$(CC) $(CFLAGS) -c main.c -o main.o

myprogram.o: myprogram.c myprogram.h mylibrary.h
	$(CC) $(CFLAGS) -c myprogram.c -o myprogram.o

mylibrary.o: mylibrary.c mylibrary.h
	$(CC) $(CFLAGS) -c mylibrary.c -o mylibrary.o

# Each input file is paired with an expected-output file.
# Any program error or output mismatch makes this target fail.
test: $(TARGET)
	@failed=0; \
	for input in test/*.test-in; do \
		expected="$${input%.test-in}.test-cmp"; \
		if ./$(TARGET) < "$$input" > test/.actual 2>/dev/null && \
		   diff -u "$$expected" test/.actual; then \
			echo "PASS $$input"; \
		else \
			echo "FAIL $$input"; \
			failed=1; \
		fi; \
	done; \
	rm -f test/.actual; \
	exit $$failed

clean:
	rm -f $(OBJECTS) $(TARGET) test/.actual
