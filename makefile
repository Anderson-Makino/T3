siguel: args.o arquivo.o circulo.o comandos.o comandosQry.o consultaQry.o funcoes.o formaGeo.o hidrante.o learq.o list.o quadra.o retangulo.o semaforo.o torre.o main.o
	gcc args.o arquivo.o circulo.o comandos.o comandosQry.o consultaQry.o funcoes.o formaGeo.o hidrante.o learq.o list.o quadra.o retangulo.o semaforo.o torre.o main.o -o siguel -lm -fstack-protector-all   -std=c99 -g

args.o: args.c args.h
		gcc -c args.c -o args.o -lm  -fstack-protector-all   -std=c99 -g

arquivo.o: arquivo.c arquivo.h
		gcc -c arquivo.c -o arquivo.o -lm  -fstack-protector-all   -std=c99 -g	
	
circulo.o: circulo.c circulo.h
		gcc -c circulo.c -o  circulo.o -lm  -fstack-protector-all   -std=c99 -g
		
comandos.o: comandos.c comandos.h
	gcc -c comandos.c -o comandos.o -lm  -fstack-protector-all   -std=c99 -g

comandosQry.o: comandosQry.c comandosQry.h
	gcc -c comandosQry.c -o comandosQry.o -lm  -fstack-protector-all   -std=c99 -g

consultaQry.o: consultaQry.c consultaQry.h
	gcc -c consultaQry.c -o consultaQry.o -lm  -fstack-protector-all   -std=c99 -g
	
funcoes.o: funcoes.c funcoes.h
	gcc -c funcoes.c -o funcoes.o -lm  -fstack-protector-all   -std=c99 -g

formaGeo.o:formaGeo.c formaGeo.h
	gcc -c formaGeo.c -o formaGeo.o -lm  -fstack-protector-all   -std=c99 -g

hidrante.o:hidrante.c hidrante.h
	gcc -c hidrante.c -o hidrante.o -lm  -fstack-protector-all   -std=c99 -g
	
learq.o: learq.c learq.h
	gcc -c learq.c -o learq.o  -lm -fstack-protector-all   -std=c99 -g

list.o: list.c list.h
	gcc -c list.c -o list.o  -lm -fstack-protector-all   -std=c99 -g

quadra.o: quadra.c quadra.h
	gcc -c quadra.c -o quadra.o -lm  -fstack-protector-all   -std=c99 -g

retangulo.o: retangulo.c retangulo.h
	gcc -c retangulo.c -o retangulo.o  -lm -fstack-protector-all   -std=c99 -g

semaforo.o: semaforo.c semaforo.h
	gcc -c semaforo.c -o semaforo.o -lm  -fstack-protector-all   -std=c99 -g

torre.o: torre.c torre.h
	gcc -c torre.c -o torre.o -lm  -fstack-protector-all   -std=c99 -g

main.o: main.c
	gcc -c main.c -o main.o  -lm -fstack-protector-all   -std=c99 -g
	
clean:
	rm -rf *.o