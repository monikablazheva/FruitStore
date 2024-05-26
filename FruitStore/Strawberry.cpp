#include "Strawberry.h"

Strawberry::Strawberry() : Fruit()
{
    setType(FruitType::Strawberry);
}

Strawberry::Strawberry(const char* name, double price, double kilograms)
    :Fruit(name, price), kilograms(kilograms)
{
    setType(FruitType::Strawberry);
}

void Strawberry::printInfo() const
{
    std::cout << getName() << std::endl;
    std::cout << getPrice() << std::endl;
    std::cout << kilograms << std::endl;
}

Fruit* Strawberry::clone() const
{
    return new Strawberry(*this);
}

double Strawberry::getKilograms() const
{
    return kilograms;
}

void Strawberry::setKilograms(double kilograms)
{
    this->kilograms = kilograms;
}
