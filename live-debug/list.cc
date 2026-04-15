#include <iostream>

template <typename T>
struct Cell {
	T data;
	Cell<T>* prev = nullptr;
	Cell<T>* next = nullptr;
};

template <typename T>
class LinkedList {
	Cell<T>* start = nullptr;

public:
	void add(T const& element) {
		Cell<T>* iter = start;
		Cell<T>* prev = nullptr;

		while (iter != nullptr) {
			prev = iter;
			iter = iter->next;
		}

		iter = new Cell<T>();
		iter->data = element;
		iter->prev = prev;

		if (prev != nullptr)
			prev->next = iter;
		else {
			start = iter;
		}
	}
};

int main() {
	LinkedList<int> mylist;
	for (auto& e: {2, 1, 3, 7})
		mylist.add(e);
}
