#include "Base.h"
#define	  stop __asm nop

Base::Base() :count(0), capacity(0), pBase(nullptr) {};
Base::~Base() {
	delete[]pBase;
};
Base::Base(const Base& other) :count(other.count), capacity(other.count) {//���� �� ������
	pBase = new Pair[capacity];
	for (size_t i = 0; i < count; i++)
	{
		pBase[i] = other.pBase[i];
	}
};
Base::Base(Base&& other) :count(other.count), capacity(other.capacity), pBase(other.pBase) {
	other.count = 0;
	other.capacity = 0;
	other.pBase = nullptr;
};
Base& Base::operator=(const Base& other) {
	if (this != &other)
	{
		if (capacity<other.count)
		{
			delete[]pBase;
			capacity = other.count;
			pBase = new Pair[capacity];
		}
		count = other.count;
		
		for (size_t i = 0; i < count; i++)
		{
			pBase[i] = other.pBase[i];
		}
	}
	return *this;
}
Base& Base::operator=(Base&& other) {
	if (this != &other)
	{
		delete[]pBase;
		pBase = other.pBase;
		count = other.count;
		capacity = other.capacity;
		other.pBase = nullptr;
		other.count = 0;
		other.capacity = 0;

	}
	return *this;
};

MyData& Base::operator[](const char* key) {
	for (size_t i = 0; i < count; i++)
	{
		if (pBase[i] == key)
			return pBase[i].data;
	}
	if (count == capacity) {
		capacity++;
		Pair* tmp = new Pair[capacity];
		for (size_t i = 0; i < count; i++)
		{
			tmp[i] = std::move(pBase[i]);
		}
		delete[]pBase;
		pBase = tmp;
	}
	stop
		pBase[count] = Pair(key, MyData());
	count++;
	return pBase[count - 1].data;
};

int Base::deletePair(const char* key) {
	for (size_t i = 0; i < count; i++) {
		if (pBase[i] == key) {
			for (size_t j = i; j < count - 1; j++) {
				pBase[j] = std::move(pBase[j + 1]);
			}
			count--;
			return 1;
		}
	}
	return 0;
};

std::ostream& operator<<(std::ostream& os, const Base& other) {
	for (size_t i = 0; i < other.count; i++)
	{
		os << other.pBase[i];
	}
	std::cout << std::endl;
	return os;
};

void Base::Sort() {
	if (pBase == nullptr) {
		return;
	}

	for (size_t i = 0; i < count - 1; i++) {
		size_t min = i;
		for (size_t j = i + 1; j < count; j++) {
			if (pBase[j].key < pBase[min].key) {
				min = j;
			}
		}
		Pair tmp = std::move(pBase[min]);
		pBase[min] = std::move(pBase[i]);
		pBase[i] = std::move(tmp);
	}
};

