#include "Fruit.h"

size_t Fruit::nextId = 0;

Fruit::Fruit(const char* name, double price)
{
	id = getNextId();
	setName(name);
	setPrice(price);
}

Fruit::Fruit()
{
	id = getNextId();
	setName("-");
}

Fruit::Fruit(const Fruit& other)
{
	copyFrom(other);
}

Fruit::Fruit(Fruit&& other) noexcept
{
	moveFrom(std::move(other));
}

Fruit& Fruit::operator=(const Fruit& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Fruit& Fruit::operator=(Fruit&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Fruit::~Fruit() {
	free();
}

void Fruit::setType(const FruitType& type) {
	this->type = type;
}

void Fruit::copyFrom(const Fruit& other)
{
	try {
		name = new char[strlen(other.name)] {}; //may trow bad_alloc ex
		strcpy(name, other.name);
		
		price = other.price;
	}
	catch (const std::bad_alloc& ex) {
		std::cout << ex.what() << std::endl;
	}
}

void Fruit::moveFrom(Fruit&& other)
{
	name = other.name;
	other.name = nullptr;

	price = other.price;
}

void Fruit::free()
{
	delete[] name;
}

const char* Fruit::getName() const
{
	return name;
}

void Fruit::setName(const char* name)
{
	try {
		if (name == nullptr) {
			throw std::invalid_argument("Name to set should have a value!");
	    }
		else if (name == this->name) {
			return;
		}
		else {
			delete[] this->name;
			this->name = new char[strlen(name)] {}; //may trow bad_alloc ex
			strcpy(this->name, name);
		}
	}
	catch(const std::invalid_argument& ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (const std::bad_alloc& ex) {
		std::cout << ex.what() << std::endl;
	}
}

double Fruit::getPrice() const {
	return price;
}

void Fruit::setPrice(double price) {
	try {
		if (price <= 0 || price >= 100) {
			throw std::invalid_argument("Price must be greter than 0 and less than 100");
		}
		this->price = price;
	}
	catch (const std::invalid_argument& ex) {
		std::cout << ex.what() << std::endl;
	}
}

size_t Fruit::getNextId()
{
	return ++nextId;
}