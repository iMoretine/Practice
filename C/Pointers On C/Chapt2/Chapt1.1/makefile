Demo.out:negate.o Chapt1.1.o increaments.o
	gcc -o Demo.out negate.o Chapt1.1.o increaments.o

negate.o : negate.c negate.h
	gcc -c negate.c

Chapt1.1.o : Chapt1.1.c negate.h increaments.h
	gcc -c Chapt1.1.c

increaments.o : increaments.c increaments.h
	gcc -c increaments.c

clean:
	rm ./*.o
