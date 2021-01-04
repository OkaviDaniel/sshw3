CC = gcc
FLAGS = -Wall -g
OBJECTSORT = insertionSort.o
OBJECTFIND = txtfind.o
MAINSORT = main_isort.o
MAINFIND = main_txtfind.o

all: isort $(MAINSORT) $(OBJECTSORT) txtfind $(MAINFIND) txtfind.o

txtfind: $(MAINFIND) $(OBJECTFIND)
	$(CC) $(MAINFIND) $(OBJECTFIND) -o txtfind

isort: $(MAINSORT) $(OBJECTSORT)
	$(CC) $(MAINSORT) $(OBJECTSORT) -o isort

$(OBJECTFIND): txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c -o $(OBJECTFIND)

$(MAINFIND): main_txtfind.c txtfind.h
	$(CC) $(FLAGS) -c main_txtfind.c -o $(MAINFIND)

$(OBJECTSORT): insertionSort.c insertionSort.h
	$(CC) $(FLAGS) -c insertionSort.c -o $(OBJECTSORT)

$(MAINSORT): main_isort.c insertionSort.h
	$(CC) $(FLAGS) -c main_isort.c -o $(MAINSORT)

clean:
	rm -f txtfind isort *.o