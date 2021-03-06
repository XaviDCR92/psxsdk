# Makefile for PSX SDK library

include ../Makefile.cfg

CFLAGS += -Os

# Never remove the line below!
CFLAGS += -D__IN_LIBPSX -ffunction-sections -fdata-sections

OBJS =	$(patsubst src/%.c, out/%.o, $(wildcard src/*.c)) \
		$(patsubst src/libc/%.c, out/libc/%.o, $(wildcard src/libc/*.c)) \
		$(patsubst src/runexe/%.c, out/runexe/%.o, $(wildcard src/runexe/*.c)) \
		$(patsubst src/%.s, out/%.o, $(wildcard src/*.s)) \
		$(patsubst src/runexe/%.s, out/runexe/%.o, $(wildcard src/runexe/*.s))

all: libpsx.a start.o

libpsx.a: $(OBJS)
	$(AR) r libpsx.a $(OBJS)

out/%.o: src/%.c
	@mkdir out -p
	$(CC) $(CFLAGS) -c -o $@ $<

out/libc/%.o: src/libc/%.c
	@mkdir out -p
	@mkdir out/libc -p
	$(CC) $(CFLAGS) -c -o $@ $<

out/runexe/%.o: src/runexe/%.c
	@mkdir out -p
	@mkdir out/runexe -p
	$(CC) $(CFLAGS) -c -o $@ $<

out/%.o: src/%.s
	@mkdir out -p
	$(CC) $(CFLAGS) -c -o $@ $<

out/runexe/%.o: src/runexe/%.s
	@mkdir out -p
	@mkdir out/runexe -p
	$(CC) $(CFLAGS) -c -o $@ $<

start.o: src/start/start.s
	$(CC) $(CFLAGS) -c -o $@ $<

install: libpsx.a start.o
	cp libpsx.a $(TOOLCHAIN_PREFIX)/lib
	cp start.o $(TOOLCHAIN_PREFIX)/lib
	cp -r include/*	$(TOOLCHAIN_PREFIX)/include

clean:
	rm -f $(OBJS)
	rm -f libpsx.a
	rm -f start.o

distclean: clean
