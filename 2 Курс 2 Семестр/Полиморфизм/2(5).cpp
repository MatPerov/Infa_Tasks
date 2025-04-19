#include <iostream>
#include <vector>
class Individual
{
public:
    virtual void speak() const = 0;
    virtual ~Individual() = default;
};

class Alice : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Alice" << std::endl;
    }
};

class Bob : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Bob" << std::endl;
    }
};

class Casper : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Casper" << std::endl;
    }
};

std::vector<std::unique_ptr<Individual>> createIndividuals() {
    std::vector<std::unique_ptr<Individual>> vector;
    for (int i = 0; i < 3; i++)
        vector.push_back(std::make_unique<Alice>());
    for (int i = 0; i < 2; i++)
        vector.push_back(std::make_unique<Bob>());
    for (int i = 0; i < 4; i++)
        vector.push_back(std::make_unique<Casper>());
    return vector;
}
void letThemSpeak(std::vector<std::unique_ptr<Individual>> vector) {
    for (int i = 0; i < vector.size();i++) {
        vector[i]->speak();
    }
}

int main()
{
    std::vector<std::unique_ptr<Individual>> vector = createIndividuals();
    letThemSpeak(vector);
}