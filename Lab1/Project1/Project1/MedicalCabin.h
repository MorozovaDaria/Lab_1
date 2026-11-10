#pragma once
#include <string>
#include "ApartmentModule.h"

class MedicalCabin : public ApartmentModule {
public:
	MedicalCabin(std::string name, int effectiveness, int durability, int energy, int capacity);
	virtual Module* clone() const override;
	virtual std::string getType() const override;
};