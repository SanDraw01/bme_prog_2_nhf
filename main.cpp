#include <iostream>
#include "linkedList.h"
#include "film.h"
#include "dokumentumFilm.h"
#include "csaladiFilm.h"
#include "gtest_lite.h"
#include "memtrace.h"
#include "exception.h"

using std::cin;
using std::cout;
using std::endl;

void printMenu(){
    cout << "##############################################" << endl;
    cout << "#  FILMTAR KEZELO PROGRAM - ANDERLIK SANDOR  #" << endl;
    cout << "##############################################" << endl;
    cout << endl;
    cout << "1.) Filmek listazasa" << endl;
    cout << "2.) Uj film felvetele" << endl;
    cout << "3.) Film keresese" << endl;
    cout << "4.) Film torlese" << endl;
    cout << "9.) Kepernyo torlese" << endl;
    cout << "0.) Kilepes" << endl;

};
void printFilmTypes(){
    system("cls");
    cout << "Valasszon az alabbi kategoriak kozul: " << endl;
    cout << "1.) Egyszeru film" << endl;
    cout << "2.) Dokumentum film" << endl;
    cout << "3.) Csaladi film" << endl;
    cout << "0.) Vissza a fomenube" << endl;
}

bool addFilmToDatabase(FilmList* lista){
    int film_type;
    cout << "Milyen filmet akar felvenni?" << endl;
    printFilmTypes();

    while(cin >> film_type && film_type != 0){
        switch(film_type){
        case 1:
            {
                Film * ujfilm = new Film();
                ujfilm->beolvas();
                std::cout << ujfilm->film_data();
                ListItem* element = new ListItem(ujfilm);
                lista->insertElement(element);

                return true;
                break;
            }
        case 2:
            {
                Documentary* uj_doc = new Documentary();
                uj_doc->beolvas();

                ListItem* elem2 = new ListItem(uj_doc);
                lista->insertElement(elem2);

                return true;
                break;
            }
        case 3:
            {
                FamilyFilm* uj_famfilm = new FamilyFilm();
                uj_famfilm->beolvas();

                ListItem* elem3 = new ListItem(uj_famfilm);
                lista->insertElement(elem3);

                return true;
                break;
            }
        default:

            break;
        }
    }
    system("cls");
    return false;
}
void searchFilm(FilmList* lista){
    cout << "Irja be a film cimet: ";
    char c = '0';
    String filmTitle;

    cin.get();
    while(c != '\n'){
        cin.get(c);
        if(c != '\n'){
            filmTitle = filmTitle + c;
        }
    }
    cout << "Ezt keresem: " << filmTitle << endl;
    try{
        if(lista->filmExists(filmTitle)){
        lista->searchFilm(filmTitle);
    }
    else{
        throw MyException("Nincs ilyen film az adatbazisban!");
    }
    }
    catch(MyException x){
        std::cout << x.what() << std::endl;
    }

}
void deleteFilm(FilmList* lista){
    cout << "Irja be a torolni kivant film cimet: ";
    char c;
    String filmTitle;
    cin.get();

    while(c != '\n'){
        cin.get(c);
        if(c != '\n'){
            filmTitle = filmTitle + c;
        }
    }
    try{
        lista->deleteElement(filmTitle);
    }
    catch(MyException x){
        std::cout << x.what() << std::endl;
    }

}

int main()
{
    FilmList* lista = new FilmList();

    /* MENÜS TESZT*/
    int nr;
    printMenu();
    lista->loadFilms();
    while(cin >> nr){

        switch (nr) {
            case 1:
                cout << "\nA listaban tarolt filmek: " << endl;
                lista->printFilms();
                break;
            case 2:
                addFilmToDatabase(lista);
                break;

            case 3:
                searchFilm(lista);
                break;
            case 4:
                deleteFilm(lista);
                break;
            case 9:
                system("cls");
                break;
            case 0:
                lista->exportFilms();
                delete lista;
                exit(0);
            default:
                cout << "nincs ilyen" << endl;
                break;
        } // switch

        printMenu();
    }


    /*
    TEST(Film_beolvasas_fajlbol, mindentipus){
        lista->loadFilms();
        EXPECT_EQ(3,lista->getLength());
    } END;
    lista->printFilms();
    TEST(Film_hozzaad, meg_nem_szerepel) {
        Film* film = new Film(); // Még nem szereplő film hozzáadása
        film->beolvas();
        Documentary* doksi = new Documentary(); // Még nem szereplő film hozzáadása
        doksi->beolvas();
        FamilyFilm* fam = new FamilyFilm(); // Még nem szereplő film hozzáadása
        fam->beolvas();
        ListItem* element_film = new ListItem(film);
        ListItem* element_doksi = new ListItem(doksi);
        ListItem* element_csaladi = new ListItem(fam);
        lista->insertElement(element_film);
        lista->insertElement(element_doksi);
        lista->insertElement(element_csaladi);
        EXPECT_EQ(6,lista->getLength());

    } END ;
    TEST(Film_hozzaad, mar_nem_szerepel) { // Már szereplő film hozzáadása
        Documentary* doksi = new Documentary("dokumentum","leiras2",200,200);
        ListItem* new_element = new ListItem(doksi);

        EXPECT_THROW(lista->insertElement(new_element),MyException);
        delete new_element;
    } END;
    TEST(Film_letezik, letezo_film){
        EXPECT_EQ(true,lista->filmExists("dokumentum"));
    } END;
    TEST(Film_letezik, nem_letezo_film){
        EXPECT_EQ(false,lista->filmExists("dokumentum2"));
    } END;
    TEST(Film_torles, letezo_film){ // létező film törlése
      lista->deleteElement("csaladi");
      EXPECT_EQ(5, lista->getLength());
    } END;
    TEST(Film_torles, nem_letezo_film){ // Nem létező film törlése
        EXPECT_THROW(deleteFilm(lista), MyException);
    } END;
    TEST(Film_kereses, letezo){ // Nem létező film törlése
        EXPECT_NO_THROW(searchFilm(lista));
    } END;
    TEST(FilmekExportalasa, filmexport){
        EXPECT_EQ(true, lista->exportFilms());
    } END;

    delete lista;
    */
    return 0;
}
