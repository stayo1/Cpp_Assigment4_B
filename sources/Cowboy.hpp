#pragma once
#include "Character.hpp"
using namespace std;

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int bullets;

    public:
        Cowboy(string, Point);
        Cowboy(Cowboy &&) = default;
        ~Cowboy() override = default;
        Cowboy(const Cowboy &) = default;
        Cowboy &operator=(Cowboy &&) = default;
        Cowboy &operator=(const Cowboy &) = default;
        void reload();
        bool hasboolets();
        void shoot(Character *);
        string print() override;
        string getID() override;
        void kill(Character *enemy) override;
    };
}