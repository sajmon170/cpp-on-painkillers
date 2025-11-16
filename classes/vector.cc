#include <iostream>

template <typename T>
class Vector {
	std::size_t len = 0;
	std::size_t capacity = 10;
	T* buffer = new T[this->capacity];

	void expand() {
		this->capacity *= 2;

		T* bigger_buffer = new T[this->capacity];
		for (std::size_t i = 0; i < this->size(); ++i) {
			bigger_buffer[i] = this->buffer[i];
		}

		delete[] this->buffer;
		this->buffer = bigger_buffer;
	}

public:
	~Vector() {
		delete[] this->buffer;
	}

	void push_back(T const& element) {
		if (this->size() == capacity)
			this->expand();

		this->buffer[this->len++] = element;
	}

	std::size_t size() const {
		return this->len;
	}

	T* begin() {
		return this->buffer;
	}

	T* end() {
		return this->buffer + this->len;
	}
};

void print_vector(Vector<int> v) {
	for (auto& element: v) {
		std::cout << element << " ";
	}
}

int main() {
	auto v = Vector<int>();

	for (int i = 0; i < 100; ++i)
		v.push_back(i);

	print_vector(v);
	print_vector(v);

	std::cout << std::endl;
}
