#include "Station.h"
#include <stdexcept>

Station::Station(size_t maxModules) : maxModules_(maxModules) {
    if (maxModules == 0) {
        throw std::invalid_argument("Error");
    }
}
bool Station::addModule(std::unique_ptr<Module> module) {
    if (modules_.size() >= maxModules_) {
        return false;
    }
    modules_.push_back(std::move(module));
    return true;
}
Module* Station::findById(int id) {
    for (size_t i = 0; i < modules_.size(); ++i) {
        if (modules_[i]->getID() == id) {
            return modules_[i].get();
        }
    }
    return nullptr;
}
void Station::removeByIndex(size_t index) {
    if (index >= modules_.size()) {
        throw std::out_of_range("Error");
    }
    modules_.erase(modules_.begin() + index);
}
void Station::removeById(int id) {
    for (size_t i = 0; i < modules_.size(); ++i) {
        if (modules_[i]->getID() == id) {
            removeByIndex(i);
            return;
        }
    }
}
size_t Station::size() const {
    return modules_.size();
}
size_t Station::maxSize() const {
    return maxModules_;
}
Station::Station(const Station& other) : maxModules_(other.maxModules_) {
    modules_.reserve(other.modules_.size());
    for (const auto& module : other.modules_) {
        modules_.push_back(std::unique_ptr<Module>(module->clone()));
    }
}
Station& Station::operator=(const Station& other) {
    if (this != &other) {
        maxModules_ = other.maxModules_;
        modules_.clear();
        modules_.reserve(other.modules_.size());
        for (const auto& module : other.modules_) {
            modules_.push_back(std::unique_ptr<Module>(module->clone()));
        }
    }
    return *this;
}
Station::Station(Station&& other) noexcept
    : modules_(std::move(other.modules_)), maxModules_(other.maxModules_) {
}
Station& Station::operator=(Station&& other) noexcept {
    if (this != &other) {
        modules_ = std::move(other.modules_);
        maxModules_ = other.maxModules_;
    }
    return *this;
}
void Station::moveModule(size_t fromIndex, size_t toIndex) {
    if (fromIndex >= modules_.size() || toIndex >= modules_.size()) {
        throw std::out_of_range("Error");
    }
    if (fromIndex == toIndex) {
        return;
    }
    std::unique_ptr<Module> moduleToMove = std::move(modules_[fromIndex]);
    modules_.erase(modules_.begin() + fromIndex);
    if (fromIndex < toIndex) {
        modules_.insert(modules_.begin() + toIndex - 1, std::move(moduleToMove));
    }
    else {
        modules_.insert(modules_.begin() + toIndex, std::move(moduleToMove));
    }
}