CC = g++
CFLAGS = -g -Wall -std=c++17


TARGET = MakePage.exe



all: $(TARGET)

$(TARGET): Main.o FileLoader.o HtmlMaker.o
	$(CC) $(CFLAGS) -o ../$(TARGET) Main.o FileLoader.o HtmlMaker.o

Main.o: Main.cpp
	$(CC) $(CFLAGS) -o Main.o -c Main.cpp

FileLoader.o: FileLoader.cpp FileLoader.h
	$(CC) $(CFLAGS) -o FileLoader.o -c FileLoader.cpp

HtmlMaker.o: HtmlMaker.cpp HtmlMaker.h
	$(CC) $(CFLAGS) -o HtmlMaker.o -c HtmlMaker.cpp

clean:
	-rm *.o 
	-rm $(TARGET)