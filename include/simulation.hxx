#ifndef NETSIM_SIMULATION_HXX
#define NETSIM_SIMULATION_HXX

#include "factory.hxx"
#include <set>
#include <functional>

class IntervalReportNotifier {
public:
    explicit IntervalReportNotifier(TimeOffset to) : to_(to) {}
    bool should_generate_report(Time t) const { return t == 1 || t % to_ == 1; }
private:
    TimeOffset to_;
};

class SpecificTurnsReportNotifier {
public:
    explicit SpecificTurnsReportNotifier(const std::set<Time>& turns) : turns_(turns) {}
    bool should_generate_report(Time t) const { return turns_.find(t) != turns_.end(); }
private:
    std::set<Time> turns_;
};

void simulate(Factory& factory, TimeOffset d, std::function<void(Factory&, TimeOffset)>&& rf);

#endif
