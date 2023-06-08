#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "film.h"
#include "string5.h"

class ListItem{
public:
    Film* film_data;
    ListItem* next;

    ListItem():film_data(NULL), next(NULL){
    }
    ListItem(Film* data):film_data(data), next(NULL){}
    ListItem(ListItem& rhs);
    void printData(){
        film_data->filmInfo();
    }
    ~ListItem(){
        delete film_data;
    }
};

class FilmList{
    ListItem* head;
    size_t num_of_films;
public:
    FilmList(): num_of_films(0){
        head = NULL;
    }
    void loadFilms();
    bool exportFilms();
    bool filmExists(String title);
    void insertElement(ListItem* data);
    void printFilms();
    void deleteElement(String title);
    void searchFilm(String title);
    size_t getLength(){
        return num_of_films;
    }
    ~FilmList();
};


#endif // LINKEDLIST_H_INCLUDED
