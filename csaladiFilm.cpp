#include "csaladiFilm.h"
#include <iostream>

using std::cout;
using std::cin;
using std::to_string;
void FamilyFilm::beolvas(){
    char c;

    String filmTitle;
    int age_limit;
    int length_of_film;
    int year_of_pub;

    cout << "Adja meg a film cimet: ";
    cin.get();
    while(c != '\n'){
        filmTitle = filmTitle + c;
        cin.get(c);
    }

    cout << "Adja meg a film hosszat percben: ";
    cin >> length_of_film;

    cout << "Adja meg a film megjelenesi evet: ";
    cin >> year_of_pub;

    cout << "Adja meg a film korhatarat: ";
    cin >> age_limit;

    this->title = filmTitle;
    this->length = length_of_film;
    this->year = year_of_pub;
    this->ageLimit = age_limit;

}
String FamilyFilm::film_data(){
    String adat("3;");
    adat = adat + title + ';';
    adat = adat + to_string(length).data() + ';';
    adat = adat + to_string(year).data() + ';';
    adat = adat + to_string(ageLimit).data() + ";\n";

    return adat;
}
