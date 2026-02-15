#ifndef PACKAGE_TYPES_HPP
#define PACKAGE_TYPES_HPP

#include "types.hxx"
#include <set>

class Package {
public:
    Package();
    Package(ElementID elementID) : eID(elementID) {assigned_IDS.insert(elementID);}
    Package(Package&& package) : eID(package.eID) {}
    ElementID get_id () const {return eID;}
    Package& operator=(Package&& package) noexcept;
    ~Package();
    //operator cza zrobic <- Co?
private:
    ElementID eID;
    static std::set<ElementID> assigned_IDS;
    static std::set<ElementID> freed_IDS;
};

#endif // PACKAGE_TYPES_HPP