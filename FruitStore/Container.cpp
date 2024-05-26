#include "Container.h"
#include "Factory.h"

TP
void Container<T,Factory>::copyFrom(const Container<T, Factory>& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new T * [capacity];
	for (size_t i = 0; i < size; i++)
	{
		T* cloned = other.data[i]->clone();
		if (cloned) {
			data[i] = cloned;
		}
	}
}

TP
void Container<T, Factory>::moveFrom(Container<T, Factory>&& other)
{
	data = other.data;
	other.data = nullptr;
	
	size = other.size;
	other.size = 0;

	capacity = other.capacity;
	other.capacity = 0;
}

TP
void Container<T, Factory>::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete data[i];
	}
	delete[] data;
}

TP
void Container<T, Factory>::resize()
{
	capacity *= 2;
	T** newContainer = new T * [capacity];
	for (size_t i = 0; i < size; i++)
	{
		newContainer[i] = data[i];
	}
	delete[] data;
	data = newContainer;
}

TP
Container<T, Factory>::Container()
{
	capacity = 8;
	size = 0;
	data = new T * [capacity];
}

TP
Container<T, Factory>::Container(const Container<T, Factory>& other)
{
	copyFrom(other);
}

TP
Container<T, Factory>::Container(Container<T, Factory>&& other) noexcept
{
	moveFrom(std::move(other));
}

TP
Container<T, Factory>& Container<T, Factory>::operator=(const Container<T, Factory>& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

TP
Container<T, Factory>& Container<T, Factory>::operator=(Container<T, Factory>&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

TP
Container<T, Factory>::~Container()
{
	free();
}

TP
void Container<T, Factory>::add(const T& obj)
{
	if (size == capacity) {
		resize();
	}

	T* cloned = obj.clone();
	if (cloned) {
		data[size++] = cloned;
	}
}

TP
void Container<T, Factory>::add(typename Factory::Type type)
{
	if (size == capacity) {
		resize();
	}

	T* created = Factory::factory(type);
	if (created) {
		data[size++] = created;
	}
}

TP
const T* Container<T, Factory>::operator[](size_t index) const
{
	//VALIDATION
	return data[index];
}

TP
T* Container<T, Factory>::operator[](size_t index)
{
	//VALIDATION
	return data[index];
}

TP
size_t Container<T, Factory>::getSize() const
{
	return size;
}

TP
void Container<T, Factory>::printAll() const
{
	for (size_t i = 0; i < size; i++)
	{
		data[i]->printInfo();
		std::cout << std::endl;
	}
}

template Container<Fruit, Factory>;