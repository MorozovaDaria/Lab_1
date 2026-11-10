#include "StandardModuleFactory.h"
#include <string>

Module* StandardModuleFactory::createApartmentModule(std::string name, int effectiveness, int durability, int energy, int capacity) {
	return new CrewCabin(name, effectiveness, durability, energy, capacity);
}
Module* StandardModuleFactory::createEnergyModule(std::string name, int effectiveness, int durability, int energy, int capacity) {
	return new SolarModule(name, effectiveness, durability, energy, capacity);
}
Module* StandardModuleFactory::createResearchModule(std::string name, int effectiveness, int durability, int energy, int capacity) {
	return new BiologyLab(name, effectiveness, durability, energy, capacity);
}