all: a2

a2: Album.o AlbumArray.o Client.o Date.o main.o Photo.o PhotoArray.o PhotoGram.o TestControl.o TestView.o
	g++ -o a2 Album.o AlbumArray.o Client.o Date.o main.o Photo.o PhotoArray.o PhotoGram.o TestControl.o TestView.o
	
Album.o: Album.h Album.cc 
	g++ -c Album.cc 

AlbumArray.o: AlbumArray.h AlbumArray.cc 
	g++ -c AlbumArray.cc 

Client.o: Client.h Client.cc 
	g++ -c Client.cc 

Date.o:	Date.h Date.cc
	g++ -c Date.cc

main.o: main.cc TestControl.h
	g++ -c main.cc
	
Photo.o: Photo.h Photo.cc
	g++ -c Photo.cc

PhotoArray.o: PhotoArray.cc PhotoArray.h
	g++ -c PhotoArray.cc

PhotoGram.o: PhotoGram.cc PhotoGram.h
	g++ -c PhotoGram.cc	

TestControl.o: TestControl.cc TestControl.h TestView.h Client.h
	g++ -c TestControl.cc

TestView.o: TestView.cc TestView.h
	g++ -c TestView.cc

clean:
	rm -f a2 *.o