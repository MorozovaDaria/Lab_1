#include "Durability.h"
#include <stdexcept>

Durability::Durability(int value) {
	if (value < 0) {
		throw std::invalid_argument("Error");
	}
		value_ = value;
}
int Durability::getValue() const {
	return value_;
}
void Durability::setValue(int value) {
	if (value < 0) {
		throw std::invalid_argument("Error");
	}
		value_ = value;
}
void Durability::decrease(int amount) {
	value_ -= amount;
	if (value_ < 0) {
		value_ = 0;
	}
}
void Durability::repair(int amount) {
	value_ += amount;
}