#include "hero.h"

Hero::Hero() {

}

ifstream& operator >> (ifstream& in, Hero& hero) {

    /* read hero attributes */
    in.read((char*)&hero.name, sizeof(char)*16);
    in.read((char*)&hero.name2, sizeof(char)*16);
    in.read((char*)&hero.slotsUsed, sizeof(char));
    in.read((char*)&hero.typus, sizeof(char));
    in.read((char*)&hero.gender, sizeof(char));
    in.read((char*)&hero.size, sizeof(short));
    in.read((char*)&hero.weight, sizeof(char));
    in.read((char*)&hero.god, sizeof(char));
    in.read((char*)&hero.level, sizeof(char));

    in.read((char*)&hero.exp, sizeof(int));
    in.read((char*)&hero.money, sizeof(int));
    in.read((char*)&hero.rsBonus1, sizeof(char));
    in.read((char*)&hero.rsBonus2, sizeof(char));
    in.read((char*)&hero.rsHandycap, sizeof(char));
    in.read((char*)&hero.remainingBP, sizeof(char));

    /* positive properties */
    in.read((char*)&hero.courage, sizeof(Hero::CharacterTrait));
    in.read((char*)&hero.intelligence, sizeof(Hero::CharacterTrait));
    in.read((char*)&hero.charisma, sizeof(Hero::CharacterTrait));
    in.read((char*)&hero.dexterity, sizeof(Hero::CharacterTrait));
    in.read((char*)&hero.agility, sizeof(Hero::CharacterTrait));
    in.read((char*)&hero.intuition, sizeof(Hero::CharacterTrait));
    in.read((char*)&hero.strength, sizeof(Hero::CharacterTrait));

    /* negative properties */
    in.read((char*)&hero.superstition, sizeof(Hero::CharacterTrait));
    in.read((char*)&hero.vertigo, sizeof(Hero::CharacterTrait));
    in.read((char*)&hero.claustrophobia, sizeof(Hero::CharacterTrait));
    in.read((char*)&hero.greed, sizeof(Hero::CharacterTrait));
    in.read((char*)&hero.necrophobia, sizeof(Hero::CharacterTrait));
    in.read((char*)&hero.curiosity, sizeof(Hero::CharacterTrait));
    in.read((char*)&hero.temper, sizeof(Hero::CharacterTrait));

    in.read((char*)&hero.vitalEnergyCurrent, sizeof(short));
    in.read((char*)&hero.vitalEnergyMax, sizeof(short));
    in.read((char*)&hero.astralEnergyCurrent, sizeof(short));
    in.read((char*)&hero.astralEnergyMax, sizeof(short));
    in.read((char*)&hero.magicResistance, sizeof(char));
    in.read((char*)&hero.basisAttackParade, sizeof(char));

    in.read((char*)&hero.attVals, sizeof(Hero::AttackValues));
    in.read((char*)&hero.parVals, sizeof(Hero::ParadeValues));

    in.read((char*)&hero.attBonWeapon, sizeof(char));
    in.read((char*)&hero.parBonWeapon, sizeof(char));
    in.read((char*)&hero.weaponType, sizeof(char));
    in.read((char*)&hero.currAttackModifier, sizeof(char));
    in.read((char*)&hero.permVitEnergLoss, sizeof(char));
    in.read((char*)&hero.unknown1, sizeof(char));
    in.read((char*)&hero.unknown2, sizeof(char));
    in.read((char*)&hero.unknown3, sizeof(char));
    in.read((char*)&hero.unknown4, sizeof(char));
    in.read((char*)&hero.hunger, sizeof(char));
    in.read((char*)&hero.thirst, sizeof(char));
    in.read((char*)&hero.unknown5, sizeof(char));
    in.read((char*)&hero.viewDirection, sizeof(char));
    in.read((char*)&hero.numLeftActionsPerFightRound, sizeof(char));
    in.read((char*)&hero.unknown6, sizeof(char));
    in.read((char*)&hero.unknown7, sizeof(char));
    in.read((char*)&hero.fightIdLastEnemey, sizeof(char));
    in.read((char*)&hero.idxHeroesGroup, sizeof(char));
    in.read((char*)&hero.unknown8, sizeof(char));
    in.read((char*)&hero.unknown9, sizeof(char));
    in.read((char*)&hero.posInHeroesGroup, sizeof(char));
}
