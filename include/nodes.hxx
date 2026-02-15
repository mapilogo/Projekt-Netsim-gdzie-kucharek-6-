#ifndef NODES_HPP_
#define NODES_HPP_

#include <functional>
#include "types.hxx"
#include "package.hxx"
#include <memory>
#include <optional>
#include "storage_types.hxx"
#include "helpers.hxx"

// class IPackageReceiver{
// public:
//     virtual void receive_package(Package&& package) = 0;
//     virtual ElementID get_id() const = 0;
//     virtual ~IPackageReceiver() = default;
// };


// class ReceiverPreferences{

// public:
//     using preferences_t = int; //do zmiany 
//     ReceiverPreferences(ProbabilityGenerator propability_generator);
//     void add_receiver(IPackageReceiver* receiver);
//     void remove_receiver(IPackageReceiver* receiver);
//     IPackageReceiver* choose_receiver();
//     const preferences_t& get_preferences() const;

// private:
//     ProbabilityGenerator propability_generaotor_;
//     preferences_t preferences_;
// };

// class PackageSender{

// public:
//     PackageSender() = default;
//     PackageSender(PackageSender&& movable) = default;
//     void send_package();
//     std::optional<Package>& get_sending_buffer();
//     ReceiverPreferences receiver_preferences_;
// private:
//     void push_package(Package&& package);
// };


// class Ramp : public PackageSender{

// public:
//     Ramp(ElementID id, TimeOffset delivery_interval);
//     void deliver_goods(Time time);
//     TimeOffset get_delivery_interval() const;
//     ElementID get_id() const;  

// private:
//     ElementID id_;
//     TimeOffset delivery_interval_;
// };

// class Worker : public PackageSender, public IPackageReceiver{

// public:
//     Worker(ElementID id,TimeOffset processing_duration, std::unique_ptr<IPackageQueue> queue);
//     void do_work(Time time);
//     TimeOffset get_processing_duration() const;
//     Time get_package_processing_start_time() const;

//     void receive_package(Package&& package) override;
//     ElementID get_id() const override;

// private:
//     ElementID id_;
//     TimeOffset processing_duration_;
//     std :: unique_ptr<IPackageQueue> queue_;
// };

// class Storehouse : public IPackageReceiver{

// public:
//     Storehouse(ElementID id, std::unique_ptr<IPackageStockpile> data);

//     void receive_package(Package&& package) override;
//     ElementID get_id() const override;

// private:
//     ElementID id_;
//     std :: unique_ptr<IPackageStockpile> data_;
// };


#endif /* NODES_HPP_ */