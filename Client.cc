#include "Client.h"

Client::Client(){
    this->albumArray = new AlbumArray;
}

Client::~Client(){
    for(int i = 0; i < albumArray->size(); i++){
        delete albumArray->get(i);
    }
    delete albumArray;
}

bool Client::downloadAlbum(const PhotoGram* pg, const string& albumTitle) const{
    Album* album = pg->downloadAlbum(albumTitle);

    if(album == NULL) return false;

    Album* albumCopy = new Album(*album);

    if(albumArray->add(albumCopy)){
        return true;
    }

    delete albumCopy;
    return false;
}

bool Client::displayOnlinePhoto(const PhotoGram* pg, const string& albumTitle, const string& photoTitle) const{
    Album* album = pg->downloadAlbum(albumTitle);

    if(album == NULL) return false;

    Photo* photo = album->getPhoto(photoTitle);

    if(photo == NULL) return false;

    photo->display();
    return true;
}

bool Client::displayLocalPhoto(const string& albumTitle, const string& photoTitle) const{
    Album* album = albumArray->get(albumTitle);

    if(album == NULL) return false;

    Photo* photo = album->getPhoto(photoTitle);

    if(photo == NULL) return false;

    photo->display();
    return true;
}

void Client::printLocalAlbums() const{
    for(int i = 0; i < albumArray->size(); i++){
        albumArray->get(i)->print();
    }
}

void Client::displayLocalAlbums() const{
    for(int i = 0; i < albumArray->size(); i++){
        albumArray->get(i)->display();
    }
}