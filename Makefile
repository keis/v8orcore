JSCORE_CFLAGS=$(shell pkg-config --cflags javascriptcoregtk-3.0)
JSCORE_LIBS=$(shell pkg-config --libs javascriptcoregtk-3.0)

V8_LIBS=-lv8

all: simple-eval.core simple-eval.v8

.PHONY: clean

simple-eval.core: simple-eval.core.o
	$(CC) $(JSCORE_LIBS) $< -o $@

simple-eval.v8: simple-eval.v8.o
	$(CC) $(V8_LIBS) $< -o $@

%.core.o: src/%.core.c
	$(CC) $(JSCORE_CFLAGS) -c $< -o $@

%.v8.o: src/%.v8.cc
	$(CC) $(V8_CFLAGS) -c $< -o $@

clean:
	rm *.o
