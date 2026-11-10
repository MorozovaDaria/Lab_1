#pragma once
#include <string>
#include "EnergyModule.h"

class SolarModule : public EnergyModule {
public:
	SolarModule(std::string name, int effectiveness, int durability, int energy, int capacity);
	virtual Module* clone() const override;
	virtual std::string getType() const override;
};