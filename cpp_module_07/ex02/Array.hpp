#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <iostream>

template <typename T>
class Array {
	public:
		Array() : data(NULL), _size(0) {}
		Array(unsigned int size) : data(new T[size]()) ,_size(size){}
		Array(const Array &a): data(NULL), _size(a.size())
		{
			if (_size > 0) {
				data = new T[_size];
                for (size_t i = 0; i < _size; i++)
                    data[i] = a.data[i];
			}
		}
		Array &operator=(const Array &a) 
		{
			if (this == &a)
                return *this;
            delete[] data;
			_size = a.size();
			if (_size > 0)
			{
                data = new T[_size];
                for (size_t i = 0; i < _size; i++)
                    data[i] = a.data[i];
			}
			else 
				data = NULL;
            return *this;
		}
		~Array() 
		{ 
			delete[] data;
		}


		T &operator[](size_t index) 
		{
			if (index >= size() || size() == 0) 
				throw std::out_of_range("array index out of bounds");
			return data[index];
		}
		const T &operator[](size_t index) const 
		{
			if (index >= size() || size() == 0)
                throw std::out_of_range("array index out of bounds");
            return data[index];
		}

		size_t size() const 
		{
            return _size;
        }

	private:
	    T *data;
		size_t _size;
};

#endif