#ifndef CLIENT_H
#define CLIENT_H

#include "defs.h"
#include "AlbumArray.h"
#include "PhotoGram.h"
#include <iostream>
#include <string>

using namespace std;

class Client{
    public:
        Client();
        ~Client();
        bool downloadAlbum(const PhotoGram*, const string&) const;
        bool displayOnlinePhoto(const PhotoGram*, const string&, const string&) const;
        bool displayLocalPhoto(const string&, const string&) const;
        void printLocalAlbums() const;
        void displayLocalAlbums() const;
    private:
        AlbumArray* albumArray;
};
#endif