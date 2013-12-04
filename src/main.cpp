#include <QApplication>
#include "mainwindow.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdio.h>

#define CHR_SIZE 1754

struct VersionHeader {
  char identifier[12];
  char unknown;
  char gamenumber;
  char major;
  char minor;
} versionHeader;

struct SaveGame {
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
} saveGame;

struct Portrait {
  char data[1024];
} portrait;

struct CharacterTrait {
  char normal;
  char current;
  char modifier;
};

struct AttackValues {
  char att1;
  char att2;
  char att3;
  char att4;
  char att5;
  char att6;
  char att7;
};

struct ParadeValues {
  char par1;
  char par2;
  char par3;
  char par4;
  char par5;
  char par6;
  char par7;
};

struct Hero {
  char name[16];
  char name2[16];
  char slotsUsed;
  char typus;
  char gender;
  char size;
  char weight;
  char god;
  char level;
  int exp;
  int money;
  char rsBonus1;
  char rsBonus2;
  char rsHandycap;
  char remainingBP;
  /* positive properties */
  CharacterTrait courage;
  CharacterTrait intelligence;
  CharacterTrait charisma;
  CharacterTrait dexterity;
  CharacterTrait agility;
  CharacterTrait intuition;
  CharacterTrait strength;
  /* negative properties */
  CharacterTrait superstition;
  CharacterTrait vertigo;
  CharacterTrait claustrophobia;
  CharacterTrait greed;
  CharacterTrait necrophobia;
  CharacterTrait curiosity;
  CharacterTrait temper;
  short vitalEnergyCurrent;
  short vitalEnergyMax;
  short astralEnergyCurrent;
  short astralEnergyMax;
  char magicResistance;
  char basisAttackParade;
  AttackValues attVals;
  ParadeValues parVals;
  char attBonWeapon;
  char parBonWeapon;
  char weaponType;
  char currAttackModifier;
  char permVitEnergLoss;
  char unknown1;
  char unknown2;
  char unknown3;
  char unknown4;
  char hunger;
  char thirst;
  char unknown5;
  char viewDirection;
  char numLeftActionsPerFightRound;
  char unknown6;
  char unknown7;
  char fightIdLastEnemey;
  char idxHeroesGroup;
  char unknown8;
  char unknown9;
  char posInHeroesGroup;

} hero;

using namespace std;

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    MainWindow mainWin;
    mainWin.show();

    return app.exec();

  /* check command line args for filename */
  if (argc != 2) {
    std::cerr << "Usage is " << argv[0] << " FILE.GAM" << std::endl;
    return 1;
  }

  /* read version header */
  fstream in(argv[1], ios::in | ios::binary);

  /* read file size */
  in.seekg(0, ios::end);
  int fileSize = in.tellg();
  in.seekg(0, ios::beg);

  in.read((char*)&versionHeader, sizeof(VersionHeader));

  /* read chr array offset */
  int chrOffset;
  in.read((char*)&chrOffset, sizeof(int));

  /* read savegame */
  in.read((char*)&saveGame, sizeof(SaveGame));

  int numHeroes = (fileSize-chrOffset) / CHR_SIZE;
  for (int i=0; i<numHeroes; i++) {
    /* read hero */
    in.seekg(chrOffset+CHR_SIZE*i, ios::beg);
    in.read((char*)&hero, sizeof(Hero));

    if (hero.idxHeroesGroup == saveGame.numActiveGroup) {
      printf("%s (%d/6)\n", hero.name, hero.posInHeroesGroup);
    }
  }

  in.close();
  
  return 0;
}
