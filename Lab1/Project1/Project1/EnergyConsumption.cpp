#include "EnergyConsumption.h"
#include <stdexcept>

EnergyConsumption::EnergyConsumption(int value) {
	if (value < 0) {
		throw std::invalid_argument("Error");
	}
	value_ = value;
}
int EnergyConsumption::getValue() const {
	return value_;
}
void EnergyConsumption::setValue(int value) {
	if (value < 0) {
		throw std::invalid_argument("Error");
	}
	value_ = value;
}
void EnergyConsumption::increase(int amount) {
	if (amount < 0) {
		throw std::invalid_argument("Error");
	}
	value_ += amount;
}
void EnergyConsumption::decrease(int amount) {
	if (amount < 0) {
		throw std::invalid_argument("Error");
	}
	if (value_ - amount < 0) {
		value_ = 0;
	}
	else {
		value_ -= amount;
	}
}