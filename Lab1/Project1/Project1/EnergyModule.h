#pragma once
#include <string>
#include "Module.h"

class EnergyModule : public Module {
public:
	EnergyModule(std::string name, int effectiveness, int durability, int energy, int capacity);
};