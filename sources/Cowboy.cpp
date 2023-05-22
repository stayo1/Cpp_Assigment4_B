#include "Cowboy.hpp"

using namespace std;
namespace ariel
{
    Cowboy::Cowboy(string name, Point location)
        : Character(std::move(name), location, 110), bullets(6) {}

    void Cowboy::shoot(Character *enemy)
    {
        if (enemy == nullptr)
            throw runtime_error("There is no enemy");
        if (!this->isAlive())
            throw runtime_error("The attacker is dead");
        if (!enemy->isAlive())
            throw runtime_error("the enemy is dead");
        if (this == enemy)
            throw runtime_error("cant attack itself");
        if (this->hasboolets())
        {
            enemy->hit(10);
            bullets -= 1;
        }
    }

    bool Cowboy::hasboolets()
    {
        return bullets > 0;
    }

    void Cowboy::reload()
    {
        if (!this->isAlive())
            throw runtime_error("the cowboy is dead");
        bullets = 6;
    }

    string Cowboy::print()
    {
        string stats;
        if (this->isAlive())
            stats = "(C) the warrior name is : " + this->getName() + ", life number is :" + to_string(this->getHealth()) + ", the location is : (" + this->getLocation().print();
        else
            stats = "(C) the warrior name is :  (" + this->getName() + ")" + ", the location is : (" + this->getLocation().print();
        return stats;
    }

    string Cowboy::getID()
    {
        return "Cowboy";
    }

    void Cowboy::kill(Character *enemy)
    {
        if (!isAlive() || !enemy->isAlive())
            return;
        if (!hasboolets())
            reload();
        else
            shoot(enemy);
    }
};
