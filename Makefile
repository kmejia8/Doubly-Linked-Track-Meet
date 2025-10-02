#-----------------------------------------------------------------------------
# Author: Karla Mejia
# Simple Makefile for Doubly Linked List Project

# This code is provided here solely for educational and portfolio purposes.  
# No permission is granted to copy, modify, or redistribute this code.  
#-----------------------------------------------------------------------------


# compiles the program with gcc
all:
	gcc -g -o DoublyTrackMeet DoublyTrackMeet.c

# runs the compiled program
run:
	./DoublyTrackMeet

# removes the compiled binary
clean:
	rm -f DoublyTrackMeet