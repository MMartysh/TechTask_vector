#pragma once


class MyVector
{
public:
	MyVector();
	MyVector(const MyVector &vectorToCopy);
	~MyVector();
	void swap(int& a, int& b);
	void resize(unsigned newSize);
	void push_back(int value);
	void insert(unsigned index,int value);
	void insert(unsigned index, int* value, unsigned numberOfElements);
	void erase(unsigned index);
	void clear();
	void reserve(unsigned newCapacity);
	int find(int value);
	unsigned int size() const;
	MyVector & operator=(const MyVector& right);
	int & operator[](unsigned index);
	int & operator[](unsigned index) const;
private:
	int* m_data;
	unsigned int m_size;
	unsigned int m_capacity;
};