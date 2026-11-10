#include <string>
#include "BiologyLab.h"

BiologyLab::BiologyLab(std::string name, int effectiveness, int durability, int energy, int capacity) : ResearchModule(name, effectiveness, durability, energy, capacity) {

}
std::string BiologyLab::getType() const {
	return "BiologyLab";
}
Module* BiologyLab::clone() const {
	return new BiologyLab(*this);
}