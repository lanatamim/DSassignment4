.PHONY: all clean

all: A4

A4: main.cpp
	g++ main.cpp -o A4

clean:
	rm -f A4
