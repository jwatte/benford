
benford:	benford.cpp
	g++ -g -Wall -o benford -O1 benford.cpp
	./benford

clean:
	rm -f *.o a.out core benford
