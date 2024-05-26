#pragma once
#include "Fruit.h"
#include "Ananas.h"
#include "Strawberry.h"

struct Factory {
	using Type = const FruitType&;
	static Fruit* factory(Type type);
};

