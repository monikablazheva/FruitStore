#pragma once
#include "Fruit.h"

class Strawberry : public Fruit
{
private:
	double kilograms = 0;

public:
	Strawberry();
	Strawberry(const char* name, double price, double kilograms);

	void printInfo() const override;
	Fruit* clone() const override;

	double getKilograms() const;
	void setKilograms(double kilograms);
};

