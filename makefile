all: travesty

travesty: travesty.o digester.o
	g++ -Wall -o travesty travesty.o digester.o

travesty.o: travesty.cpp digester.h
	g++ -Wall -c travesty.cpp digester.h

digester.o: digester.cpp digester.h
	g++ -Wall -c digester.cpp digester.h

clean:
	rm *.o *.h.gch travesty
