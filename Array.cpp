#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void)
:data_ (new T[0]),
 cur_size_(0),
 max_size_(0)
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
:data_(new T[length]),
 cur_size_ (length),
 max_size_(length)
{

}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
:data_(new T[length]),
 cur_size_ (length),
 max_size_ (length)
{
	for(int i = 0; i < cur_size_; i++) {
        	data_[i] = fill;
        }
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
:data_(new T[array.max_size_]),
cur_size_(array.cur_size_),
max_size_(array.max_size_)
{
	for(int i = 0; i < cur_size_; i++) {
		data_[i] = array.data_[i];
	}
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
	delete [] data_;
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	if (this == &rhs) {
		return *this;
	}
	else {
		if(rhs.max_size_ > max_size_) {
			delete [] data_;
			T * copyData_ = new T[rhs.max_size_];

			for(int i = 0; i < rhs.max_size_; i++) {
				copyData_[i] = rhs.data_[i];
			}

			data_ = copyData_;
			cur_size_ = rhs.cur_size_;
			max_size_ = rhs.max_size_;
		}
		else {
			for(int j = 0; j < rhs.max_size_; j++) {
				data_[j] = rhs.data_[j];
			}
			cur_size_ = rhs.cur_size_;
		}
	}
	return *this;
}

//
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{
	if(index < 0 || index >= cur_size_) {
		throw std::out_of_range("Not in range");
	}
	return data_[index];
}

//
// operator [] 
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
	if(index < 0 || index >= cur_size_) {
                throw std::out_of_range("Not in range");
        }
        return data_[index];

}

//
// get
//
template <typename T>
T Array <T>::get (size_t index) const
{
	if(index < 0 || index >= cur_size_) {
		throw std::out_of_range("Not in range");
	}
	return data_[index];
}

//
// set
//
template <typename T>
void Array <T>::set (size_t index, T value)
{
	if(index < 0 || index >= cur_size_) {
		throw std::out_of_range("Not in range");
	}
	else {
		data_[index] = value;
	}
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	if(new_size <= max_size_) {
		cur_size_ = new_size;
	}
	else {
		T * newBiggerData_ = new T[new_size];

		for(int i = 0; i < cur_size_; i++) {
			newBiggerData_[i] = data_[i];
		}

		delete [] data_;
		data_ = newBiggerData_;
		cur_size_ = new_size;
		max_size_ = new_size;
	}
}

//
// find (char)
//
template  <typename T>
int Array <T>::find (T value) const
{
	for(int i =0; i < cur_size_; i++) {
		if(data_[i] == value) {
			return i;
		}
	}
	return -1;
}

//
// find (char, size_t) 
//
template <typename T>
int Array <T>::find (T val, size_t start) const
{
	if(start < 0 || start >= cur_size_) {
		throw std::out_of_range("Not in range");
	}
	else {
		for(int i = start; i < cur_size_; i++) {
			if (data_[i] == val) {
				return i;
			}
		}
		return -1;
	}
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
	if(this == &rhs) {
		return true;
	}	
	if(cur_size_ != rhs.cur_size_ || max_size_ != rhs.max_size_) {
		return false;
	}
	for(int i = 0; i <cur_size_; i++) {
		if(data_[i] != rhs.data_[i]) {
			return false;
		}
	}
	return true;

	
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
	return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Array <T>::fill (T value)
{
	for(int i = 0; i < cur_size_; i++) {
		data_[i] = value;
	}
}
