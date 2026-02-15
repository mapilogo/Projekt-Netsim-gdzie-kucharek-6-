#include "gtest/gtest.h"
#include "simulation.hxx"
#include "factory.hxx"

TEST(SimulationTest, ThrowsExceptionOnInconsistentFactory) {
    Factory factory;
    factory.add_ramp(Ramp(1, 1));
    
    EXPECT_THROW({
        try {
            simulate(factory, 1, [](Factory&, TimeOffset) {});
        } catch (const std::logic_error& e) {
            EXPECT_STREQ("Non-consistent factory", e.what());
            throw;
        }
    }, std::logic_error);
}

TEST(SimulationTest, CallbackExecutionCount) {
    Factory factory;
    factory.add_storehouse(Storehouse(1));
    factory.add_ramp(Ramp(1, 1));
    factory.find_ramp_by_id(1)->receiver_preferences_.add_receiver(&*factory.find_storehouse_by_id(1));

    int call_count = 0;
    TimeOffset duration = 5;
    
    simulate(factory, duration, [&call_count](Factory&, TimeOffset) {
        call_count++;
    });

    EXPECT_EQ(call_count, duration);
}

TEST(SimulationTest, IntegrationPackageFlow) {
    Factory factory;
    
    factory.add_ramp(Ramp(1, 1));
    factory.add_worker(Worker(1, 1, std::make_unique<PackageQueue>(PackageQueueType::FIFO)));
    factory.add_storehouse(Storehouse(1));

    factory.find_ramp_by_id(1)->receiver_preferences_.add_receiver(&*factory.find_worker_by_id(1));
    factory.find_worker_by_id(1)->receiver_preferences_.add_receiver(&*factory.find_storehouse_by_id(1));

    simulate(factory, 3, [](Factory&, TimeOffset) {});

    auto storehouse_it = factory.find_storehouse_by_id(1);
    EXPECT_FALSE(storehouse_it->get_queue()->empty());
}

TEST(SimulationTest, NotifierIntegrationWithZeroIndex) {
    IntervalReportNotifier notifier(2);
    Factory factory;
    factory.add_storehouse(1);
    
    std::vector<TimeOffset> reported_turns;
    
    simulate(factory, 3, [&](Factory& f, TimeOffset t) {
        if (notifier.should_generate_report(t)) {
            reported_turns.push_back(t);
        }
    });

    ASSERT_EQ(reported_turns.size(), 1);