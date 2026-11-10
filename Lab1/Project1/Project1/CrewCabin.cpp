#include <string>
#include "CrewCabin.h"

CrewCabin::CrewCabin(std::string name, int effectiveness, int durability, int energy, int capacity) : ApartmentModule(name, effectiveness, durability, energy, capacity) {

}
std::string CrewCabin::getType() const {
	return "CrewCabin";
}
Module* CrewCabin::clone() const {
	return new CrewCabin(*this);
}