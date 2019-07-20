#include "MyVector.h"


MyVector::MyVector() :
	m_data(0), m_size(0), m_capacity(0)
{

}
MyVector::MyVector(const MyVector &vectorToCopy) :
	m_data(new int[vectorToCopy.m_size]), m_size(vectorToCopy.m_size), m_capacity(vectorToCopy.m_capacity)
{
	for (unsigned i = 0; i < m_size; ++i)
	{
		m_data[i] = vectorToCopy.m_data[i];
	}
}
int & MyVector::operator[](unsigned index)
{
	return m_data[index];
}
int & MyVector::operator[](unsigned index) const
{
	return m_data[index];
}
MyVector& MyVector::operator=(const MyVector& right)
{
	if (this == &right)
	{
		return *this;
	}
	if (m_size!=right.m_size)
	{
		m_size = right.m_size;
		reserve(right.m_capacity);
	}
	for (int i = 0; i < m_size; ++i)
	{
		m_data[i] = right.m_data[i];
	}
	return *this;
}
MyVector::~MyVector()
{
	delete[] m_data;
}
void MyVector::swap(int& a, int& b)
{
	b += a;
	a = b - a;
	b -= a;
}
unsigned int MyVector::size() const
{
	return m_size;
}
void MyVector::reserve(int newCapacity)
{
	if (newCapacity > m_capacity)
	{
		m_capacity = newCapacity;
		int* newArr = new int[m_capacity];
		for (int i = 0; i < m_size; ++i)
		{
			newArr[i] = m_data[i];
		}
		delete[] m_data;
		m_data = newArr;
	}
}
void MyVector::push_back(int value)
{
	if (m_size >= m_capacity)
	{
		reserve(m_capacity+5);
	}
	m_data[m_size] = value;
	++m_size;
}
int MyVector::find(int value)
{
	int minint = -2147483646;
	for (unsigned i = 0; i < 1 + m_size / 2; ++i)
	{
		if (m_data[i] == value)
		{
			return i;
		}
		if (m_data[m_size-i] == value)
		{
			return m_size-i;
		}
	}
	return minint;
}
void MyVector::resize(unsigned newSize)
{
	int* newArr = new int[newSize];
	for (int i = 0; i < newSize; ++i)
	{
		newArr[i] = m_data[i];
	}
	if (m_size < newSize)
	{
		for (int i = m_size; i < newSize; ++i)
		{
			newArr[i] = 0;
		}
	}
	delete[] m_data;
	m_data = newArr;
	m_size = newSize;
}
void MyVector::erase(unsigned index)
{
	--m_size;
	for (unsigned i = index; i < m_size; ++i)
	{
		m_data[i] = m_data[i + 1];
	}
	resize(m_size);
}
void MyVector::insert(unsigned index,int value)
{
	push_back(0);
	int temp;
	temp = m_data[index];
	for (unsigned i = index; i < m_size; ++i)
	{
		swap(m_data[i + 1], temp);
	}
	m_data[index] = value;
}
void MyVector::clear()
{
	delete[] m_data;
	m_size = 0;
}
