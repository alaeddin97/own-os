
output: main.o message.o
	g++ main.o message.o -o $@

main.o: main.cpp
	g++ -c $<

message.o: message.cpp message.h
	g++ -c message.cpp
	
clean:
	rm *.o output
