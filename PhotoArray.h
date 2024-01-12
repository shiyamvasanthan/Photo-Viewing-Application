#ifndef PHOTOARRAY_H
#define PHOTOARRAY_H

#include "defs.h"
#include "Photo.h"
#include <iostream>
#include <string>

using namespace std;

class PhotoArray{
    public:
        PhotoArray();
        PhotoArray(const PhotoArray&);
        ~PhotoArray();
        bool isFull() const;
        bool add(Photo*);
        bool add(int, Photo*);
        Photo* get(const string&) const;
        Photo* get(int) const;
        Photo* remove(const string&);
        Photo* remove(int);
        int size() const;
    private:
        Photo** photoPtrs;
        int numPhotos;
};
#endif