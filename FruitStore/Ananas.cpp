#include "Ananas.h"

Ananas::Ananas(): Fruit()
{
    setType(FruitType::Ananas);
}

Ananas::Ananas(const char* name, double price, size_t quantity) 
    : Fruit(name, price), quantity(quantity)
{
    setType(FruitType::Ananas);
}

void Ananas::printInfo() const
{
    std::cout << getName() << std::endl;
    std::cout << getPrice() << std::endl;
    std::cout << quantity << std::endl;
}

Fruit* Ananas::clone() const
{
    return new Ananas(*this);
}

size_t Ananas::getQuantity() const
{
    return quantity;
}

void Ananas::setQuanity(size_t quanity)
{
    this->quantity = quanity;
}
