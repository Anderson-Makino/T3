siguel: args.o arquivo.o circulo.o comandos.o concatena.o formaGeo.o learq.o list.o retangulo.o main.o
	gcc args.o arquivo.o circulo.o comandos.o concatena.o formaGeo.o learq.o list.o retangulo.o main.o -o siguel -lm -fstack-protector-all   -std=c99 -g

args.o: args.c args.h
		gcc -c args.c -o args.o -lm  -fstack-protector-all   -std=c99 -g

arquivo.o: arquivo.c arquivo.h
		gcc -c arquivo.c -o arquivo.o -lm  -fstack-protector-all   -std=c99 -g	
	
circulo.o: circulo.c circulo.h
		gcc -c circulo.c -o  circulo.o -lm  -fstack-protector-all   -std=c99 -g
		
comandos.o: comandos.c comandos.h
	gcc -c comandos.c -o comandos.o -lm  -fstack-protector-all   -std=c99 -g

concatena.o: concatena.c concatena.h
	gcc -c concatena.c -o concatena.o -lm  -fstack-protector-all   -std=c99 -g

formaGeo.o:formaGeo.c formaGeo.h
	gcc -c formaGeo.c -o formaGeo.o -lm  -fstack-protector-all   -std=c99 -g
	
learq.o: learq.c learq.h
	gcc -c learq.c -o learq.o  -lm -fstack-protector-all   -std=c99 -g

list.o: list.c list.h
	gcc -c list.c -o list.o  -lm -fstack-protector-all   -std=c99 -g

retangulo.o: retangulo.c retangulo.h
	gcc -c retangulo.c -o retangulo.o  -lm -fstack-protector-all   -std=c99 -g

main.o: main.c
	gcc -c main.c -o main.o  -lm -fstack-protector-all   -std=c99 -g
	
clean:
	rm -rf *.o