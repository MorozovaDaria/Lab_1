#pragma once
#include <string>
#include "Module.h"

class ModuleFactory {
public:
	virtual Module* createApartmentModule(std::string name, int effectiveness, int durability, int energy, int capacity) = 0;
	virtual Module* createEnergyModule(std::string name, int effectiveness, int durability, int energy, int capacity) = 0;
	virtual Module* createResearchModule(std::string name, int effectiveness, int durability, int energy, int capacity) = 0;
	virtual ~ModuleFactory() = default;
};