all:	./bin/tsp
./bin/tsp:	./obj/nearest.o
	g++ ./obj/nearest.o -o  ./bin/tsp
./obj/nearest.o:	./src/trial.cpp
	g++ -c ./src/trial.cpp -o ./obj/nearest.o
clean:
	rm -fr bin/* obj/*
build:
	make clean
	make
run:
	make clean
	make
	./bin/tsp
