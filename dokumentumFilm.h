#ifndef DOKUMENTUMFILM_H_INCLUDED
#define DOKUMENTUMFILM_H_INCLUDED

#include "film.h"
class Documentary: public Film{
protected:
    String description;
public:
    Documentary(String film_title="", String desc = "", int film_len=0, int year_of_pub=0): Film(film_title, film_len, year_of_pub), description(desc){}
    Documentary(const Documentary& d): Film(d.title, d.length, d.year), description(d.description){}
    ~Documentary(){}
    void filmInfo(){
        std::cout << "Doksi: " << title << " " << length << " " << year << " " << description <<std::endl;
    }
    void beolvas();
    String film_data();
    String getDescription() const {
        return description;
    }
};
#endif // DOKUMENTUMFILM_H_INCLUDED
