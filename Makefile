CC=g++
CFLAGS=-c -std=c++11 -I.

all: SignSimilMain LSHMain JsimMain permutateDoc

SignSimilMain: SignSimilMain.o SignSimil.o kShingleGen.o
	$(CC) -o SignSimilMain SignSimilMain.o SignSimil.o kShingleGen.o

SignSimilMain.o: SignSimilMain.cc SignSimil.h
	$(CC) $(CFLAGS) SignSimilMain.cc

SignSimil.o: SignSimil.cc SignSimil.h Jsim.h kShingleGen.h
	$(CC) $(CFLAGS) SignSimil.cc

LSHMain: LSHMain.o LSH.o SignSimil.o kShingleGen.o Jsim.o
	$(CC) -o LSHMain LSHMain.o LSH.o SignSimil.o Jsim.o kShingleGen.o

LSHMain.o: LSHMain.cpp LSH.h SignSimil.h Jsim.h kShingleGen.h
	$(CC) $(CFLAGS) LSHMain.cpp

LSH.o: LSH.cpp LSH.h SignSimil.h Jsim.h kShingleGen.h
	$(CC) $(CFLAGS) LSH.cpp

JsimMain: JsimMain.o Jsim.o kShingleGen.o
	$(CC) -o JsimMain JsimMain.o Jsim.o kShingleGen.o

JsimMain.o: JsimMain.cpp Jsim.h kShingleGen.h
	$(CC) $(CFLAGS) JsimMain.cpp

Jsim.o: Jsim.cpp Jsim.h kShingleGen.h
	$(CC) $(CFLAGS) Jsim.cpp -c

kShingleGen.o: kShingleGen.cpp kShingleGen.h
	$(CC) $(CFLAGS) kShingleGen.cpp -c

permutateDoc: permutateDoc.o
	$(CC) -o permutateDoc permutateDoc.o

permutateDoc.o: permutateDoc.cpp
	$(CC) $(CFLAGS) permutateDoc.cpp












clean:
	rm *.o
	rm SignSimilMain
	rm LSHMain
	rm JsimMain



