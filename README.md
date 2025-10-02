# Doubly Linked List – Runner Management (C)

A C program that implements a doubly linked list to manage information about runners in a track meet.  
Each node in the list represents a runner and stores lane, bib number, name, school, qualifying time, and personal record.  
The project demonstrates dynamic memory allocation, insertion, removal, and traversal of a linked data structure.  

---

## Features
- **Custom Data Structure:** Doubly linked list storing runner information  
- **Insertion:** Add new runners either at the head of the list or after a specified node  
- **Removal:** Remove any runner from the list and free allocated memory  
- **Traversal:** Print all runners in the current list, displaying their details in order  

---

## Implementation Details
- Written in C with `malloc`/`free` for dynamic memory management  
- Uses pointers to link `previous` and `next` nodes  
- Encapsulates list operations into reusable functions:  
  - `insert_entry` – handles adding a new runner  
  - `remove_entry` – removes a runner and updates list pointers  
  - `print_entries` – iterates through the list to display details  

---

## Build
Make sure the `Makefile` or source file is in the same directory, then run:
```bash
gcc -g -o DoublyTrackMeet DoublyTrackMeet.c
