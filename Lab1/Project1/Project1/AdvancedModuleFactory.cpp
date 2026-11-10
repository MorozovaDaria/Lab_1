#include "AdvancedModuleFactory.h"
#include <string>

Module* AdvancedModuleFactory::createApartmentModule(std::string name, int effectiveness, int durability, int energy, int capacity) {
	return new MedicalCabin(name, effectiveness, durability, energy, capacity);
}
Module* AdvancedModuleFactory::createEnergyModule(std::string name, int effectiveness, int durability, int energy, int capacity) {
	return new ReactorModule(name, effectiveness, durability, energy, capacity);
}
Module* AdvancedModuleFactory::createResearchModule(std::string name, int effectiveness, int durability, int energy, int capacity) {
	return new PhysicsLab(name, effectiveness, durability, energy, capacity);
}