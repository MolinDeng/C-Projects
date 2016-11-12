studentrecords:main.o Student.o
	g++ main.o Student.o -o studentrecords

main.o:main.cpp Student.h
	g++ -c main.cpp

Student.o:Student.cpp Student.h
	g++ -c Student.cpp

.PHONY:clean
clean:
	rm studentrecords main.o Student.h
