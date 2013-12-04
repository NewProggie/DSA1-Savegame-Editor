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

cv::Vec3b colorMapping(uchar value) {

  /* FIXME: generated from http://obiwahn.h2174870.stratoserver.net/mediawiki/index.php?title=Palette#1 */
  switch (value) {
  case 0: return cv::Vec3b(0,0,0);
  case 1: return cv::Vec3b(48,64,32);
  case 2: return cv::Vec3b(80,32,16);
  case 3: return cv::Vec3b(80,64,16);
  case 4: return cv::Vec3b(64,64,64);
  case 5: return cv::Vec3b(64,96,64);
  case 6: return cv::Vec3b(128,48,16);
  case 7: return cv::Vec3b(64,112,96);
  case 8: return cv::Vec3b(128,96,32);
  case 9: return cv::Vec3b(128,96,64);
  case 10: return cv::Vec3b(80,144,64);
  case 11: return cv::Vec3b(112,112,96);
  case 12: return cv::Vec3b(176,64,16);
  case 13: return cv::Vec3b(48,112,144);
  case 14: return cv::Vec3b(128,144,48);
  case 15: return cv::Vec3b(80,144,112);
  case 16: return cv::Vec3b(192,96,32);
  case 17: return cv::Vec3b(112,160,96);
  case 18: return cv::Vec3b(64,176,144);
  case 19: return cv::Vec3b(192,112,80);
  case 20: return cv::Vec3b(208,112,48);
  case 21: return cv::Vec3b(192,144,48);
  case 22: return cv::Vec3b(64,176,160);
  case 23: return cv::Vec3b(128,176,128);
  case 24: return cv::Vec3b(176,160,96);
  case 25: return cv::Vec3b(224,144,48);
  case 26: return cv::Vec3b(144,192,128);
  case 27: return cv::Vec3b(192,176,128);
  case 28: return cv::Vec3b(208,192,96);
  case 29: return cv::Vec3b(208,208,128);
  case 30: return cv::Vec3b(192,192,176);
  case 31: return cv::Vec3b(224,224,192);
  case 32: return cv::Vec3b(0,0,0);
  case 33: return cv::Vec3b(0,0,252);
  case 34: return cv::Vec3b(0,0,144);
  case 35: return cv::Vec3b(240,192,160);
  case 36: return cv::Vec3b(240,176,144);
  case 37: return cv::Vec3b(240,160,112);
  case 38: return cv::Vec3b(224,144,96);
  case 39: return cv::Vec3b(208,128,80);
  case 40: return cv::Vec3b(192,112,80);
  case 41: return cv::Vec3b(160,96,64);
  case 42: return cv::Vec3b(144,80,48);
  case 43: return cv::Vec3b(112,64,48);
  case 44: return cv::Vec3b(96,48,32);
  case 45: return cv::Vec3b(80,48,32);
  case 46: return cv::Vec3b(224,224,224);
  case 47: return cv::Vec3b(192,192,192);
  case 48: return cv::Vec3b(176,176,176);
  case 49: return cv::Vec3b(160,160,160);
  case 50: return cv::Vec3b(128,128,128);
  case 51: return cv::Vec3b(112,112,112);
  case 52: return cv::Vec3b(80,80,80);
  case 53: return cv::Vec3b(64,64,64);
  case 54: return cv::Vec3b(0,252,0);
  case 55: return cv::Vec3b(0,144,0);
  case 56: return cv::Vec3b(240,224,0);
  case 57: return cv::Vec3b(208,176,0);
  case 58: return cv::Vec3b(160,128,0);
  case 59: return cv::Vec3b(240,96,64);
  case 60: return cv::Vec3b(192,64,32);
  case 61: return cv::Vec3b(144,48,16);
  case 62: return cv::Vec3b(64,32,16);
  case 63: return cv::Vec3b(240,240,240);
  case 64: return cv::Vec3b(0,0,0);
  case 65: return cv::Vec3b(224,224,224);
  case 66: return cv::Vec3b(208,208,208);
  case 67: return cv::Vec3b(192,192,192);
  case 68: return cv::Vec3b(176,176,176);
  case 69: return cv::Vec3b(160,160,160);
  case 70: return cv::Vec3b(144,144,144);
  case 71: return cv::Vec3b(128,128,128);
  case 72: return cv::Vec3b(112,112,112);
  case 73: return cv::Vec3b(96,96,96);
  case 74: return cv::Vec3b(80,80,80);
  case 75: return cv::Vec3b(64,64,64);
  case 76: return cv::Vec3b(48,48,48);
  case 77: return cv::Vec3b(32,32,32);
  case 78: return cv::Vec3b(240,240,240);
  case 79: return cv::Vec3b(240,208,96);
  case 80: return cv::Vec3b(240,208,32);
  case 81: return cv::Vec3b(240,208,0);
  case 82: return cv::Vec3b(224,192,0);
  case 83: return cv::Vec3b(208,176,0);
  case 84: return cv::Vec3b(192,160,0);
  case 85: return cv::Vec3b(176,144,0);
  case 86: return cv::Vec3b(160,128,0);
  case 87: return cv::Vec3b(144,112,0);
  case 88: return cv::Vec3b(128,96,0);
  case 89: return cv::Vec3b(112,80,0);
  case 90: return cv::Vec3b(224,80,48);
  case 91: return cv::Vec3b(208,48,0);
  case 92: return cv::Vec3b(176,32,0);
  case 93: return cv::Vec3b(144,16,0);
  case 94: return cv::Vec3b(112,0,0);
  case 95: return cv::Vec3b(80,0,0);
  case 96: return cv::Vec3b(180,252,180);
  case 97: return cv::Vec3b(180,252,196);
  case 98: return cv::Vec3b(180,252,216);
  case 99: return cv::Vec3b(180,252,232);
  case 100: return cv::Vec3b(180,252,252);
  case 101: return cv::Vec3b(180,232,252);
  case 102: return cv::Vec3b(180,216,252);
  case 103: return cv::Vec3b(180,196,252);
  case 104: return cv::Vec3b(0,0,112);
  case 105: return cv::Vec3b(28,0,112);
  case 106: return cv::Vec3b(56,0,112);
  case 107: return cv::Vec3b(84,0,112);
  case 108: return cv::Vec3b(112,0,112);
  case 109: return cv::Vec3b(112,0,84);
  case 110: return cv::Vec3b(112,0,56);
  case 111: return cv::Vec3b(112,0,28);
  case 112: return cv::Vec3b(112,0,0);
  case 113: return cv::Vec3b(112,28,0);
  case 114: return cv::Vec3b(112,56,0);
  case 115: return cv::Vec3b(112,84,0);
  case 116: return cv::Vec3b(112,112,0);
  case 117: return cv::Vec3b(84,112,0);
  case 118: return cv::Vec3b(56,112,0);
  case 119: return cv::Vec3b(28,112,0);
  case 120: return cv::Vec3b(0,112,0);
  case 121: return cv::Vec3b(0,112,28);
  case 122: return cv::Vec3b(0,112,56);
  case 123: return cv::Vec3b(0,112,84);
  case 124: return cv::Vec3b(0,112,112);
  case 125: return cv::Vec3b(0,84,112);
  case 126: return cv::Vec3b(0,56,112);
  case 127: return cv::Vec3b(0,28,112);
  case 128: return cv::Vec3b(56,56,112);
  case 129: return cv::Vec3b(68,56,112);
  case 130: return cv::Vec3b(84,56,112);
  case 131: return cv::Vec3b(96,56,112);
  case 132: return cv::Vec3b(112,56,112);
  case 133: return cv::Vec3b(112,56,96);
  case 134: return cv::Vec3b(112,56,84);
  case 135: return cv::Vec3b(112,56,68);
  case 136: return cv::Vec3b(112,56,56);
  case 137: return cv::Vec3b(112,68,56);
  case 138: return cv::Vec3b(112,84,56);
  case 139: return cv::Vec3b(112,96,56);
  case 140: return cv::Vec3b(112,112,56);
  case 141: return cv::Vec3b(96,112,56);
  case 142: return cv::Vec3b(84,112,56);
  case 143: return cv::Vec3b(68,112,56);
  case 144: return cv::Vec3b(56,112,56);
  case 145: return cv::Vec3b(56,112,68);
  case 146: return cv::Vec3b(56,112,84);
  case 147: return cv::Vec3b(56,112,96);
  case 148: return cv::Vec3b(56,112,112);
  case 149: return cv::Vec3b(56,96,112);
  case 150: return cv::Vec3b(56,84,112);
  case 151: return cv::Vec3b(56,68,112);
  case 152: return cv::Vec3b(80,80,112);
  case 153: return cv::Vec3b(88,80,112);
  case 154: return cv::Vec3b(96,80,112);
  case 155: return cv::Vec3b(104,80,112);
  case 156: return cv::Vec3b(112,80,112);
  case 157: return cv::Vec3b(112,80,104);
  case 158: return cv::Vec3b(112,80,96);
  case 159: return cv::Vec3b(112,80,88);
  case 160: return cv::Vec3b(112,80,80);
  case 161: return cv::Vec3b(112,88,80);
  case 162: return cv::Vec3b(112,96,80);
  case 163: return cv::Vec3b(112,104,80);
  case 164: return cv::Vec3b(112,112,80);
  case 165: return cv::Vec3b(104,112,80);
  case 166: return cv::Vec3b(96,112,80);
  case 167: return cv::Vec3b(88,112,80);
  case 168: return cv::Vec3b(80,112,80);
  case 169: return cv::Vec3b(80,112,88);
  case 170: return cv::Vec3b(80,112,96);
  case 171: return cv::Vec3b(80,112,104);
  case 172: return cv::Vec3b(80,112,112);
  case 173: return cv::Vec3b(80,104,112);
  case 174: return cv::Vec3b(80,96,112);
  case 175: return cv::Vec3b(80,88,112);
  case 176: return cv::Vec3b(0,0,64);
  case 177: return cv::Vec3b(16,0,64);
  case 178: return cv::Vec3b(32,0,64);
  case 179: return cv::Vec3b(48,0,64);
  case 180: return cv::Vec3b(64,0,64);
  case 181: return cv::Vec3b(64,0,48);
  case 182: return cv::Vec3b(64,0,32);
  case 183: return cv::Vec3b(64,0,16);
  case 184: return cv::Vec3b(64,0,0);
  case 185: return cv::Vec3b(64,16,0);
  case 186: return cv::Vec3b(64,32,0);
  case 187: return cv::Vec3b(64,48,0);
  case 188: return cv::Vec3b(64,64,0);
  case 189: return cv::Vec3b(48,64,0);
  case 190: return cv::Vec3b(32,64,0);
  case 191: return cv::Vec3b(16,64,0);
  case 192: return cv::Vec3b(0,64,0);
  case 193: return cv::Vec3b(0,64,16);
  case 194: return cv::Vec3b(0,64,32);
  case 195: return cv::Vec3b(0,64,48);
  case 196: return cv::Vec3b(0,64,64);
  case 197: return cv::Vec3b(0,48,64);
  case 198: return cv::Vec3b(0,32,64);
  case 199: return cv::Vec3b(0,16,64);
  case 200: return cv::Vec3b(160,0,0);
  case 201: return cv::Vec3b(160,160,0);
  case 202: return cv::Vec3b(0,0,160);
  case 203: return cv::Vec3b(56,32,64);
  case 204: return cv::Vec3b(64,32,64);
  case 205: return cv::Vec3b(64,32,56);
  case 206: return cv::Vec3b(64,32,48);
  case 207: return cv::Vec3b(64,32,40);
  case 208: return cv::Vec3b(64,32,32);
  case 209: return cv::Vec3b(64,40,32);
  case 210: return cv::Vec3b(64,48,32);
  case 211: return cv::Vec3b(64,56,32);
  case 212: return cv::Vec3b(64,64,32);
  case 213: return cv::Vec3b(56,64,32);
  case 214: return cv::Vec3b(48,64,32);
  case 215: return cv::Vec3b(40,64,32);
  case 216: return cv::Vec3b(0,0,0);
  case 217: return cv::Vec3b(224,192,160);
  case 218: return cv::Vec3b(224,192,64);
  case 219: return cv::Vec3b(192,160,48);
  case 220: return cv::Vec3b(176,144,32);
  case 221: return cv::Vec3b(160,128,16);
  case 222: return cv::Vec3b(96,80,0);
  case 223: return cv::Vec3b(44,100,48);
  case 224: return cv::Vec3b(44,44,64);
  case 225: return cv::Vec3b(48,44,64);
  case 226: return cv::Vec3b(52,44,64);
  case 227: return cv::Vec3b(60,44,64);
  case 228: return cv::Vec3b(64,44,64);
  case 229: return cv::Vec3b(64,44,60);
  case 230: return cv::Vec3b(64,44,52);
  case 231: return cv::Vec3b(64,44,48);
  case 232: return cv::Vec3b(64,44,44);
  case 233: return cv::Vec3b(64,48,44);
  case 234: return cv::Vec3b(64,52,44);
  case 235: return cv::Vec3b(64,60,44);
  case 236: return cv::Vec3b(64,64,44);
  case 237: return cv::Vec3b(60,64,44);
  case 238: return cv::Vec3b(52,64,44);
  case 239: return cv::Vec3b(48,64,44);
  case 240: return cv::Vec3b(44,64,44);
  case 241: return cv::Vec3b(44,64,48);
  case 242: return cv::Vec3b(44,64,52);
  case 243: return cv::Vec3b(44,64,60);
  case 244: return cv::Vec3b(44,64,64);
  case 245: return cv::Vec3b(44,60,64);
  case 246: return cv::Vec3b(44,52,64);
  case 247: return cv::Vec3b(44,48,64);
  case 248: return cv::Vec3b(0,0,0);
  case 249: return cv::Vec3b(0,0,0);
  case 250: return cv::Vec3b(0,0,0);
  case 251: return cv::Vec3b(0,0,0);
  case 252: return cv::Vec3b(0,0,0);
  case 253: return cv::Vec3b(0,0,0);
  case 254: return cv::Vec3b(0,0,0);
  case 255: return cv::Vec3b(252,252,252);  
  default: return (cv::Vec3b(0,125,125));
  }
}


int main(int argc, char *argv[]) {

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
