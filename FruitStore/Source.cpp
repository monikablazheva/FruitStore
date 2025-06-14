#include "Container.h"
#include "Fruit.h"
#include "Factory.h"

int main() {
	Container<Fruit, Factory> fruitShop;

	fruitShop.add(FruitType::Ananas);

	Ananas ananas("ananas mn juicy", 4.78, 8);
	fruitShop.add(ananas);

	fruitShop.add(FruitType::Strawberry);

	Ananas strawberry("bg strawberry", 6, 3);
	fruitShop.add(strawberry);

	fruitShop.printAll();

	fruitShop[2]->setName("Banana strawberry");
	fruitShop[2]->setPrice(6);

	fruitShop[2]->printInfo();
	fruitShop[3]->printInfo();
}
