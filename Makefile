CC   = cc
OBJS = my_string.o tokenizer.o main.o

# -Wextra
CFLAGS = -O3 -g3 -Wall -Werror=format-security -Werror=implicit-function-declaration \
         -Wshadow -Wpointer-arith -Wcast-align -Wstrict-prototypes -Wwrite-strings \

all: main

%.o: %.c
	${CC} $(CFLAGS) -c -o $@ $<

main: $(OBJS)
	${CC} -o $@ $^

run: main
	./main Dodge,Challenger,Charger,Durango

clean:
	rm -f *.o main

my_string.o: my_string.c my_string.h
tokenizer.o: tokenizer.c tokenizer.h my_string.h

