#pragma once
#include <vector>	
#include <memory>
#include <string>
#include "Module.h"

class ModuleFactory;
class Station {
private:
	std::vector<std::unique_ptr<Module>> modules_;
	size_t maxModules_;
public:
	Station(size_t maxModules);
	~Station() = default;
	Station(const Station& other);
	Station& operator=(const Station& other);
	Station(Station&& other) noexcept;
	Station& operator=(Station&& other) noexcept;
	bool addModule(std::unique_ptr<Module> module);
	void removeById(int id);
	void removeByIndex(size_t index);
	Module* findById(int id);
	size_t size() const;
	size_t maxSize() const;
	auto begin() { return modules_.begin(); }
	auto end() { return modules_.end(); }
	auto begin() const { return modules_.begin(); }
	auto end() const { return modules_.end(); }
	auto getIterator() { return modules_.begin(); }
	auto getIterator() const { return modules_.begin(); }
	void moveModule(size_t fromIndex, size_t toIndex);
};