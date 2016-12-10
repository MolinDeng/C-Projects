all: pdadd pdlist pdshow pdremove
.PHONY: all

pdadd: pdadd.o Dairy.o
	g++ pdadd.o Dairy.o -o pdadd
pdlist: pdlist.o Dairy.o
	g++ pdlist.o Dairy.o -o pdlist
pdshow: pdshow.o Dairy.o
	g++ pdshow.o Dairy.o -o pdshow
pdremove: pdremove.o Dairy.o
	g++ pdremove.o Dairy.o -o pdremove
	
pdadd.o: pdadd.cpp Dairy.h
	g++ -c pdadd.cpp
pdlist.o: pdlist.cpp Dairy.h
	g++ -c pdlist.cpp
pdshow.o: pdshow.cpp Dairy.h
	g++ -c pdshow.cpp
pdremove.o: pdremove.cpp Dairy.h
	g++ -c pdremove.cpp
Dairy.o: Dairy.cpp Dairy.h
	g++ -c Dairy.cpp

clean:
	del all *.o