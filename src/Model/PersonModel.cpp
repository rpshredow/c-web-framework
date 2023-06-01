#include "../../include/Model/PersonModel.h"

PersonModel::PersonModel(){}

PersonModel::PersonModel(int id, std::string name, std::string surname, std::string email, std::string password) : 
name(name), surname(surname), email(email), password(password) {}

int PersonModel::getId() {
    return id;
}

std::string PersonModel::getName() {
    return name;
}

void PersonModel::setName(std::string name) {
    name = name;
}

std::string PersonModel::getSurname() {
    return surname;
}

void PersonModel::setSurname(std::string surname) {
    surname = surname;
}

std::string PersonModel::getEmail() {
    return email;
}

void PersonModel::setEmail(std::string email) {
    email = email;
}

std::string PersonModel::getPassword() {
    return password;
}

void PersonModel::setPassword(std::string password) {
    password = password;
}