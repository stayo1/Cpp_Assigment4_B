#pragma once
#include "Ninja.hpp"

namespace ariel
{
    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(string name, Point location) : Ninja(std::move(name), location, YOUNG_HEALTH, YOUNG_SPEED) {}
    };
}