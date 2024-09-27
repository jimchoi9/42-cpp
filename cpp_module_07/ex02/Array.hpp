#include <iostream>

template <typename T>
class Array {
	public:
		Array() : data(new T()), _size(0) {}
		Array(size_t size) : data(new T[size]) ,_size(size){}
		Array(const Array &a) {
			
			if (a.size() == 0) {
				// delete[] a.data;
				data = new T[0];
				_size = 0;
			}
			else {
				// delete[] data;
				data = new T[a.size()];
				_size = a.size();
                for (size_t i = 0; i < a.size(); i++)
                    data[i] = a[i];
			}
		}
		Array &operator=(const Array &a) {
			if (this == &a)
                return *this;
            delete[] data;
            data = new T[a.size()];
			_size = a.size();
            for (size_t i = 0; i < a.size(); i++)
                data[i] = a[i];
            return *this;
		}
		~Array() { 
			if (data != NULL)
			{

			if (size() != 0)
				delete[] data; 
			else
				delete data;
			}
			}
		T &operator[](size_t index) {
			if (index >= size() || index < 0) {
                throw OutOfRangeException();
            }
            return data[index];
		}
		const T &operator[](size_t index) const {
			if (index >= size()) {
                throw OutOfRangeException();
            }
            return data[index];
		}

		size_t size() const {
            return _size;
        }

		class OutOfRangeException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Index out of range";
				};
		};
	private:
	    T *data;
		size_t _size;
};