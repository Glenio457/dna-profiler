all: bin/dna_profiler

bin/dna_profiler: bin/main.o bin/analisador.o bin/comparador.o bin/leitorcsv.o bin/leitortxt.o
	mkdir -p bin
	g++ -o bin/dna_profiler bin/main.o bin/analisador.o bin/comparador.o bin/leitorcsv.o bin/leitortxt.o

bin/main.o: src/main.cpp include/comparador.h include/analisador.h include/leitorcsv.h include/leitortxt.h
	mkdir -p bin
	g++ -c src/main.cpp -o bin/main.o

bin/analisador.o: src/analisador.cpp include/analisador.h
	mkdir -p bin
	g++ -c src/analisador.cpp -o bin/analisador.o

bin/comparador.o: src/comparador.cpp include/comparador.h
	mkdir -p bin
	g++ -c src/comparador.cpp -o bin/comparador.o

bin/leitorcsv.o: src/leitorcsv.cpp include/leitorcsv.h
	mkdir -p bin
	g++ -c src/leitorcsv.cpp -o bin/leitorcsv.o

bin/leitortxt.o: src/leitortxt.cpp include/leitortxt.h
	mkdir -p bin
	g++ -c src/leitortxt.cpp -o bin/leitortxt.o

clean:
	rm -rf bin
