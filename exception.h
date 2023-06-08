#ifndef EXCEPTION_H_INCLUDED
#define EXCEPTION_H_INCLUDED

class MyException : public std::exception {
    private:
    std::string message;

    public:
    MyException(std::string msg) : message(msg) {}
    std::string what () {
        return message;
    }
};

#endif // EXCEPTION_H_INCLUDED
