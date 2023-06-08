#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED

#include <iostream>
#include "string5.h"
class Film{
protected:
    String title;
    int length;
    int year;

public:

    Film(String film_title="", int film_len=0, int year_of_pub=0): title(film_title), length(film_len), year(year_of_pub){}
    Film(const Film& f): title(f.title), length(f.length), year(f.year){}
    virtual ~Film(){}
    virtual void beolvas();
    virtual void filmInfo(){
        std::cout << title << " " << length << " " << year << std::endl;
    }
    virtual String film_data();
    int getLength() const { return length; }
    String getTitle() const { return title; }
    int getYear() const { return year; }
};


#endif // FILM_H_INCLUDED
