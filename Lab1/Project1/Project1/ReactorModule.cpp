#include <string>
#include "ReactorModule.h"

ReactorModule::ReactorModule(std::string name, int effectiveness, int durability, int energy, int capacity) : EnergyModule(name, effectiveness, durability, energy, capacity) {

}
std::string ReactorModule::getType() const {
	return "ReactorModule";
}
Module* ReactorModule::clone() const {
	return new ReactorModule(*this);
}