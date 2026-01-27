enum class PackageQueueType {
    FIFO,
    LIFO
};

class IPackageStockpile {
public:
    void push(Package&& package_p);
    bool empty();
    size_t size();
    ~IPackageStockpile();

};

class IPackageQueue : public IPackageStockpile{
public:
    Package pop();
    PackageQueueType get_queue_type();
};
