// OCP_worksheet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <string>
#include "OCP_worksheet.h"

using namespace std;

struct pos
{
    int x, y;
    int distanceFrom(pos p) {
		return  sqrt(pow((x - p.x), 2) + pow((y - p.y), 2) * 1.0);;
    }
};

string getLocation(pos p) {

    if (p.x < 10 && p.y < 10) {
        return "castle";
    }
    else if (p.x < 20 && p.y < 20) {
        return "town";
    }
    else {
        return "forest";
    }

}

class Player {
public:
    pos p = { 10,10 };
    int gold = 100;
    string tag = "Player";

    pos position() { return p; };
    bool isRich() { return gold > 50; }

    void takeGold() {
        cout << "Player lost " << gold << " gold" << endl;
        gold = 0;
    }
    void takeDamage(int damage) {
        cout << "Player took " << damage << " damage" << endl;
    }
};

class Character {
    pos p {0,0};
public:
    int range = 10;
    string tag = "Character";
    virtual pos position() {return p};

};

class Warrior : public Character {
public:

	int attackDamage = 10;
    string tag = "Warrior";
};

class Mage : public Character {
//mage rules
//if in same location as player, and mage has mana, mage casts spell to restore player health to 100
// also if in forest, teleport player to castle
public:
    string tag = "Mage";

};

class Archer : public Character {
public:
    string tag = "Archer";
    int arrows = 10;
    int attackDamage = 5;
    void useArrow() { arrows--; }
    bool hasArrows() { return arrows > 0; }
};


// 0. fix law of demeter violation
// 1. deal with feature envy
// 2. remove switch statements or if else chains
// 3. remove duplicate code
// 4. when you ar done, this function should be ONE shortish line of code
void Interact(Character* npc, Player& player)
{
    if (npc->tag == "Warrior") {
        auto warrior = dynamic_cast<Warrior*>(npc);
        if (warrior->position().distanceFrom(player.position()) < warrior->range) //ugh! fix law of demeter violation, maybe ask the warrior a question instead?
            if (player.isRich()) {
                cout << "Warrior attacks" << endl;
                player.takeGold();
            }
    }
    else if (npc->tag == "Archer") {
        auto archer = dynamic_cast<Archer*>(npc);
        if (archer->position().distanceFrom(player.position()) < archer->range) //ugh! it hurts my eyes! law of demter AND duplicate code
            if (archer->hasArrows()) {
                cout << "Archer attacks" << endl;
                archer->useArrow();
                player.takeDamage(archer->attackDamage);
            }
    }
}

// Game simulation
int main() {
    Warrior w;
    Archer a;
    Mage m;
    Player player;

    std::vector<Character*> npcs = {
        &w,
        &a
    };

    for (Character* npc : npcs) {
        Interact(npc, player);
    }

    return 0;
}
