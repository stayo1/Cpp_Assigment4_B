#include "Ninja.hpp"

namespace ariel
{
    Ninja::Ninja(string name, Point location, int health, int speed)
        : Character(std::move(name), location, health), speed(speed) {}

    void Ninja::move(Character *enemy)
    {
        if (!this->isAlive())
            return;
        this->setLocation(Point::moveTowards(this->getLocation(), enemy->getLocation(), speed));
    }

    void Ninja::slash(Character *enemy)
    {
        if (enemy == nullptr)
            throw runtime_error("There is no enemy");
        if (!this->isAlive())
            throw runtime_error("The attacker is dead");
        if (!enemy->isAlive())
            throw runtime_error("the enemy is dead");
        if (this == enemy)
            throw runtime_error("cant attack itself");
        if (this->isAlive() && this->distance(enemy) < 1)
            enemy->hit(40);
    }

    string Ninja::print()
    {
        string stats;
        if (this->isAlive())
            stats = "(N) the warrior name is : " + this->getName() + ", life number is :" + to_string(this->getHealth()) + ", the location is : (" + this->getLocation().print();
        else
            stats = "(N) the warrior name is :  (" + this->getName() + ")" + ", the location is : (" + this->getLocation().print();
        return stats;
    }

    string Ninja::getID()
    {
        return "Ninja";
    }

    void Ninja::kill(Character *enemy)
    {
        if (!this->isAlive())
            return;
        if (!enemy->isAlive())
            return;
        if (distance(enemy) < 1)
            slash(enemy);
        else
            move(enemy);
    }
}
