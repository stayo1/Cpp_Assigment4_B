#pragma once
#include <string>
#include "Point.hpp"
using namespace std;

namespace ariel
{
    class Character
    {
    private:
        Point location;
        string name;
        int health;
        bool IN = false;

    public:
        Character(string, Point, int);
        virtual ~Character() = default;
        Character(Character &&) = default;
        Character(const Character &) = default;
        Character &operator=(Character &&) = default;
        Character &operator=(const Character &) = default;
        bool getIN();
        void setIN();
        void hit(int);
        bool isAlive();
        int getHealth();
        string getName();
        Point getLocation();
        void setLocation(Point);
        virtual string print() = 0;
        virtual string getID() = 0;
        double distance(Character *);
        virtual void kill(Character *) = 0;
    };
}