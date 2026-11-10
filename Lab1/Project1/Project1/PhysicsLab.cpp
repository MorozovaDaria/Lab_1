#include <string>
#include "PhysicsLab.h"

PhysicsLab::PhysicsLab(std::string name, int effectiveness, int durability, int energy, int capacity) : ResearchModule(name, effectiveness, durability, energy, capacity) {

}
std::string PhysicsLab::getType() const {
	return "PhysicsLab";
}
Module* PhysicsLab::clone() const {
	return new PhysicsLab(*this);
}