#include "Factory.h"

Fruit* Factory::factory(Type type)
{
	switch (type) {
	case(FruitType::Ananas):
		return new Ananas();
	case(FruitType::Strawberry):
		return new Strawberry();
	}
	return nullptr;
}
