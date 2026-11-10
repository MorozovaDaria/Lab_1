#pragma once
#include <string>
#include "ResearchModule.h"

class BiologyLab : public ResearchModule {
public:
	BiologyLab(std::string name, int effectiveness, int durability, int energy, int capacity);
	virtual Module* clone() const override;
	virtual std::string getType() const override;
}; 
