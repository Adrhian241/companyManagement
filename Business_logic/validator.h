#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <QString>

class Validator
{
public:
    static void validateName(const QString& name);
    static void validateSurname(const QString& surname);
    static void validateSearchText(const QString& searchText);
};

#endif // VALIDATOR_H
