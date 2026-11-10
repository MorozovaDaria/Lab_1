#pragma once

class EnergyConsumption {
private:
	int value_;
public:
	EnergyConsumption(int value);
	int getValue() const;
	void setValue(int value);
	void increase(int amount);
	void decrease(int amount);
};