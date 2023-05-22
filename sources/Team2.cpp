#include "Team2.hpp"

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader){};
    void Team2::add(Character *warrior)
    {
        if (!warrior->isAlive())
            throw runtime_error("the warrior is dead");
        if (warrior->getIN() == true)
            throw runtime_error("the warrior is in the team");
        if (MAX_SIZE == this->getSize())
            throw runtime_error("the team is full");
        this->setWarriors(warrior);
        this->setSize(1);
        warrior->setIN();
    }
};
