#pragma once
#include "Fruit.h"

class Ananas: public Fruit
{
private:
	size_t quantity = 0;

public:
	Ananas();
	Ananas(const char* name, double price, size_t quantity);

	void printInfo() const override;
	Fruit* clone() const override;

	size_t getQuantity() const;
	void setQuanity(size_t quanity);
};

