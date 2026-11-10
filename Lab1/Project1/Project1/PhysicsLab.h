#pragma once
#include <string>
#include "ResearchModule.h"

class PhysicsLab : public ResearchModule {
public:
	PhysicsLab(std::string name, int effectiveness, int durability, int energy, int capacity);
	virtual Module* clone() const override;
	virtual std::string getType() const override;
};
