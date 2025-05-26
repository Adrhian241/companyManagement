#include "validator.h"
#include "exceptionsProject.h"

void Validator::validateName(const QString& name) {
    if(name.length() > 30){
        throw NameTooLongException();
    }
}

void Validator::validateSurname(const QString& surname){
    if(surname.length() > 30){
        throw SurnameTooLongException();
    }
}

void Validator::validateSearchText(const QString& searchText){
    if(searchText.length() > 40){
        throw SearchTextTooLongException();
    }
}
