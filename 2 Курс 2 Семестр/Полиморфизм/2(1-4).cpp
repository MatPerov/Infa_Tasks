#include <iostream>
#include <vector>
class Individual
{
public:
    virtual void speak() const = 0;
    virtual int myIdentification() {
        return 100;
    }
    virtual ~Individual() = default;
};

class Alice : public Individual
{
public:
    int myIdentification() {
        return 0;
    }
    void speak() const override
    {
        std::cout << "Hi, I am Alice" << std::endl;
    }
};

class Bob : public Individual
{
public:
    int myIdentification() {
        return 1;
    }
    void speak() const override
    {
        std::cout << "Hi, I am Bob" << std::endl;
    }
};

class Casper : public Individual
{
public:
    int myIdentification() {
        return 2;
    }
    void speak() const override
    {
        std::cout << "Hi, I am Casper" << std::endl;
    }
};

std::vector<Individual*> createIndividuals() {
    std::vector<Individual*> vector;
    for (int i = 0; i < 3; i++)
        vector.push_back(new Alice);
    for (int i = 0; i < 2; i++)
        vector.push_back(new Bob);
    for (int i = 0; i < 4; i++)
        vector.push_back(new Casper);
    return vector;
}
void letThemSpeak(std::vector<Individual*> vector) {
    for (int i = 0; i < vector.size();i++) {
        vector[i]->speak();
    }
}
void deleteIndividuals(std::vector<Individual*> vector) {
    for (int i = vector.size()-1; i > -1; i--) {
        delete vector[i];
    }
}

int identificationA(Individual* p) {
    return p->myIdentification();
}

int identificationB(Individual* p) {
    if (dynamic_cast<Alice*>(p) != nullptr) {
        return 0;
    }
    if (dynamic_cast<Bob*>(p) != nullptr) {
        return 1;
    }
    if (dynamic_cast<Casper*>(p) != nullptr) {
        return 2;
    }
}
int identificationC(Individual* p) {
    if (typeid(*p) == typeid(Alice)) {
        return 0;
    }
    if (typeid(*p) == typeid(Bob)) {
        return 1;
    }
    if (typeid(*p) == typeid(Casper)) {
        return 2;
    }
}
int main()
{
    std::vector<Individual*> vector = createIndividuals();
    letThemSpeak(vector);
    std::cout<<identificationA(vector[0])<<std::endl;
    std::cout << identificationB(vector[3])<< std::endl;
    std::cout << identificationC(vector[5]) << std::endl;
    deleteIndividuals(vector);
}