part2:
	gcc -g part2.c -o part2 -lm
	gcc -g app1.c -o solver -lm
	gcc -g app2.c -o trace -lm
	gcc -g app3.c -o fib -lm
part3:
	gcc -g wallet_stat.c -o part3
	gcc -g print_help.o -o print_help
clean:
	rm -f part2
	rm -f solver
	rm -f trace
	rm -f fib
	rm -f part3
	rm -f print_help

