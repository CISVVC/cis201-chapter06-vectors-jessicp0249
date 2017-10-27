#
all: main


main : 
	@echo "Making the executable -- some warnings can be safely ignored"
	@g++ -o main *.cpp 

run : main
	@echo "Running the program:"
	@./main

edit:
	@vim main.cpp

debug:
	@gdb ./main

clean :
	@rm main
