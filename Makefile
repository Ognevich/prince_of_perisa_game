CC = gcc

CFLAGS = -I src/include -Wall -g

LDFLAGS = -L src/lib -lSDL3

SRC = main.c \
      game/game.c \
      game/player/player.c \
      graphics/renderer.c \
      input/input.c \
      platform/sdl.c \
	  game/static_objects/objects.c \
	  game/scene/scene.c \
        game/collisions/collisions.c

TARGET = main.exe   

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	del /F /Q $(TARGET)   # для Windows використовується del