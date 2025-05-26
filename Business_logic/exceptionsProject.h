#ifndef EXCEPTIONSPROJECT_H
#define EXCEPTIONSPROJECT_H

#endif // EXCEPTIONSPROJECT_H
#include <exception>

class NameTooLongException : public std::exception{
public:
    const char* what() const throw(){
        return "Imię za długie - max 30 znaków";
    }
};

class SurnameTooLongException : public std::exception{
public:
    const char* what() const throw(){
        return "Nazwisko za długie - max 30 znaków";
    }
};

class SearchTextTooLongException : public std::exception{
public:
    const char* what() const throw(){
        return "Wyszukiwany tekst za długi - max 40 znaków";
    }
};
