#include "Photo.h"

Photo::Photo(const Photo& photo){
    title = photo.title;
    date = photo.date;
    content = photo.content;
}

Photo::Photo(const string& title, const Date& date, const string& content){
    this->title = title;
    this->date = date;
    this->content = content;
}

bool Photo::equals(const string& title) const{
    return this->title == title;
}

void Photo::print() const{
    date.print();
    cout << endl;
    cout << "Photo name is " << title << endl;
}

void Photo::display() const{
    print();
    cout << "Photo content is " << content << endl;
}