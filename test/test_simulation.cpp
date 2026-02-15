#include "gtest/gtest.h"
#include "simulation.hxx"
#include "factory.hxx"


TEST(SpecificTurnsReportNotifierTest, GeneratesReportInCorrectTurns) {
    std::set<Time> turns = {1, 3, 5};
    SpecificTurnsReportNotifier notifier(turns);

    // Powinno generować raport dla tur ze zbioru
    EXPECT_TRUE(notifier.should_generate_report(1));
    EXPECT_TRUE(notifier.should_generate_report(3));
    EXPECT_TRUE(notifier.should_generate_report(5));

    // Nie powinno generować raportu dla tur spoza zbioru
    EXPECT_FALSE(notifier.should_generate_report(2));
    EXPECT_FALSE(notifier.should_generate_report(4));
    EXPECT_FALSE(notifier.should_generate_report(0));
}



TEST(IntervalReportNotifierTest, GeneratesReportInCorrectIntervals) {
    TimeOffset interval = 3;
    IntervalReportNotifier notifier(interval);

    EXPECT_TRUE(notifier.should_generate_report(1));  
    EXPECT_FALSE(notifier.should_generate_report(2));
    EXPECT_FALSE(notifier.should_generate_report(3));
    EXPECT_TRUE(notifier.should_generate_report(4));
    EXPECT_FALSE(notifier.should_generate_report(5));
}

TEST(SimulationTest, FullSimulationSequenceExecution) {
    Factory factory;
    
    // Konfiguracja sieci: Rampa(1) -> Robotnik(1) -> Magazyn(1)
    factory.add_ramp(Ramp(1, 1));
    factory.add_worker(Worker(1, 1, std::make_unique<PackageQueue>(PackageQueueType::FIFO)));
    factory.add_storehouse(Storehouse(1));

    // Połączenia
    factory.find_ramp_by_id(1)->receiver_preferences_.add_receiver(&*factory.find_worker_by_id(1));
    factory.find_worker_by_id(1)->receiver_preferences_.add_receiver(&*factory.find_storehouse_by_id(1));

    // Zmienna do weryfikacji wywołania raportu
    bool report_called = false;

    //**
    //* Symulacja przez 2 tury (indeksy 0 i 1 )
    
    simulate(factory, 2, [&](Factory& f, TimeOffset t) {
        if (t == 1) {
            report_called = true;
            auto storehouse_it = f.find_storehouse_by_id(1);
            EXPECT_FALSE(storehouse_it->get_queue()->empty());
            EXPECT_EQ(storehouse_it->get_queue()->size(), 1U);
        }
    });

    EXPECT_TRUE(report_called);
}