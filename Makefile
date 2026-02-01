CC = gcc

CFLAGS = -I src/include -Wall -g

LDFLAGS = -L src/lib -lSDL3

SRC = main.c core/gameControler.c game/game.c graphics/renderer.c input/input.c platform/sdl.c  
TARGET = main.exe   

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	del /F /Q $(TARGET)   # для Windows використовується del