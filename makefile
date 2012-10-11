all: travesty

travesty: travesty.o
	g++ -Wall -o travesty travesty.o

travesty.o: travesty.cpp
	g++ -Wall -c travesty.cpp

clean:
	rm *.o *.h.gch travesty
