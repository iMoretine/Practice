Demo.out: Acount.o Chapt10.1.o
	g++ -o Demo.out Acount.o Chapt10.1.o

Acount.o: Acount.cpp Acount.h
	g++ -c Acount.cpp

Chapt10.1.o: Chapt10.1.cpp Acount.h
	g++ -c Chapt10.1.cpp

clean:
	rm ./*.o
