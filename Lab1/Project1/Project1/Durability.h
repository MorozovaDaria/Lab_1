#pragma once

class Durability {
private:
	int value_;
public:
	Durability(int value);
	int getValue() const;
	void setValue(int value);
	void decrease(int amount);
	void repair(int amount);
};