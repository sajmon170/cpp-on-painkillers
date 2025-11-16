#include <iostream>
#include <memory>

template <typename T>
class Array {
	std::size_t const len;
	std::unique_ptr<T[]> buffer;

public:
	Array(std::size_t sz)
		: len(sz), buffer(std::make_unique<T[]>(sz)) { }

	std::size_t size() const {
		return this->len;
	}

	T& operator[](std::size_t idx) {
		return this->buffer[idx];
	}

	T* begin() {
		return this->buffer.get();
	}

	T* end() {
		return this->begin() + len;
	}
};

void print_array(Array<int> arr) {
	for (auto& element: arr) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}

int main() {
	auto arr = Array<int>(32);

	for (int i = 0; i < arr.size(); ++i)
		arr[i] = i;

	print_array(arr);
}
