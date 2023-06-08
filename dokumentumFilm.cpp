#include "dokumentumFilm.h"
#include <iostream>

using std::cout;
using std::cin;
using std::to_string;
void Documentary::beolvas(){
    char c;

    String filmTitle;
    String filmDescription;
    int length_of_film;
    int year_of_pub;

    cout << "Adja meg a film cimet: ";
    cin.get();
    while(c != '\n'){
        filmTitle = filmTitle + c;
        cin.get(c);
    }
    c = '.';
    cout << "Adja meg a film leirasat: ";

    while(c != '\n'){
        cin.get(c);
        if(c != '\n'){
            filmDescription = filmDescription + c;
        }

    }

    cout << "Adja meg a film hosszat percben: ";
    cin >> length_of_film;

    cout << "Adja meg a film megjelenesi evet: ";
    cin >> year_of_pub;

    this->title = filmTitle;
    this->length = length_of_film;
    this->year = year_of_pub;
    this->description = filmDescription;

}
String Documentary::film_data(){
    String adat("2;");
    adat = adat + title + ';';
    adat = adat + description + ';';
    adat = adat + to_string(length).data() + ';';
    adat = adat + to_string(year).data() + ";\n";

    return adat;
}

