#ifndef HERO_H
#define HERO_H

#include <QtGui/QPixmap>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdio.h>

using namespace std;

class Hero {

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

    struct Portrait {
        char data[1024];
    } portrait;

public:
    Hero();
    friend ifstream& operator >> (ifstream& in, Hero& hero);

    char name[16];
    char name2[16];
    char slotsUsed;
    char typus;
    char gender;
    short size;
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
    int unknown10;
    int unknown11;
    char unknown12;
    char unknown13;
    char unknown14;
    char remainingFightRoundsBlended;
    char remainingFightRoundsEcliptifactus;
    char unknown15;
    char protectAgainstMagicFire;
    char invisibleVisibliVanitar;
    char unknown16;
    char unknown17;
    char unknown18;
    char unknown19;
    char unknown20;
    char axxeleratusActivated;
    char drunken;
    char unknown21[8];
    char statusConstitution;
    char statusMagicStuff;
    short unknown22;
    char emptySlotDiseases[5];

    QPixmap portrait;
};

#endif
