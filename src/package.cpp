#include "package.hxx"

//definicje klasy Package
Package :: Package() : elementID_(1) {};
Package :: Package(ElementID elementID) : elementID_(elementID) {};
Package :: Package(Package&& package) : elementID_(2) {};
Package :: ~Package() {};
ElementID const Package ::  get_id (){
    return elementID_;
}

