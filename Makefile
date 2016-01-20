CC = g++
SDL2 = `sdl2-config --cflags`
LIBS = -lSDL2 -lSDL2_image
OUTPUT = game

all:
	$(CC) -std=c++11 $(SDL2) $(LIBS) -O3 -o $(OUTPUT) main.cpp

run:
	make
	./$(OUTPUT)

clean:
	rm -fv $(OUTPUT)
