#ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a C sztringkezelő függvényeire
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <cstring>

#include "string5.h"


/// Konstruktorok: egy char karakterből (createString)
///                egy nullával lezárt char sorozatból (createString)

String::String(char c){
     /// Meghatározzuk a hosszát
    len = 1;
    /// Lefoglalunk a helyet a hossznak + a lezáró nullának
    pData = new char[len+1];
    /// Betesszük a karaktert
    pData[0] = c;
    pData[1] = '\0';
}
String::~String(){
    delete[] pData;
}
String::String(const char* p){
    len = strlen(p);
    pData = new char[len + 1];

    for(int i = 0; p[i] != '\0'; i++){
        pData[i] = p[i];
    }
    pData[len] = '\0';
}
String::String(const String& s){
    len = s.size();
    pData = new char[len + 1];
    strcpy(pData, s.pData);
}
String& String::operator=(const String& s){

    if(this != &s){
        len = s.size();
        delete[] pData;
        pData = new char[len + 1];
        strcpy(pData, s.pData);

    }


    return *this;
}
String String::operator+(const String& s) const{
    char* szoveg = new char[len + s.size() + 1];

    strcpy(szoveg, pData);
    strcat(szoveg, s.pData);


    String uj(szoveg);
    delete[] szoveg;

    return uj;

}
String operator+(char c, const String& s){
    char* szoveg = new char[s.size() + 2];

    szoveg[0] = c;

    strcpy(szoveg+1, s.c_str());


    String uj(szoveg);
    delete[] szoveg;

    return uj;
}
std::ostream& operator<<(std::ostream& os, const String& s0) {
    os << s0.c_str();
    return os;
}

