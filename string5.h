#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
    char *pData;
    size_t len;
public:

    void printDbg(const char *txt = "") const {
        std::cout << txt << "[" << len << "], "
                  << (pData ? pData : "(NULL)") << '|' << std::endl;
    }

    /// Paraméter nélküli konstruktor:
    String() :pData(new char[1]{'\0'}), len(0) {}

    /// Sztring hosszát adja vissza.
    /// @return sztring tényleges hossza (lezáró nulla nélkül).
    size_t size() const { return len; }

    /// C-sztringet ad vissza
    /// @return pointer a tárolt, vagy azzal azonos tartalmú nullával lezárt sztring-re.
    const char* c_str() const {
        return pData;

    }


    String(char c);
    ~String();
    String(const char* s);
    String(const String& s);
    String& operator=(const String& s);
    String operator+(const String& s) const;

};

String operator+(char c, const String& s);
std::ostream& operator<<(std::ostream& os, const String& s0);



#endif
