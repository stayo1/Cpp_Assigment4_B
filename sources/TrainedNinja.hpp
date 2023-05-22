#pragma once
#include "Ninja.hpp"

namespace ariel
{
    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(string name, Point location) : Ninja(std::move(name), location, TRAINED_HEALTH, TRAINED_SPEED) {}
    };
}
