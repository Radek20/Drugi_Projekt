main: main.cpp test.cpp test.h tens.h tensor.h
	g++ main.cpp test.cpp
clean:
	rm a.out
start:
	./a.out

