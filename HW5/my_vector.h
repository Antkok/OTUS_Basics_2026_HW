#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class MyVector {
    private:
        T* vec;
        size_t vec_size;
        size_t vec_capacity;

        void resize_vec(size_t new_capacity);

    public:
        MyVector() : vec(nullptr), vec_size(0), vec_capacity(0) {}
        ~MyVector() { delete[] vec; }

        MyVector(const MyVector& other);
        MyVector& operator=(const MyVector& other);

        void push_back(const T& value);
        T& insert(size_t index, const T& value);
        size_t erase(size_t index);
        size_t size() const { return vec_size; }
        T& operator[](size_t index) { return vec[index]; }

        void print_elements() const {
            for (size_t i = 0; i < vec_size; ++i) {
                std::cout << vec[i];
                if (i + 1 < vec_size) std::cout << ' ';
            }
            std::cout << std::endl;
        }

        void print_size() const{
            std::cout << vec_size << std::endl;
        }

        void print_capacity() const{
            std::cout << vec_capacity << std::endl;
        }
};


template <typename T>
void MyVector<T>::resize_vec(size_t new_capacity) {
	T* new_vec = new T[new_capacity];

	for (size_t i = 0; i < vec_size; ++i) {
		new_vec[i] = vec[i];
	}

	delete[] vec;
	vec = new_vec;
	vec_capacity = new_capacity;
}

template <typename T>
MyVector<T>::MyVector(const MyVector& other) :
	vec_size(other.vec_size),
	vec_capacity(other.vec_capacity),
	vec(new T[other.vec_capacity])
{
	for (size_t i = 0; i < vec_size; ++i) {
		vec[i] = other.vec[i];
	}
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other) {
	if (this != &other) {
		delete[] vec;

		vec_size = other.vec_size;
		vec_capacity = other.vec_capacity;
		vec = new T[vec_capacity];
		for (size_t i = 0; i < vec_size; ++i) {
			vec[i] = other.vec[i];
		}
	}
	return *this;
}

template <typename T>
void MyVector<T>::push_back(const T& value) {
	if (vec_size == vec_capacity) {
		size_t new_capacity = (vec_capacity == 0) ? 1 : vec_capacity * 2;
		MyVector<T>::resize_vec(new_capacity);
	}
	vec[vec_size] = value;
	vec_size++;
}

template <typename T>
T& MyVector<T>::insert(size_t index, const T& value) {
	if (index > vec_size) {
		throw std::out_of_range("Insert index out of range!");
	}

	if (vec_size == vec_capacity) {
		size_t new_capacity = (vec_capacity == 0) ? 1 : vec_capacity * 2;
		resize_vec(new_capacity);
	}

	for (size_t i = vec_size; i > index; --i) {
		vec[i] = vec[i - 1];
	}

	vec[index] = value;
	vec_size++;

	return vec[index];
}

template <typename T>
size_t MyVector<T>::erase(size_t index) {
	if (index >= vec_size) {
		throw std::out_of_range("Erase index out of range!");
	}

	for (size_t i = index; i < vec_size - 1; ++i) {
		vec[i] = vec[i + 1];
	}

	vec_size--;

	return index;
}