#pragma once
#include <string>
#include "Module.h"

class ApartmentModule : public Module {
public:
	ApartmentModule(std::string name, int effectiveness, int durability, int energy, int capacity);
};