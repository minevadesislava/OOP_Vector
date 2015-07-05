#include <iostream>
#include <cassert>
using namespace std;

#ifndef Vector_H
#define Vector_H

template <class T>
class Vector
{
public:
	/**
	* Creates Vector with default values
	*/
	Vector();

	/**
	* Creates Vector with given size
	* @param size
	*/
	Vector(int);

	/**
	* Creates Vector - copy of given Vector object
	* @param Vector object
	*/
	Vector(const Vector<T>&);

	/**
	* Creates Vector and fills it with default values
	* @param T value
	* @param size
	*/
	Vector(int, const T&);

	/**
	* Destructor
	*/
	~Vector();

	/**
	* Retruns the size of the vector
	* @return vsize
	*/
	int size();

	/**
	* Retruns the actual size of the vector
	* @return maxsize
	*/
	int capacity();

	/**
	* Retruns true if the vector is empty
	* @return boolean
	*/
	bool empty();

	/**
	* Retruns synonym of the value on given possition
	* @param index
	* @return &T
	*/
	T& operator[](int);

	/**
	* Overrides = operator. Assigns the properties of one vector to the one on the left side
	* @param Vector object
	* @return Vector object
	*/
	Vector & operator=(const Vector&);

	/**
	* Checks if value on given possition exists and returns it
	* @param int index
	* @return T
	*/
	T at(int);

	/**
	* Checks if value on first possition exists and returns it
	* @return T
	*/
	T & front();

	/**
	* Checks if value on last possition exists and returns it
	* @return T
	*/
	T & back();

	/**
	* Appends element to the vector
	* @param &T
	*/
	void push_back(const T&);

	/**
	* Removes last element to the vector
	*/
	void pop_back();

	/**
	* Changes the size of the vector
	* @param int size
	*/
	void resize(int);

	/**
	* Changes the reserved size of the vector
	* @param int size
	*/
	void reserve(int);

	/**
	* Removes element on given possition
	* @param int index
	*/
	void erase(int);

	/**
	* Removes all data and set 0 values to all properties of the vector
	*/
	void clear();

	/**
	* Inserts T element on given possition
	* @param int index
	* @param T
	*/
	void insert(int, const T&);

	/**
	* Shrinks reserved space
	*/
	void shrink_to_fit();

	/**
	* swaps two vectors
	* @param Vector&
	*/
	void swap(Vector&);
private:
	//Default size of an empty vector's array
	static const int _DEFAULT_SIZE = 4;
	int vsize;
	int maxsize;
	T* data;
	void shrink(int);
};

template<class T>
Vector<T>::Vector()
{
	vsize = 0;
	maxsize = _DEFAULT_SIZE;
	data = new T[maxsize];
}

template<class T>
Vector<T>::Vector(int size)
{
	vsize = size;
	maxsize = size;
	data = new T[maxsize];
}

template<class T>
Vector<T>::Vector(const Vector<T> &v)
{
	vsize = v.vsize;
	maxsize = v.maxsize;
	data = new T[maxsize];
	for (int i = 0; i < vsize; i++)
	{
		data[i] = v.data[i];
	}
}

template<class T>
Vector<T>::Vector(int size, const T& value)
{
	vsize = size;
	maxsize = size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = value;
	T();
}

template<class T>
Vector<T>::~Vector()
{
	delete[] data;
}

template<class T>
Vector<T> & Vector<T>::operator=(const Vector<T> &v)
{
	vsize = v.vsize;
	maxsize = v.maxsize;
	data = new T[maxsize];
	for (int i = 0; i < vsize; i++)
	{
		data[i] = v.data[i];
	}
	return *this;
}

template <class T>
T & Vector<T>::operator[](int index)
{
	return data[index];
}

template<class T>
T Vector<T>::at(int index){
	assert(index >= 0 && index < vsize);
	return data[index];
}

template<class T>
T& Vector<T>::front()
{
	assert(vsize > 0);
	return data[0];
}

template<class T>
T& Vector<T>::back()
{
	assert(vsize > 0);
	return data[vsize - 1];
}

template<class T>
void Vector<T>::shrink(int new_size)
{
	vsize = new_size;
	if (new_size <= maxsize / 2){
		maxsize -= maxsize/4;
		if (maxsize < _DEFAULT_SIZE){
			maxsize = _DEFAULT_SIZE;
		}
		T *temp = new T[maxsize];
		for (int i = 0; i < vsize; i++)
		{
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;
	}
}

template<class T>
void Vector<T>::insert(int index, const T &value)
{
	if (vsize >= maxsize){
		reserve(vsize*2);
	}
	T *temp = new T[maxsize];
	for (int i = 0; i <= vsize; i++)
	{
		if (i < index){
			temp[i] = data[i];
		}
		else if (i == index){
			temp[i] = value;
		}
		else{
			temp[i] = data[i - 1];
		}
	}
	delete[] data;
	data = temp;
	vsize++;
}

template<class T>
int Vector<T>::size(){
	return vsize;
}
template<class T>
int Vector<T>::capacity(){
	return maxsize;
}
template<class T>
bool Vector<T>::empty(){
	return !vsize;
}
template<class T>
void Vector<T>::push_back(const T &element){
	if (vsize >= maxsize){
		reserve(vsize*2);
	}
	data[vsize] = element;
	vsize++;
}
template<class T>
void Vector<T>::pop_back(){
	erase(vsize - 1);
}
template<class T>
void Vector<T>::erase(int index){
	T *temp = new T[maxsize];
	for (int i = 0; i < vsize-1; i++)
	{
		if (i < index){
			temp[i] = data[i];
		}
		else{
			temp[i] = data[i + 1];
		}
	}
	delete[] data;
	data = temp;
	shrink(vsize - 1);
}

template<class T>
void Vector<T>::resize(int size){
	assert(size >= 0);
	vsize = size;
	if (maxsize < size){
		reserve(size);
	}
}

template<class T>
void Vector<T>::reserve(int size){
	size = (size <= 0 ? 1 : size);
	if (size <= vsize)
		return;

	T* temp = new T[size];
	maxsize = size;
	for (int i = 0; i < vsize; i++)
		temp[i] = data[i];
	delete[] data;
	data = temp;
}

template <class T>
void Vector<T>::clear()
{
	maxsize = 0;
	vsize = 0;
	delete[] data;
	data = NULL;
}

template <class T>
void Vector<T>::shrink_to_fit()
{
	maxsize = vsize;
	reserve(vsize);
}

template <class T>
void Vector<T>::swap(Vector &v)
{
	Vector temp(v);
	v = *this;
	*this = temp;
}
#endif
