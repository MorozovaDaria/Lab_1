#pragma once
#include <string>
#include "Module.h"

class ResearchModule : public Module {
public:
	ResearchModule(std::string name, int effectiveness, int durability, int energy, int capacity);
};