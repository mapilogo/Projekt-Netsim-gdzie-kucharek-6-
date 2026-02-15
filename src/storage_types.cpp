#include "storage_types.hxx"
#include <stdexcept>

Package PackageQueue::pop() {
    Package pack;
    switch (PQT)
    {
    case PackageQueueType::LIFO:
        pack = std::move(list_of_packages.back());
        list_of_packages.pop_back();
        break;
    case PackageQueueType::FIFO:
        pack = std::move(list_of_packages.front());
        list_of_packages.pop_front();
        break;
    default:
        throw std::runtime_error("Invalid PackageQueueType in pop()");
        break;
    }
    return pack;
}