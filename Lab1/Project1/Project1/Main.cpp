#include <iostream>
#include <memory>
#include <vector>
#include "Station.h"
#include "ModuleFactory.h"
#include "StandardModuleFactory.h"
#include "AdvancedModuleFactory.h"
#include "CrewCabin.h"
#include "MedicalCabin.h"
#include "SolarModule.h"
#include "ReactorModule.h"
#include "BiologyLab.h"
#include "PhysicsLab.h"

int main() {
    setlocale(LC_ALL, "RU");

    std::cout << "Сценарий 1: Создание станции и добавление модулей" << std::endl;
    Station station(5);
    StandardModuleFactory standardFactory;
    AdvancedModuleFactory advancedFactory;

    station.addModule(std::unique_ptr<Module>(standardFactory.createApartmentModule("CrewCabin", 90, 100, 10, 5)));
    station.addModule(std::unique_ptr<Module>(standardFactory.createEnergyModule("SolarModule", 85, 80, 50, 20)));
    station.addModule(std::unique_ptr<Module>(advancedFactory.createResearchModule("PhysicsLab", 95, 90, 30, 10)));

    std::cout << "Модулей на станции: " << station.size() << std::endl;
    for (const auto& module : station) {
        std::cout << "ID: " << module->getID() << " | Type: " << module->getType() << " | Name: " << module->getName() << " | State: " << module->getCondition() << std::endl;
    }

    std::cout << "\nСценарий 2: Копирование станции (глубокое)" << std::endl;
    Station copyStation = station;
    Module* copyModule = copyStation.findById(1);
    if (copyModule != nullptr) {
        copyModule->activate();
        std::cout << "Состояние модуля в копии: " << copyModule->getCondition() << std::endl;
    }
    Module* origModule = station.findById(1);
    if (origModule != nullptr) {
        std::cout << "Состояние модуля в оригинале: " << origModule->getCondition() << std::endl;
    }

    std::cout << "\nСценарий 3: Поиск и удаление" << std::endl;
    Module* found = station.findById(2);
    if (found != nullptr) {
        std::cout << "Найден модуль: " << found->getName() << std::endl;
    }
    station.removeById(2);
    std::cout << "После удаления по ID, размер: " << station.size() << std::endl;
    station.removeByIndex(0);
    std::cout << "После удаления по индексу, размер: " << station.size() << std::endl;

    std::cout << "\nСценарий 4: Итерация и действия" << std::endl;
    for (auto& module : station) {
        module->activate();
        std::cout << "Модуль " << module->getName() << " активирован. Состояние: " << module->getCondition() << std::endl;
    }

    std::cout << "\nСценарий 5: Перемещение станции (move-семантика)" << std::endl;
    Station movedStation = std::move(copyStation);
    std::cout << "Размер перемещенной станции: " << movedStation.size() << std::endl;
    std::cout << "Размер исходной станции после перемещения: " << copyStation.size() << std::endl;

    std::cout << "\nСценарий 6: Перемещение модуля внутри станции" << std::endl;
    Station moveTest(3);
    moveTest.addModule(std::unique_ptr<Module>(standardFactory.createApartmentModule("CrewCabin", 50, 50, 5, 5)));
    moveTest.addModule(std::unique_ptr<Module>(standardFactory.createApartmentModule("MedicalCabin", 50, 50, 5, 5)));
    moveTest.moveModule(0, 1);
    std::cout << "После перемещения модулей:" << std::endl;
    for (const auto& m : moveTest) {
        std::cout << "ID: " << m->getID() << " | Name: " << m->getName() << std::endl;
    }

    return 0;
}