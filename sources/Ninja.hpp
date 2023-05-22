#pragma once
#include "Character.hpp"

constexpr int YOUNG_HEALTH = 100;
constexpr int TRAINED_HEALTH = 120;
constexpr int OLD_HEALTH = 150;
constexpr int YOUNG_SPEED = 14;
constexpr int TRAINED_SPEED = 12;
constexpr int OLD_SPEED = 8;

namespace ariel
{
    class Ninja : public Character
    {
    private:
        int speed;

    public:
        Ninja(Ninja &&) = default;
        ~Ninja() override = default;
        Ninja(const Ninja &) = default;
        Ninja(string, Point, int, int);
        Ninja &operator=(Ninja &&) = default;
        Ninja &operator=(const Ninja &) = default;
        void move(Character *);
        void slash(Character *);
        string print() override;
        string getID() override;
        void kill(Character *enemy) override;
    };
}