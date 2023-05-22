#pragma once
#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
    public:
        OldNinja(string name, Point location) : Ninja(std::move(name), location, OLD_HEALTH, OLD_SPEED) {}
    };
}