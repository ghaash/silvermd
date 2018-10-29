default: prog

prog:
	gcc -Wall -std=c99 -o prog testme.c -coverage
		
clean:
	rm prog

cleanall: 
	rm prog 