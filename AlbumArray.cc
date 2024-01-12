#include "AlbumArray.h"

AlbumArray::AlbumArray(){
    this->numAlbums = 0;
    this->albumPtrs = new Album*[MAX_ARRAY];
}

AlbumArray::~AlbumArray(){
    delete[] albumPtrs;
}

bool AlbumArray::isFull() const{
    return numAlbums >= MAX_ARRAY;
}

bool AlbumArray::add(Album* album){
    if(isFull()) return false;

    for (int i = numAlbums; i > 0 ; --i){
        if (album->lessThan(*albumPtrs[i-1])){
            //keep making space by copying elements
            //one location to the right
            albumPtrs[i]=albumPtrs[i-1];
        }else{
            //we have found where s should go
            albumPtrs[i] = album;
            ++numAlbums;
            return true;
        }
    }

    //we went through every location, and s was less than 
    //all of them. Therefore s goes in location 0
    albumPtrs[0] = album;
    ++numAlbums;
    return true;
}

Album* AlbumArray::get(const string& title) const{
    for(int i = 0; i < numAlbums; i++){
        if(albumPtrs[i]->equals(title)){
            return albumPtrs[i];
        }
    }

    return NULL;
}

Album* AlbumArray::get(int index) const{
    if(index < 0 || index >= numAlbums) return NULL;

    return albumPtrs[index];
}

Album* AlbumArray::remove(const string& title){
    int index = 0;

    while(!albumPtrs[index]->equals(title) && index < numAlbums){
        ++index;
    }

    if (index == numAlbums) return NULL;

    Album* removedAlbum = albumPtrs[index];

    while(index < numAlbums - 1){
        albumPtrs[index] = albumPtrs[index + 1];
        index++;
    }

    --numAlbums;

    return removedAlbum;
}

Album* AlbumArray::remove(int index){
    if(index < 0 || index >= numAlbums) return NULL;

    Album* removedAlbum = albumPtrs[index];

    while(index < numAlbums - 1){
        albumPtrs[index] = albumPtrs[index + 1];
        index++;
    }

    --numAlbums;

    return removedAlbum;
}

int AlbumArray::size() const{
    return numAlbums;
}