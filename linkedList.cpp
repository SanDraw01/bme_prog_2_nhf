#include <iostream>
#include <fstream>
#include <sstream>
#include "linkedList.h"
#include "string.h"
#include "dokumentumFilm.h"
#include "csaladiFilm.h"
#include "exception.h"

using std::getline;
using std::string;
using std::cout;
using std::endl;

namespace cp {      //cross-platform getline

  std::istream& getline(std::istream& is, std::string& str) {
    std::getline(is, str);
    if (str.size() && *str.rbegin() == '\r')
        str.erase(str.size()-1);
    return is;
  }
}

void FilmList::insertElement(ListItem* data){
    if(filmExists(data->film_data->getTitle())){ // Megnézem, hogy a film benne van-e a listában.
        throw MyException("Film already in the database!");
    }
    if (head == NULL) {
        head = data;
        num_of_films++;
        return;
    }

    ListItem* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = data;
    num_of_films++;
}
void FilmList::printFilms(){
    ListItem* temp = head;

    if (head == NULL) {
        std::cout << "Egyelore nincs film a listaban!\n" << std::endl;
        return;
    }

    while (temp != NULL) {
        temp->printData();
        temp = temp->next;
    }
    std::cout << std::endl;
}
void FilmList::deleteElement(String title){
    ListItem *lemarado = NULL;
    ListItem *mozgo = head;
    while (mozgo != NULL && strcmp(mozgo->film_data->getTitle().c_str(),title.c_str()) != 0) {
        lemarado = mozgo;
        mozgo = mozgo->next;
    }

    /* megtalált elem törlése */
    if (mozgo == NULL) {           /* nincs ilyen elem */
        throw MyException("Nincs ilyen elem a listaban!");
    } else if (lemarado == NULL) { /* az első elemet kell törölni */
        ListItem *ujeleje = mozgo->next;
        delete mozgo;
        head = ujeleje;
        num_of_films--;
    } else {                       /* a közepéről/végéről törlünk */
        lemarado->next = mozgo->next;
        delete mozgo;
        num_of_films--;
    }
}
void FilmList::searchFilm(String title){
    ListItem* temp = head;

    if (head == NULL) {
        std::cout << "Nincs film az adatbazisban!" << std::endl;
    }

    while (temp != NULL) {
        if(strcmp(temp->film_data->getTitle().c_str(), title.c_str()) == 0){
            temp->printData();
        }
        temp = temp->next;
    }

}
bool FilmList::filmExists(String title){
    ListItem* temp = head;

    if (head == NULL) {
        return false;
    }

    while (temp != NULL) {
        if(strcmp(temp->film_data->getTitle().c_str(), title.c_str()) == 0){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void FilmList::loadFilms(){

    string myText;
    string token;
    std::ifstream my_file("./filmek.txt");
    try{
        if (!my_file) {
            throw MyException("Nem tudtam megnyitni a fajlt!");
        }
    }
    catch(MyException x){
        std::cout << x.what() << std::endl;
    }

    while(cp::getline(my_file, myText)){
        switch (myText[0]){
            case '1':{
                    std::stringstream ss(myText);
                    string arr[3];
                    size_t index = 0;
                    getline(ss, token, ';');
                    while(getline(ss, token, ';')){
                        arr[index] = token;
                        index++;
                    }
                    Film* uj_film = new Film(arr[0].data(),stoi(arr[1]), stoi(arr[2]));
                    ListItem* uj = new ListItem(uj_film);
                    this->insertElement(uj);
                    break;
                }
            case '2':{
                std::stringstream ss(myText);
                string arr[4];
                size_t index = 0;
                getline(ss, token, ';');
                while(getline(ss, token, ';')){
                    arr[index] = token;
                    index++;
                }
                Documentary* ujdok = new Documentary(arr[0].data(),arr[1].data(), stoi(arr[2]), stoi(arr[3]));
                ListItem* uj_doc_elem = new ListItem(ujdok);
                this->insertElement(uj_doc_elem);
                break;
            }
            case '3':
                std::stringstream ss(myText);
                string arr[4];
                size_t index = 0;
                getline(ss, token, ';');
                while(getline(ss, token, ';')){
                    arr[index] = token;
                    index++;
                }
                FamilyFilm* uj_fam = new FamilyFilm(arr[0].data(), stoi(arr[1]), stoi(arr[2]),stoi(arr[3]));
                ListItem* uj_fam_elem = new ListItem(uj_fam);
                this->insertElement(uj_fam_elem);
                break;
        }
    }
    my_file.close();
}
bool FilmList::exportFilms(){
    std::ofstream my_file("filmek.txt");
    ListItem* temp = head;
    if (!my_file) {
        return false;
    }
    if (head == NULL) {
        return true;
    }

    while (temp != NULL) {

        my_file << temp->film_data->film_data();


        temp = temp->next;
    }
    my_file.close();
    return true;
}
FilmList::~FilmList(){
    ListItem *lemarado = NULL;
    ListItem *mozgo = head;
    while (mozgo != NULL) {
        lemarado = mozgo;
        mozgo = mozgo->next;
        delete lemarado;
    }
}

ListItem::ListItem(ListItem& rhs){
    film_data = rhs.film_data;
    next = NULL;
}

