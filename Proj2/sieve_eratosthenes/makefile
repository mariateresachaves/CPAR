SRC = $(wildcard src/*.cpp)

OBJ = $(patsubst src%, ./tmp%.o, $(SRC))

OUT = bin/sieve_eratosthenes

# include directories
INCLUDES = -I./src -I/opt/papi/include

# compiler
CC = mpic++ -std=c++14

# library paths
LIBS = -L/opt/papi/lib -lpapi

# flags
FLAGS = -O3 -s -Wall -Wdisabled-optimization -fopenmp

.SUFFIXES: .cpp

./tmp/%.o: src/%
	mkdir -p ./tmp
	$(CC) $(INCLUDES) -c $< -o $@ $(FLAGS)

$(OUT): $(OBJ)
	mkdir -p bin
	$(CC) $(INCLUDES) $(OBJ) $(LIBS) -o $(OUT) $(FLAGS)

clean:
	rm -f $(OBJ) $(OUT)
