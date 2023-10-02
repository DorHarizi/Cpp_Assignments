#pragma once

#include "Team.hpp"
using namespace std;
using namespace ariel;

namespace ariel {
    class Team2 : public Team {
        public:
            Team2(Character *leader);

            void findNewLeader();

            void findNewVictim(Character **victim, Team *enemyTeam);

            void attack(Team *enemyTeam);

        };
}

