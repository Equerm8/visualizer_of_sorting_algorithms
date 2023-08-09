all:
	g++ -lm -I src/include -L src/lib -o main main.cpp sdl2Functions.cpp sdl2Functions.hpp sortAlgorithms.cpp sortAlgorithms.hpp -lmingw32 -lSDL2main -lSDL2
	
clean:
	rm *.o output