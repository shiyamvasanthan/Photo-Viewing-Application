#ifndef PHOTO_H
#define PHOTO_H

#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

class Photo{
    public:
        Photo(const string&, const Date&, const string&);
        Photo(const Photo&);
        bool equals(const string&) const;
        void print() const;
        void display() const;
    private:
        string title;
        string content;
        Date date;
};
#endif