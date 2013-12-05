#ifndef SAVEGAME_H
#define SAVEGAME_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include "hero.h"

#define CHR_SIZE 1754

class SaveGame {

    struct VersionHeader {
        char identifier[12];
        char unknown;
        char gamenumber;
        char major;
        char minor;
    };

public:
    SaveGame();
    friend ifstream& operator >> (ifstream& in, SaveGame& saveGame);

    VersionHeader versionHeader;
    char gameFinished;
    char numActiveGroup;
    char numHeroesGroup0;
    char numHeroesGroup1;
    char numHeroesGroup2;
    char numHeroesGroup3;
    char numHeroesGroup4;
    char numHeroesGroup5;
    char numHeroesInGame;
    char viewDirection;
    char rest[5734];
};

#endif
