#ifndef STORAGE_TYPES_HPP
#define STORAGE_TYPES_HPP

#include "package.hxx"
#include <list>

enum class PackageQueueType {
    FIFO,
    LIFO
};

class IPackageStockpile {
public:
    virtual void push(Package&& n_package) = 0;
    virtual bool empty() const = 0;
    virtual size_t size() const = 0;
    virtual std::list<Package>::const_iterator begin() const = 0;
    virtual std::list<Package>::const_iterator cbegin() const = 0;
    virtual std::list<Package>::const_iterator end() const = 0;
    virtual std::list<Package>::const_iterator cend() const = 0;
    virtual ~IPackageStockpile() = default;
};

class IPackageQueue : public IPackageStockpile {
public:
    ~IPackageQueue() override = default;
    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() const = 0;
};

class PackageQueue : public IPackageQueue {
public:
    PackageQueue(PackageQueueType type) : PQT(type), list_of_packages() {}
    ~PackageQueue() override = default;
    void push(Package&& n_package) override {
        list_of_packages.emplace_back(std::move(n_package));
    }
    bool empty() const override {
        return list_of_packages.empty();
    }
    size_t size() const override {
        return list_of_packages.size();
    }
    std::list<Package>::const_iterator begin() const override {return list_of_packages.cbegin();}
    virtual std::list<Package>::const_iterator cbegin() const override {return list_of_packages.cbegin();}
    virtual std::list<Package>::const_iterator end() const override {return list_of_packages.cend();}
    virtual std::list<Package>::const_iterator cend() const override {return list_of_packages.cend();}
    Package pop() override;
    PackageQueueType get_queue_type() const override {return PQT;}
private:
    PackageQueueType PQT;
    std::list<Package> list_of_packages;
};

#endif // STORAGE_TYPES_HPP