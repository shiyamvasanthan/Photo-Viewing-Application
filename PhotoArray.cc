#include "PhotoArray.h"

PhotoArray::PhotoArray(){
    this->numPhotos = 0;
    this->photoPtrs = new Photo*[MAX_ARRAY];
}

PhotoArray::~PhotoArray(){
    for(int i = 0; i < numPhotos; i++){
        delete photoPtrs[i];
    }
    delete[] photoPtrs;
}

bool PhotoArray::isFull() const{
    return numPhotos >= MAX_ARRAY;
}

bool PhotoArray::add(Photo* photo){
    if(isFull()) return false;

    photoPtrs[numPhotos++] = photo;

    return true;
}

bool PhotoArray::add(int index, Photo* photo){
    if(isFull() || index < 0 || index > numPhotos) return false;

    int addIndex = index;

    while(addIndex < numPhotos){
        photoPtrs[addIndex+1] = photoPtrs[addIndex];
        ++addIndex;
    }

    photoPtrs[index] = photo;
    ++numPhotos;
    return true;
}

Photo* PhotoArray::get(const string& title) const{
    for(int i = 0; i < numPhotos; i++){
        if(photoPtrs[i]->equals(title)){
            return photoPtrs[i];
        }
    }

    return NULL;
}

Photo* PhotoArray::get(int index) const{
    if(index < 0 || index >= numPhotos) return NULL;

    return photoPtrs[index];
}

Photo* PhotoArray::remove(const string& title){
    int index = 0;

    while(!photoPtrs[index]->equals(title) && index < numPhotos){
        ++index;
    }

    if (index == numPhotos) return NULL;

    Photo* removedPhoto = photoPtrs[index];

    while(index < numPhotos - 1){
        photoPtrs[index] = photoPtrs[index + 1];
        index++;
    }

    --numPhotos;

    return removedPhoto;
}

Photo* PhotoArray::remove(int index){
    if(index < 0 || index >= numPhotos) return NULL;

    Photo* removedPhoto = photoPtrs[index];

    while(index < numPhotos - 1){
        photoPtrs[index] = photoPtrs[index + 1];
        index++;
    }

    --numPhotos;

    return removedPhoto;
}

int PhotoArray::size() const{
    return numPhotos;
}