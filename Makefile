# all the files
FILES = main.cc Renderer.cc Window.cc

# compiler
CC = g++

# link the libraries
LINK = -lSDL2 -lSDL2_image -lSDL2_ttf

# executable name
OUT = ProTyper

all : $(FILES)
	$(CC) $(FILES) $(LINK) -o $(OUT) -g
