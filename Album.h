#ifndef ALBUM_H
#define ALBUM_H

#include "defs.h"
#include "PhotoArray.h"
#include <iostream>
#include <string>

using namespace std;

class Album{
    public:
        Album(const string&, const string&);
        Album(const Album&);
        ~Album();
        string getTitle() const;
        bool equals(const string&) const;
        bool lessThan(const Album&) const;
        bool addPhoto(Photo*);
        bool addPhoto(int, Photo*);
        Photo* getPhoto(const string&) const;
        Photo* getPhoto(int) const;
        Photo* removePhoto(const string&);
        Photo* removePhoto(int);
        int size() const;
        void print() const;
        void display() const;
    private:
        string title;
        string description;
        PhotoArray* photoArray;
};
#endif