all: problema1 problema2

problema1: problema1.cpp
	g++ -o problema1 problema1.cpp

problema2: problema2.cpp
	g++ -o problema2 problema2.cpp

clean:
	rm -f problema1 problema2

