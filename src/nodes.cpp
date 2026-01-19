#include "nodes.hxx"
#include "types.hxx"

//Definicje metod klasy Ramp

Ramp :: Ramp(ElementID id, TimeOffset delivery_interval) : id_(id),delivery_interval_(delivery_interval) {};

TimeOffset Ramp :: get_delivery_interval() const{
    return delivery_interval_;
}

ElementID Ramp :: get_id() const{
    return id_;
}

void Ramp :: deliver_goods(Time t){
    
}

//Definicje metod klasy Worker

Worker :: Worker(ElementID id,TimeOffset processing_duration, std::unique_ptr<IPackageQueue> queue): id_(id),processing_duration_(processing_duration),queue_(queue) {};

void Worker :: do_work(Time t){
    
}
TimeOffset Worker :: get_processing_duration() const{
    return processing_duration_;
}

Time Worker :: get_package_processing_start_time() const{

    }

ElementID Worker :: get_id() const{
    return id_;
}

