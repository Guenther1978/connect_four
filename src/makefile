CXX = g++
libs = -lncurses

connect_four : connect_four.o graphics.o player.o playing_field.o
	$(CXX) -o connect_four connect_four.o graphics.o player.o \
	playing_field.o $(libs)

connect_four.0 : connect_four.cpp consants.hpp graphics.hpp player.hpp \
	playing_field.hpp 
	$(CXX) -c connect_four.cpp
graphics.o : graphics.cpp graphics.hpp
	$(CXX) -c graphics.cpp
player.o : player.cpp player.hpp playing_field.hpp
	$(CXX) -c player.cpp
playing_field.o : playing_field.cpp playing_field.hpp
	$(CXX) -c playing_field.cpp

clean :
	rm connect_four *.o
