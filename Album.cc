#include "Album.h"

Album::Album(const string& title, const string& descripion){
    this->title = title;
    this->description = description;
    this->photoArray = new PhotoArray();
}

Album::Album(const Album& album){
    this->title = album.title;
    this->description = album.description;
    PhotoArray* copy = new PhotoArray();
    for(int i = 0; i < album.size(); i++){
        copy->add(new Photo(*album.getPhoto(i)));
    }

    this->photoArray = copy;
}

Album::~Album(){
    delete photoArray;
}

string Album::getTitle() const{
    return title;
}

bool Album::equals(const string& title) const{
    return this->title == title;
}

bool Album::lessThan(const Album& album) const{
    return this->title < album.title;
}

bool Album::addPhoto(Photo* photo){
    return photoArray->add(photo);
}

bool Album::addPhoto(int index, Photo* photo){
    return photoArray->add(index, photo);
}

Photo* Album::getPhoto(const string& title) const{
    return photoArray->get(title);
}

Photo* Album::getPhoto(int index) const{
    return photoArray->get(index);
}

Photo* Album::removePhoto(const string& title){
    return photoArray->remove(title);
}

Photo* Album::removePhoto(int index){
    return photoArray->remove(index);
}

int Album::size() const{
    return photoArray->size();
}   
void Album::print() const{
    cout << "Album Title: " << title << endl;
    cout << "Album Description: " << description << endl;
}

void Album::display() const{
    print();

    for(int i = 0; i < photoArray->size(); i++){
        photoArray->get(i)->display();
    }
}