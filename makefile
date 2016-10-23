all : cnode.o vcnode.o funhash.o CMd5.o main

CMd5.o : CMd5.cpp CMd5.h
	g++ -c CMd5.cpp -o CMd5.o -g
cnode.o : cnode.cpp cnode.h
	g++ -c cnode.cpp -o cnode.o -g 
vcnode.o : vcnode.cpp vnode.h
	g++ -c vcnode.cpp -o vcnode.o -g 
funhash.o : funhash.cpp funhash.h 
	g++ -c funhash.cpp  -o funhash.o -g 
main : main.cpp cnode.o vcnode.o funhash.o CMd5.o 
	g++ cnode.o vcnode.o funhash.o CMd5.o main.cpp -o main -g 

clean :
	rm *.o main

