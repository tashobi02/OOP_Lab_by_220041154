#include <iostream>
#include <vector>
using namespace std;

class CharacterActions {
   public:
    virtual void attack() = 0;
    virtual void defend() = 0;
    virtual void useSpecialAbility() = 0;
    virtual void displayStats() = 0;
    virtual ~CharacterActions() {}
};

class BaseCharacter : public CharacterActions {
   public:
    string name;
    int health;
    int mana;
    int attackPower;
    int specialAbilityPower;
    string specialAbilityName;
    BaseCharacter(string n, int h, int ap, int sap, string san)
        : name(n),
          health(h),
          mana(0),
          attackPower(ap),
          specialAbilityPower(sap),
          specialAbilityName(san) {}
    void displayStats() override {
        cout << name << endl;
        cout << "Health: " << health << endl;
        cout << "Mana: " << mana << endl;
    }
    void defend() override {
        cout << name << " defends! Attack is blocked, no health reduced."
             << endl;
    }
    int getHealth() const { return health; }
    void takeDamage(int damage) { health -= damage; }
    bool isAlive() const { return health > 0; }

   protected:
    void increaseMana() {
        mana += 50;
        if (mana > 100)
            mana = 100;
    }
    void resetMana() { mana = 0; }
};

class Warrior : public BaseCharacter {
   public:
    Warrior() : BaseCharacter("Warrior", 100, 25, 35, "Berserk Rage") {}
    void attack() override {
        cout << name << " attacks with power " << attackPower << "!" << endl;
        increaseMana();
    }
    void useSpecialAbility() override {
        if (mana >= 100) {
            cout << name << " uses " << specialAbilityName << " with power "
                 << specialAbilityPower << "!" << endl;
            resetMana();
        } else {
            cout << name << " does not have enough mana to use "
                 << specialAbilityName << "!" << endl;
        }
    }
};

class Mage : public BaseCharacter {
   public:
    Mage() : BaseCharacter("Mage", 120, 20, 30, "Arcane Blast") {}
    void attack() override {
        cout << name << " attacks with power " << attackPower << "!" << endl;
        increaseMana();
    }
    void useSpecialAbility() override {
        if (mana >= 100) {
            cout << name << " uses " << specialAbilityName << " with power "
                 << specialAbilityPower << "!" << endl;
            resetMana();
        } else {
            cout << name << " does not have enough mana to use "
                 << specialAbilityName << "!" << endl;
        }
    }
};

class Archer : public BaseCharacter {
   public:
    Archer() : BaseCharacter("Archer", 90, 20, 35, "Fire Arrow") {}
    void attack() override {
        cout << name << " attacks with power " << attackPower << "!" << endl;
        increaseMana();
    }
    void useSpecialAbility() override {
        if (mana >= 100) {
            cout << name << " uses " << specialAbilityName << " with power "
                 << specialAbilityPower << "!" << endl;
            resetMana();
        } else {
            cout << name << " does not have enough mana to use "
                 << specialAbilityName << "!" << endl;
        }
    }
};

class BossEnemy {
   public:
    string name;
    int health;
    int attackPower;
    int attackCounter;
    BossEnemy()
        : name("Boss"), health(150), attackPower(30), attackCounter(0) {}
    void attack(BaseCharacter& character) {
        cout << name << " attacks " << character.name << " with power "
             << attackPower << "!" << endl;
        character.takeDamage(attackPower);
    }
    void takeDamage(int damage) {
        attackCounter++;
        if (attackCounter % 3 == 0) {
            cout << name << " defends! No damage taken." << endl;
        } else {
            health -= damage;
        }
    }
    int getHealth() const { return health; }
    bool isAlive() const { return health > 0; }
    void displayStats() {
        cout << name << endl;
        cout << "Health: " << health << endl;
    }
};

class GameEngine {
   private:
    vector<BaseCharacter*> players;
    BossEnemy boss;

   public:
    GameEngine() {
        players.push_back(new Warrior());
        players.push_back(new Mage());
        players.push_back(new Archer());
    }
    ~GameEngine() {
        for (auto& pl : players) delete pl;
    }
    void playGame() {
        cout << "Game begins! Players vs. Boss" << endl;
        while (boss.isAlive() && allPlayersAlive()) {
            for (auto& pl : players) {
                if (pl->mana == 100) {
                    pl->useSpecialAbility();
                    boss.takeDamage(pl->specialAbilityPower);
                    cout << "Boss takes " << pl->specialAbilityPower
                         << " damage! Health now: " << boss.getHealth() << endl;
                } else {
                    pl->attack();
                    boss.takeDamage(pl->attackPower);
                    cout << "Boss takes " << pl->attackPower
                         << " damage! Health now: " << boss.getHealth() << endl;
                }
                if (!boss.isAlive())
                    break;
            }
            if (!boss.isAlive())
                break;
            for (auto& pl : players) {
                if (pl->isAlive()) {
                    boss.attack(*pl);
                    cout << pl->name
                         << " takes damage! Health now: " << pl->getHealth()
                         << endl;
                }
            }
        }
        if (boss.isAlive()) {
            cout << "Boss wins! Players lose." << endl;
        } else {
            cout << "Boss defeated! Players win!" << endl;
        }
    }

   private:
    bool allPlayersAlive() const {
        for (const auto& pl : players) {
            if (!pl->isAlive())
                return false;
        }
        return true;
    }
};

int main() {
    GameEngine game;
    game.playGame();
    return 0;
}
