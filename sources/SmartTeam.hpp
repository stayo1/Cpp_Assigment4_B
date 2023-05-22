#pragma once
#include "Team.hpp"
using namespace std;

namespace ariel
{
    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *);
        void attack(Team *);
        void print() override;
    };
};
