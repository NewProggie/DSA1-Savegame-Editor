#include "savegame.h"

SaveGame::SaveGame() {

}

ifstream& operator >> (ifstream& in, SaveGame& saveGame) {

    /* read file size */
    in.seekg(0, ios::end);
    int fileSize = in.tellg();
    in.seekg(0, ios::beg);

    /* parse version header */
    in.read((char*)&saveGame.versionHeader, sizeof(SaveGame::VersionHeader));

    /* read chr array offset */
    int chrOffset;
    in.read((char*)&chrOffset, sizeof(int));

    /* read savegame */
    in.read((char*)&saveGame.gameFinished, sizeof(char));
    in.read((char*)&saveGame.numActiveGroup, sizeof(char));
    in.read((char*)&saveGame.numHeroesGroup0, sizeof(char));
    in.read((char*)&saveGame.numHeroesGroup1, sizeof(char));
    in.read((char*)&saveGame.numHeroesGroup2, sizeof(char));
    in.read((char*)&saveGame.numHeroesGroup3, sizeof(char));
    in.read((char*)&saveGame.numHeroesGroup4, sizeof(char));
    in.read((char*)&saveGame.numHeroesGroup5, sizeof(char));
    in.read((char*)&saveGame.numHeroesInGame, sizeof(char));
    in.read((char*)&saveGame.viewDirection, sizeof(char));
    in.read((char*)&saveGame.rest, sizeof(char)*5734);

    int numHeroes = (fileSize-chrOffset) / CHR_SIZE;
    for (int i = 0; i < numHeroes; i++) {

        /* read current hero */
        Hero hero;
        in.seekg(chrOffset+CHR_SIZE*i, ios::beg);
        in >> hero;

        if (hero.idxHeroesGroup == saveGame.numActiveGroup) {
            printf("%s (%d/6)\n", hero.name, hero.posInHeroesGroup);
        }
    }
}
