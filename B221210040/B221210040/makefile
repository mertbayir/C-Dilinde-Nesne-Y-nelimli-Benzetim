all: compile run

compile:
	gcc -I ./include/ -o ./lib/bitki.o -c ./src/bitki.c
	gcc -I ./include/ -o ./lib/bocek.o -c ./src/bocek.c
	gcc -I ./include/ -o ./lib/canli.o -c ./src/canli.c
	gcc -I ./include/ -o ./lib/habitat.o -c ./src/habitat.c
	gcc -I ./include/ -o ./lib/pire.o -c ./src/pire.c
	gcc -I ./include/ -o ./lib/sinek.o -c ./src/sinek.c
	gcc -I ./include/ -o ./bin/test ./lib/bitki.o ./lib/bocek.o ./lib/canli.o ./lib/habitat.o ./lib/pire.o ./lib/sinek.o ./src/test.c

run:
	./bin/test