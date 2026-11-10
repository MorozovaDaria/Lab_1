#pragma once
#include <string>
#include "Durability.h"
#include "EnergyConsumption.h"
#include "Capacity.h"

class Station;

class Module {
protected:
	int ID_;
	std::string name_;
	int effectiveness_;
	std::string condition_;
	Durability durability_;
	EnergyConsumption energyConsumption_;
	Capacity capacity_;
	static int nextId_;
public:
	Module(std::string name, int effectiveness, int endurance, int energy, int capacity);
	virtual ~Module() = default;
	virtual Module* clone() const = 0;
	virtual std::string getType() const = 0;
	int getID() const;
	std::string getName() const;
	int getEffectiveness() const;
	std::string getCondition() const;
	Durability& getDurability();
	EnergyConsumption& getEnergyConsumption();
	Capacity& getCapacity();
	void activate();
	void deactivate();
	void setState(const std::string& newState);
	void setEffectiveness(int newEff);
	void moveToIndex(Station& station, size_t currentIndex, size_t newIndex);
};