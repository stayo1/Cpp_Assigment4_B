#pragma once
#include <float.h>
#include <iostream>
#include <stdexcept>
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

using namespace std;

const int MAX_SIZE = 10;

namespace ariel
{
    class Team
    {
    private:
        Character *(*warriors);
        Character *leader;
        int size;

    public:
        virtual ~Team();
        Team(Character *);
        Team(Team &&) = default;
        Team(const Team &) = default;
        Team &operator=(Team &&) = default;
        Team &operator=(const Team &) = default;
        int getSize();
        int stillAlive();
        void setSize(int);
        void CowboyFirst();
        void attack(Team *);
        virtual void print();
        void add(Character *);
        bool inTeam(Character *);
        void setLeader(Character *);
        Character *getWarriors(int);
        void setWarriors(Character *);
        virtual Character *FindNearestWarrior(Team *);
    };
};
