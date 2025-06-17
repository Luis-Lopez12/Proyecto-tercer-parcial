CXX = g++
CXXFLAGS = -std=c++11 -Iinclude
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SRC = src/main.cpp src/Juego.cpp src/Tablero.cpp src/Celda.cpp src/Jugador.cpp src/Interfaz.cpp
BIN = bin/buscaminas.exe

all: $(BIN)

$(BIN): $(SRC)
	@if not exist bin mkdir bin
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BIN) $(LDFLAGS)

run: all
	$(BIN)

clean:
	@if exist bin rmdir /s /q bin
	rm -rf bin *.o
