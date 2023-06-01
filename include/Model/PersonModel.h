#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <string>

class PersonModel {
    public: 
        PersonModel();
        PersonModel(int id, std::string name, std::string surname, std::string email, std::string password);
        int getId();
        std::string getName();
        void setName(std::string name);
        std::string getSurname();
        void setSurname(std::string surname);
        std::string getEmail();
        void setEmail(std::string email);
        std::string getPassword();
        void setPassword(std::string password);

    private:
        int id;
        std::string name;
        std::string surname;
        std::string email;
        std::string password;
        
};

#endif