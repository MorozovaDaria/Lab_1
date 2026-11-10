#include "Module.h"
#include <stdexcept>
#include <string>
#include "Station.h"

int Module::nextId_ = 1;
Module::Module(std::string name, int effectiveness, int endurance, int energy, int capacity) : name_(name), effectiveness_(effectiveness), durability_(endurance), energyConsumption_(energy), capacity_(capacity)
{
	ID_ = nextId_++;
	condition_ = "выключен";
	if (effectiveness > 100 || effectiveness < 0) {
		throw std::invalid_argument("Error");
	}
}
int Module::getID() const {
	return ID_;
}
std::string Module::getName() const {
	return name_;
}
int Module::getEffectiveness() const {
	return effectiveness_;
}
std::string Module::getCondition() const {
	return condition_;
}
Durability& Module::getDurability() {
	return durability_;
}
EnergyConsumption& Module::getEnergyConsumption() {
	return energyConsumption_;
}
Capacity& Module::getCapacity() {
	return capacity_;
}
void Module::activate() {
	condition_ = "включен";
}
void Module::deactivate() {
	condition_ = "выключен";
}
void Module::setState(const std::string& newState) {
	if (newState == "включен" || newState == "выключен" || newState == "авария" || newState == "ремонт") {
		condition_ = newState;
	}
	else {
		throw std::invalid_argument("Error");
	}
}
void Module::setEffectiveness(int newEff) {
	if (newEff > 100 || newEff < 0) {
		throw std::invalid_argument("Error");
	}
	effectiveness_ = newEff;
}
void Module::moveToIndex(Station& station, size_t currentIndex, size_t newIndex) {
	station.moveModule(currentIndex, newIndex);
}