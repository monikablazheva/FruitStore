#pragma once
#include<iostream>
#define TP template<typename T, typename Factory>

TP
class Container
{
private:
	T** data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void copyFrom(const Container<T, Factory>& other);
	void moveFrom(Container<T, Factory>&& other);
	void free();
	void resize();

public:
	Container();
	Container(const Container<T, Factory>& other);
	Container(Container<T, Factory>&& other) noexcept;

	Container<T, Factory>& operator=(const Container<T, Factory>& other);
	Container<T, Factory>& operator=(Container<T, Factory>&& other) noexcept;

	~Container();

	void add(const T& obj);
	void add(typename Factory::Type type);

	const T* operator[](size_t index) const;
	T* operator[](size_t index);

	size_t getSize() const;
	void printAll() const;
};

