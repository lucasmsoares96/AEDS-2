all:
	gcc -Wall -Wextra src/*.c
run:
	./a.out
db:
	clang -fstandalone-debug -g -O0 src/**/*.c src/*.c  && lldb a.out
clean:
	rm a.out 
