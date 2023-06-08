#include "film.h"
#include <iostream>


using std::cout;
using std::cin;
using std::to_string;
void Film::beolvas(){
    char c;
    String filmTitle;
    int length_of_film;
    int year_of_pub;
    cout << "Adja meg a film cimet: ";
    cin.get();
    while(c != '\n'){
        cin.get(c);
        if(c != '\n'){
            filmTitle = filmTitle + c;
        }
    }
    this->title = filmTitle;
    cout << "Adja meg a film hosszat percben: ";
    cin >> length_of_film;
    this->length = length_of_film;
    cout << "Adja meg a film megjelenesi evet: ";
    cin >> year_of_pub;
    this->year = year_of_pub;

}

String Film::film_data(){
    String adat("1;");
    adat = adat + title + ';';
    adat = adat + to_string(length).data() + ';';
    adat = adat + to_string(year).data() + ";\n";

    return adat;
}
