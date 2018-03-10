SRC = $(wildcard src/*.cpp)

OBJ = $(patsubst src%, ./tmp%.o, $(SRC))

OUT = bin/matrixmult

# include directories
INCLUDES = -I./src -I/opt/papi/include

# compiler
CC = g++ -std=c++14

# library paths
LIBS = -L/opt/papi/lib -lpapi

.SUFFIXES: .cpp

./tmp/%.o: src/%
	mkdir -p ./tmp
	$(CC) $(INCLUDES) -c $< -o $@ -O3 -s -Wall -Wdisabled-optimization

$(OUT): $(OBJ)
	mkdir -p bin
	$(CC) $(INCLUDES) $(OBJ) $(LIBS) -o $(OUT) -O3 -s -Wall -Wdisabled-optimization

clean:
	rm -f $(OBJ) $(OUT)
