bin/scheck : bin/main.o bin/parser.o bin/csvreporter.o
	g++ bin/main.o bin/parser.o bin/csvreporter.o -o bin/scheck

bin/parser.o : src/parser.cpp inc/parser.h inc/error.h 
	g++ -I inc -c src/parser.cpp -o bin/parser.o

bin/main.o : src/main.cpp inc/parser.h inc/error.h inc/dictionary.h inc/csvreporter.h
	g++ -I inc -c src/main.cpp -o bin/main.o

bin/csvreporter.o : src/csvreporter.cpp inc/csvreporter.h inc/reporter.h
	g++ -I inc -c src/csvreporter.cpp -o bin/csvreporter.o