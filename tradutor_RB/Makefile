all:
	gcc -Wunused src/*.c -o rb.out && ./rb.out
db:
	clang -fstandalone-debug -g -O0 src/**/*.c src/*.c  -o rb.out && lldb rb.out
clean:
	rm rb.out 
