#include "types.hxx"

class Package {
public:
    Package();
    Package(ElementID elementID);
    Package(Package&& package);
    ElementID const get_id ();
    ~Package();
    //operator cza zrobic
private:
    ElementID elementID_;
};
