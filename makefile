objects = image.o main.o map.o screen.o actor.o game.o program.o

game.exe : $(objects)
	g++ -o game.exe $(objects)

image.o : image.h
main.o : screen.h image.h
map.o : map.h
screen.o : screen.h
actor.o : actor.h image.h
game.o : game.h
program.o : game.h

clean :
	del $(objects)