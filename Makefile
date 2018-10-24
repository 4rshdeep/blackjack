SRC = main.cpp

all: $(SRC)
	g++ --std=c++11 -o blackJack.out $(SRC)

debug: $(SRC)
	  g++ -g --std=c++11 -O3 -o blackJack.out $(SRC)

warnings: $(SRC)
	  g++ -g --std=c++11 -Wall -Wextra -O3 -o blackJack.out $(SRC)

clean:
	rm -rf *.out
