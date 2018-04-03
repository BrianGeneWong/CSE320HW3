part2:
	gcc -g part2.c -o part2 -lm
	gcc -g app1.c -o app1 -lm
	gcc -g app2.c -o app2 -lm
	gcc -g app3.c -o app3 -lm
part3:
	gcc -g wallet_stat.c -o part3
	gcc -g print_help.o -o print_help
clean:
	rm -f part2
	rm -f app1
	rm -f app2
	rm -f app3
	rm -f part3
	rm -f print_help

