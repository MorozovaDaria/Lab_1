#include "Capacity.h"
#include <stdexcept>

Capacity::Capacity(int value) {
	if (value < 0) {
		throw std::invalid_argument("Error");
	}
	value_ = value;
}
int Capacity::getValue() const {
	return value_;
}
void Capacity::setValue(int value) {
	if (value < 0) {
		throw std::invalid_argument("Error");
	}
	value_ = value;
}