#ifndef ALBUMARRAY_H
#define ALBUMARRAY_H

#include "defs.h"
#include "Album.h"
#include <iostream>
#include <string>

using namespace std;

class AlbumArray{
    public:
        AlbumArray();
        ~AlbumArray();
        bool isFull() const;
        bool add(Album*);
        Album* get(const string&) const;
        Album* get(int) const;
        Album* remove(const string&);
        Album* remove(int);
        int size() const;
    private:
        Album** albumPtrs;
        int numAlbums;
};
#endif