Name: Shiyam Vasanthan

Program Files:
Date.h - Stores the date class function protoypes and data members like day, month, and year
Date.cc - Allows the user to increment dates, compare dates, set dates, and print out the date
Album.h - Stores album class function prototypes and data members like title, description, photoarray
Album.cc - Allows user to add, get, remove photos
AlbumArray.h - Stores albumArray class function prototypes and data members like array of albums
AlbumArray.cc - Allows user to add, get, remove albums
Client.h - Stores client class function prototypes and data member like array of albums
Client.cc - Allows user to download albums, display online and local photos, print and display online and local albums
Photo.h - Stores photo class function prototypes and data members like title, content, date
Photo.cc - Allows user to print, display, and compare photos
PhotoArray.h - Stores photoarray class function prototypes and data members like array of photos
PhotoArray.cc - Allows user to add, get, remove from array of photos
PhotoGram.h - Stores the photogram function prototypes and data member like array of albums
PhotoGram.cc - Allows user to add and remove albums, add and remove photos, download albums and photos, print and display albums
TestControl.h, TestControl.cc, TestView.h, TestView.cc - Tests all the classes
main.cc - Used to test all the functions to see if they work correctly
Makefile - Used to compile all the files into one executable
defs.h - Provides some predefined constant for the max array size

Compilation Instructions:
1. Type "make" in the terminal
2. Type "./a2" in the terminal to execute the program
3. Type Options from "0" through "5" to test different classes or exit the program
4. Type "valgrind ./a2" in the terminal to execute program using valgrind. When done check to see there's no memory leaks
5. Type "make clean" in the terminal to clean all the object files and the executable
