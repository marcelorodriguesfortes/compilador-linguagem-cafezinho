



lexico.c: lexico.l
	flex -olexico.c  lexico.l
 
simpleLang.c:  simpleLang.y
	bison -d -osimpleLang.c simpleLang.y

lexico.o: lexico.c
	gcc -c lexico.c -o lexico.o

simpleLang.o: simpleLang.c
	gcc -c simpleLang.c -o simpleLang.o

simpleLang:  simpleLang.o lexico.o
	gcc simpleLang.o lexico.o -o sint
