#include <string>
#include "SolarModule.h"

SolarModule::SolarModule(std::string name, int effectiveness, int durability, int energy, int capacity) : EnergyModule(name, effectiveness, durability, energy, capacity) {

}
std::string SolarModule::getType() const {
	return "SolarModule";
}
Module* SolarModule::clone() const {
	return new SolarModule(*this);
}