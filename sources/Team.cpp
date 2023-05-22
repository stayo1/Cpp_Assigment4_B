#include "Team.hpp"

namespace ariel
{
    Team::Team(Character *leader)
    {
        this->warriors = new Character *[MAX_SIZE];
        if (leader->getIN() == true)
            throw runtime_error("this warrior is in the team");
        this->leader = leader;
        this->warriors[0] = leader;
        this->size = 1;
        leader->setIN();
    }

    Team::~Team()
    {
        for (int i = 0; i < size; i++)
            delete this->warriors[i];
        delete[] this->warriors;
    }

    void Team::add(Character *warrior)
    {
        if (warrior == nullptr)
            throw runtime_error("there is no enemy");
        if (!warrior->isAlive())
            throw runtime_error("the warrior is dead");
        if (warrior->getIN() == true)
            throw runtime_error("the warrior is in the team");
        if (MAX_SIZE == this->size)
            throw runtime_error("the team is full");
        this->warriors[size] = warrior;
        this->CowboyFirst();
        this->size++;
        warrior->setIN();
    }

    void Team::attack(Team *enemy)
    {
        if (enemy == nullptr)
            throw invalid_argument("There is no enemy to attack");
        if (this == enemy)
            throw runtime_error("cant attack itself");
        if (!this->stillAlive())
            throw runtime_error("The attacker team are dead");
        if (!enemy->stillAlive())
            throw runtime_error("The enemy team are dead");
        leader = FindNearestWarrior(this);
        Character *victim = FindNearestWarrior(enemy);
        for (int i = 0; i < size; i++)
        {
            if (this->warriors[i]->getID() == "Ninja")
                continue;
            if (!victim->isAlive())
            {
                victim = FindNearestWarrior(enemy);
                if (victim == nullptr)
                    return;
            }
            this->warriors[i]->kill(victim);
        }
        for (int i = 0; i < size; i++)
        {
            if (this->warriors[i]->getID() == "Cowboy")
                continue;
            if (!victim->isAlive())
            {
                victim = FindNearestWarrior(enemy);
                if (victim == nullptr)
                    return;
            }
            this->warriors[i]->kill(victim);
        }
    }

    int Team::stillAlive()
    {
        int count = 0;
        for (int i = 0; i < size; i++)
            if (this->warriors[i]->isAlive())
                count++;
        return count;
    }

    void Team::print()
    {
        for (int i = 0; i < size; i++)
            if (this->warriors[i]->getID() == "Cowboy")
                cout << this->warriors[i]->print() << endl;
        for (int i = 0; i < size; i++)
            if (this->warriors[i]->getID() == "Ninja")
                cout << this->warriors[i]->print() << endl;
    }

    bool Team::inTeam(Character *warrior)
    {
        for (int i = 0; i < size; i++)
        {
            if (this->warriors[i] == warrior)
                return true;
        }
        return false;
    }

    Character *Team::FindNearestWarrior(Team *team)
    {
        Character *theOne = NULL;
        double lowDis = DBL_MAX;
        for (int i = 0; i < team->size; i++)
            if (team->warriors[i]->isAlive())
                if (leader->distance(team->warriors[i]) < lowDis)
                {
                    lowDis = leader->distance(team->warriors[i]);
                    theOne = team->warriors[i];
                }
        return theOne;
    }

    void Team::CowboyFirst()
    {
        for (int i = 0; i < this->size; i++)
            for (int j = i + 1; j < this->size; j++)
                if (this->warriors[j]->getID() == "Cowboy" && this->warriors[i]->getID() == "Ninja")
                {
                    Character *tmp = this->warriors[i];
                    this->warriors[i] = this->warriors[j];
                    this->warriors[j] = tmp;
                }
    }

    int Team::getSize()
    {
        return this->size;
    }

    void Team::setSize(int num)
    {
        this->size += num;
    }

    Character *Team::getWarriors(int indx)
    {
        return this->warriors[indx];
    }

    void Team::setWarriors(Character *warrior)
    {
        this->warriors[size] = warrior;
    }

    void Team::setLeader(Character *warrior)
    {
        this->leader = warrior;
    }

};
