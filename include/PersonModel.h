#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <string>

class PersonModel {
    public: 
        PersonModel();
        PersonModel(int id, std::string name, std::string surname, std::string email, std::string password);
        int getId() const;
        std::string getName() const;
        void setName(std::string name);
        std::string getSurname() const;
        void setSurname(std::string surname);
        std::string getEmail() const;
        void setEmail(std::string email);
        std::string getPassword() const;
        void setPassword(std::string password);

    private:
        int id;
        std::string name;
        std::string surname;
        std::string email;
        std::string password;
        
};

#endif