#ifndef EXCEPTIONSPROJECT_H
#define EXCEPTIONSPROJECT_H

#endif // EXCEPTIONSPROJECT_H
#include <exception>

class NameTooLongException : public std::exception{
public:
    const char* what() const throw(){
        return "Imie za dlugie - max 30 znakow";
    }
};

class SurnameTooLongException : public std::exception{
public:
    const char* what() const throw(){
        return "Nazwisko za dlugie - max 30 znakow";
    }
};

class SearchTextTooLongException : public std::exception{
public:
    const char* what() const throw(){
        return "Wyszukiwany tekst za dlugi - max 40 znakow";
    }
};
