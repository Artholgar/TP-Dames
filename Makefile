CC=gcc
EXEC=Dame
CFLAGS=-Wall -pedantic
LDFLAGS=-lncurses -lm
OBJ=./Main.o ./Event.o ./Affichage.o ./Cases.o ./Position.o ./Reso.o ./Test.o

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

./Main.o: ./include/Event.h ./include/Affichage.h ./include/Cases.h ./include/Position.h ./include/Reso.h ./include/Test.h

./Event.o: ./include/Event.h ./include/Affichage.h ./include/Cases.h ./include/Position.h ./include/Reso.h

./Affichage.o: ./include/Affichage.h ./include/Cases.h ./include/Position.h

./Cases.o: ./include/Cases.h ./include/Position.h

./Position.o: ./include/Position.h

./Reso.o: ./include/Cases.h ./include/Position.h ./include/Reso.h

./Test.o: ./include/Event.h ./include/Affichage.h ./include/Cases.h ./include/Position.h ./include/Reso.h ./include/Test.h

./%.o: ./src/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f ./*.o

mrproper: clean
	rm -f $(EXEC)

install: $(EXEC)
	mkdir ./bin
	mv $(EXEC) ./bin/
	mv *.o ./bin/
	make mrproper

uninstall: mrproper
	rm -f ./bin/$(EXEC)
	rm -f ./bin/*.o
	rm -rf ./bin