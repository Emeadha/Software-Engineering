#When calling make all
all:	airport.o clock.o main.o passenger.o plane.o timeManager.o airline.o gate.o flight.o
	g++ -o airline_simulation airport.o clock.o main.o passenger.o plane.o timeManager.o airline.o gate.o flight.o
	echo Compilation is all green to green!

clean:
	rm *.o airline_simulation
	echo All files cleaned
