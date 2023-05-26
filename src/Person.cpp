#include "Person.h"

Person::Person(){}

Person::Person(int id, std::string name, std::string surname, std::string email, std::string password) : 
name(name), surname(surname), email(email), password(password) {}

int Person::getId() {
    return id;
}

std::string Person::getName() {
    return name;
}

void Person::setName(std::string name) {
    name = name;
}

std::string Person::getSurname() {
    return surname;
}

void Person::setSurname(std::string surname) {
    surname = surname;
}

std::string Person::getEmail() {
    return email;
}

void Person::setEmail(std::string email) {
    email = email;
}

std::string Person::getPassword() {
    return password;
}

void Person::setPassword(std::string password) {
    password = password;
}