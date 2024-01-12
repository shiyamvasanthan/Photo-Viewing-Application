#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H

#include "defs.h"
#include "AlbumArray.h"
#include <iostream>
#include <string>

using namespace std;

class PhotoGram{
    public:
        PhotoGram();
        ~PhotoGram();
        bool addAlbum(const string&, const string&);
        bool removeAlbum(const string&);
        bool addPhoto(const string&, const Photo&);
        bool removePhoto(const string&, const string&);
        Album* downloadAlbum(const string&) const;
        Photo* downloadPhoto(const string&, const string&) const;
        void printAlbums() const;
        void displayAlbums() const;
    private:
        AlbumArray* albumArray;
};
#endif