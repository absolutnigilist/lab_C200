#include "Pair.h"
Pair::Pair() :key(), data() {};
Pair::Pair(const char* k, const MyData& d) :key(k), data(d) {};
Pair::~Pair() {}
Pair::Pair(const Pair& other) :key(other.key), data(other.data) {};
Pair::Pair(Pair&& other) :key(std::move(other.key)), data(std::move(other.data)) {}
Pair& Pair::operator=(const Pair& other)
{
	if (this != &other) {
		key = other.key;
		data = other.data;
	}
	return *this;
};
Pair& Pair::operator=(Pair&& other) {
	if (this != &other)
	{
		key = std::move(other.key);
		data = std::move(other.data);
	}
	return *this;
}
bool Pair::operator==(const char* k) const {
	return key == k;
};
std::ostream& operator<<(std::ostream& os, const Pair& other) {
	os << other.key << other.data;
	return os;
};
