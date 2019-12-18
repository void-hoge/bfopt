CC = g++
STD = -std=c++17
OPTIM = -O3 -flto -mtune=native -march=native
PROGRAM = bf

$(PROGRAM).out: main.o interpreter.o
	$(CC) main.o interpreter.o $(STD) $(OPTIM) -o $(PROGRAM).out

main.o: main.cpp
	$(CC) main.cpp $(STD) $(OPTIM) -c -o main.o

interpreter.o: interpreter.cpp
	$(CC) interpreter.cpp $(STD) $(OPTIM) -c -o interpreter.o

clean:
	rm *.out
	rm *.o

run:
	./$(PROGRAM).out hello.bf
