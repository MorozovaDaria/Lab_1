#pragma once
#include "ModuleFactory.h"
#include "CrewCabin.h"
#include "SolarModule.h" 
#include "BiologyLab.h"

class StandardModuleFactory : public ModuleFactory {
public:
	virtual Module* createApartmentModule(std::string name, int effectiveness, int durability, int energy, int capacity) override;
	virtual Module* createEnergyModule(std::string name, int effectiveness, int durability, int energy, int capacity) override;
	virtual Module* createResearchModule(std::string name, int effectiveness, int durability, int energy, int capacity) override;
};