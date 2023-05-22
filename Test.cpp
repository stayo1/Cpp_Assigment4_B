#include "doctest.h"
#include "sources/Point.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Ninja.hpp"
#include "sources/Team.hpp"
#include "sources/SmartTeam.hpp"

using namespace ariel;

TEST_CASE("points checks")
{
    Point a(1, 0);
    Point b(5, 0);
    Point c = Point::moveTowards(a, b, 2.2);

    CHECK(a.distance(b) == 4);
    CHECK(a.distance(a) == 0);
    CHECK_FALSE(a.distance(b) == 2);
    CHECK(a.distance(c) == 2.2);
}

TEST_CASE("characters checks")
{
    YoungNinja A("alice", Point(1, 0));
    TrainedNinja L("luka", Point(2, 0));
    OldNinja E("eli", Point(3, 0));
    Cowboy B("bob", Point(4, 0));
    Cowboy T("troy", Point(5, 0));

    CHECK(A.isAlive());
    CHECK(L.isAlive());
    CHECK(E.isAlive());
    CHECK(B.isAlive());
    CHECK(T.isAlive());

    int i = 0;
    while (i < 6)
    {
        B.shoot(&A);
        i++;
    }
    CHECK(B.hasboolets());

    int health1 = L.getHealth();
    int health2 = T.getHealth();
    B.shoot(&L);
    L.slash(&T);
    CHECK(health1 == L.getHealth());
    CHECK(health2 == T.getHealth());
    CHECK_THROWS(B.shoot(&B));

    CHECK(A.getHealth() < L.getHealth());
    CHECK(L.getHealth() < E.getHealth());
}

TEST_CASE("teams checks")
{
    YoungNinja *n1 = new YoungNinja("avi", Point(1, 0));
    YoungNinja *n2 = new YoungNinja("aviv", Point(2, 0));
    YoungNinja *n3 = new YoungNinja("aviv", Point(3, 0));
    Team team1(n1);
    Team team2(n2);
    SmartTeam team3(n3);

    int i = 0;
    while (i < 10)
    {
        team1.add(new Cowboy("amir", Point(1, 1)));
        i++;
    }
    CHECK_THROWS(team1.add(new Cowboy("amir", Point(1, 1))));
    CHECK_THROWS(team1.add(n1));
    CHECK_THROWS(team2.attack(&team2));
    CHECK_THROWS(team2.attack(NULL));

    CHECK(team3.stillAlive());
}