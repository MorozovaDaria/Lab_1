#pragma once
#include <string>
#include "EnergyModule.h"

class ReactorModule : public EnergyModule {
public:
	ReactorModule(std::string name, int effectiveness, int durability, int energy, int capacity);
	virtual Module* clone() const override;
	virtual std::string getType() const override;
}; 
