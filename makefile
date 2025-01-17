dna_profiler: main.o analisador.o comparador.o leitorcsv.o leitortxt.o
	g++ -o dna_profiler main.o analisador.o comparador.o leitorcsv.o leitortxt.o

main.o: src/main.cpp include/comparador.h include/analisador.h include/leitorcsv.h include/leitortxt.h
	g++ -c src/main.cpp

analisador.o: src/analisador.cpp include/analisador.h
	g++ -c src/analisador.cpp

comparador.o: src/comparador.cpp include/comparador.h
	g++ -c src/comparador.cpp

leitorcsv.o: src/leitorcsv.cpp include/leitorcsv.h
	g++ -c src/leitorcsv.cpp

leitortxt.o: src/leitortxt.cpp include/leitortxt.h
	g++ -c src/leitortxt.cpp

clean:dna_profiler
	rm -f dna_profiler *.o