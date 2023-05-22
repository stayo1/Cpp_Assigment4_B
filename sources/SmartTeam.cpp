#include "SmartTeam.hpp"

namespace ariel
{
    SmartTeam::SmartTeam(Character *leader) : Team(leader){};
    void SmartTeam::attack(Team *enemy)
    {
        setLeader(FindNearestWarrior(this));
        if (!enemy->stillAlive())
            return;
        if (enemy == nullptr)
            throw invalid_argument("There is no enemy to attack");
        for (int i = 0; i < this->getSize(); i++)
        {
            Character *victim = nullptr;
            if (getWarriors(i)->getID() == "Cowboy")
            {
                for (int j = 0; j < enemy->getSize(); j++)
                {
                    if (enemy->getWarriors(j)->isAlive() && enemy->getWarriors(j)->getHealth() <= 10)
                    {
                        victim = enemy->getWarriors(j);
                    }
                }
            }
            else
            {
                int blood = 0;
                for (int j = 0; j < enemy->getSize(); j++)
                {
                    if (enemy->getWarriors(j)->isAlive())
                        if (getWarriors(i)->distance(enemy->getWarriors(j)) < 1 && blood < enemy->getWarriors(j)->getHealth())
                        {
                            blood = enemy->getWarriors(j)->getHealth();
                            victim = enemy->getWarriors(j);
                        }
                }
                if (victim == nullptr)
                    victim = FindNearestWarrior(enemy);
            }
            this->getWarriors(i)->kill(victim);
        }
    }

    void SmartTeam::print()
    {
        for (int i = 0; i < this->getSize(); i++)
            if (this->getWarriors(i)->isAlive() && this->getWarriors(i)->getID() == "Cowboy")
                cout << getWarriors(i)->print() << endl;
        for (int j = 0; j < this->getSize(); j++)
            if (this->getWarriors(j)->isAlive() && this->getWarriors(j)->getID() == "Ninja")
                cout << getWarriors(j)->print() << endl;
    }
};
