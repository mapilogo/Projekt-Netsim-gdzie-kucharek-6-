#include "package.hxx"

std::set<ElementID> Package::assigned_IDS = {};
std::set<ElementID> Package::freed_IDS = {};

//nie kopiuje, a przesuwa ID
Package& Package::operator=(Package&& package) noexcept {
    if (this == &package)
        return *this;
    assigned_IDS.erase(this->eID);
    freed_IDS.insert(this->eID);
    this->eID = package.eID;
    assigned_IDS.insert(this->eID);
    return *this;
}

//Przypisanie ID do nowej paczki
Package :: Package() {
    if (freed_IDS.empty()){
        if (assigned_IDS.empty()) {
            eID = 1;
        }
        else {
            eID = *assigned_IDS.end() + 1;
        }
    }
    else {
        eID = *freed_IDS.begin();
        freed_IDS.erase(eID);
    }
    assigned_IDS.insert(eID);    
}

//destruktor
Package :: ~Package() {
    freed_IDS.insert(eID);
    assigned_IDS.erase(eID);
};

