#ifndef CSALADIFILM_H_INCLUDED
#define CSALADIFILM_H_INCLUDED
#include "film.h"

class FamilyFilm: public Film{
protected:
    int ageLimit;
public:
    FamilyFilm(String film_title="", int film_len=0, int year_of_pub=0, int limit=0): Film(film_title, film_len, year_of_pub), ageLimit(limit){}
    FamilyFilm(const FamilyFilm& f): Film(f.title, f.length, f.year), ageLimit(f.ageLimit){}
    void beolvas();
    void filmInfo(){
         std::cout << "Csaladi: " << title << " " << length << " " << year << " " << ageLimit <<std::endl;
    }
    String film_data();
    int getLimit(){ return ageLimit; }
};

#endif // CSALADIFILM_H_INCLUDED
