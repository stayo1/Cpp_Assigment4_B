#include "Character.hpp"
using namespace std;

namespace ariel
{
    Character::Character(string name, Point location, int health)
        : name(std::move(name)), location(location), health(health) {}

    Point Character::getLocation()
    {
        return this->location;
    }

    void Character::setLocation(Point dest)
    {
        this->location = dest;
    }

    int Character::getHealth()
    {
        return this->health;
    }

    string Character::getName()
    {
        return this->name;
    }

    bool Character::isAlive()
    {
        return this->health > 0;
    }

    double Character::distance(Character *other)
    {
        return this->location.distance(other->location);
    }

    void Character::hit(int life)
    {
        if (life < 0)
            throw invalid_argument("only positive integer");
        this->health -= life;
        if (this->health < 0)
            this->health = 0;
    }

    bool Character::getIN()
    {
        return this->IN;
    }

    void Character::setIN()
    {
        this->IN = true;
    }
}
