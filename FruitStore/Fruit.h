#pragma once
#include <iostream>
#pragma warning (disable : 4996)
#include "FruitType.h"

class Fruit
{
private:

	static size_t nextId;
	size_t id = 0;

	char* name = nullptr;
	double price = 0;

	FruitType type;
	
public:

	//Constructors
	Fruit();
	Fruit(const char* name, double price);
	Fruit(const Fruit& other);
	Fruit(Fruit&& other) noexcept;
	
	//Op=
	Fruit& operator=(const Fruit& other);
	Fruit& operator=(Fruit&& other) noexcept;

	//Virtual destructor
	virtual ~Fruit();

	//Other virtual functions
	virtual Fruit* clone() const = 0;
	virtual void printInfo() const = 0;

	//Getters and Settes
	const char* getName() const;
	void setName(const char* name);

	double getPrice() const;
	void setPrice(double price);

protected:
	void setType(const FruitType& type);

private:
	void copyFrom(const Fruit& other);
	void moveFrom(Fruit&& other);
	void free();

	static size_t getNextId();
};

