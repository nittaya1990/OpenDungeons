#ifndef CREATURECLASS_H
#define CREATURECLASS_H

#include <string>
#include <iostream>
using namespace std;

#include "Ogre.h"

class CreatureClass
{
	public:
		enum CreatureJob { basicWorker = 1, advancedWorker, scout, weakFighter, weakSpellcaster, weakBuilder,
		                   strongFighter, strongSpellcaster, strongBuilder, guard, specialCreature, summon, superCreature };

		// Constructors and operators
		CreatureClass();
		CreatureClass(string nClassName, string nMeshName, Ogre::Vector3 nScale, double nHPPerLevel, double nManaPerLevel,\
				double nSightRadius, double nDigRate, double nMoveSpeed);

		// Class properties
		//NOTE: Anything added to this class must be included in the '=' operator for the Creature class.
		string className;
		string meshName;
		Ogre::Vector3 scale;
		double sightRadius;		// The inner radius where the creature sees everything
		double digRate;			// Fullness removed per turn of digging
		double danceRate;		// How much the danced upon tile's color changes per turn of dancing
		double hpPerLevel;
		double manaPerLevel;
		double moveSpeed;		// How fast the creature moves and animates
		double maxHP, maxMana;

		static string getFormat();
		friend ostream& operator<<(ostream& os, CreatureClass *c);
		friend istream& operator>>(istream& is, CreatureClass *c);
};

#endif

