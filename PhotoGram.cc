#include "PhotoGram.h"

PhotoGram::PhotoGram(){
    this->albumArray = new AlbumArray;
}

PhotoGram::~PhotoGram(){
    for(int i = 0; i < albumArray->size(); i++){
        delete albumArray->get(i);
    }
    delete albumArray;
}

bool PhotoGram::addAlbum(const string& title, const string& description){
    if(albumArray->add(new Album(title, description))){
        return true;
    }

    cout << "Album could not be added to the photogram!" << endl;
    return false;
}

bool PhotoGram::removeAlbum(const string& title){
    Album* album = albumArray->remove(title);

    if(album == NULL) {
        cout << "No album with this title exists!" << endl;
        return false;
    }
    
    delete album;
    return true;
}

bool PhotoGram::addPhoto(const string& albumTitle, const Photo& photo){
    Album* album = albumArray->get(albumTitle);

    if(album == NULL) {
        cout << "No album with this title exists!" << endl;
        return false;
    }

    Photo* photoCopy = new Photo(photo);

    if(album->addPhoto(photoCopy)){
        return true;
    }

    cout << "Photo could not be added to the photogram!" << endl;
    return false;
}

bool PhotoGram::removePhoto(const string& albumTitle, const string& photoTitle){
    Album* album = albumArray->get(albumTitle);

    if(album == NULL) {
        cout << "No album with this title exists!" << endl;
        return false;
    }
    
    Photo* removedPhoto = album->removePhoto(photoTitle);

    if(removedPhoto == NULL) {
        cout << "No photo with this title exists!" << endl;
        return false;
    }

    delete removedPhoto;
    return true;
}

Album* PhotoGram::downloadAlbum(const string& albumTitle) const{
    return albumArray->get(albumTitle);
}

Photo* PhotoGram::downloadPhoto(const string& albumTitle, const string& photoTitle) const{
    Album* album = albumArray->get(albumTitle);

    if(album == NULL) {
        cout << "No album with this title exists!" << endl;
        return NULL;
    }

    return album->getPhoto(photoTitle);
}

void PhotoGram::printAlbums() const{
    for(int i = 0; i < albumArray->size(); i++){
        albumArray->get(i)->print();
    }
}

void PhotoGram::displayAlbums() const{
    for(int i = 0; i < albumArray->size(); i++){
        albumArray->get(i)->display();
    }
}
