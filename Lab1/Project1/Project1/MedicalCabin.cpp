#include <string>
#include "MedicalCabin.h"

MedicalCabin::MedicalCabin(std::string name, int effectiveness, int durability, int energy, int capacity) : ApartmentModule(name, effectiveness, durability, energy, capacity) {

}
std::string MedicalCabin::getType() const {
	return "MedicalCabin";
}
Module* MedicalCabin::clone() const {
	return new MedicalCabin(*this);
}