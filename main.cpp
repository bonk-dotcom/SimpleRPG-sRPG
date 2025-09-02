/*  Project Name: SRPG
    Project Version: 1.0
    Project Description: A simple turn based RPG that allows the player to attack and run from enemies.
    Created by Marcus V. on 02/09/2025.
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
string startInput;
string userName;
class user {
    public:
    string userName;
    float health = 100;
    float attack = 10;
};
class enemy {
    public:
    string type = "Goblin";
    float health = 25;
    float attack = 5;
};
cout << "------------" << endl;
cout << "    SRPG" << endl;
cout << "------------" << endl;
cout << "START? (Y/N) "; //start and close game logic
cin >> startInput;
int startInputScore = 1;
while (startInputScore == 1) {
    if (startInput == "Y" || startInput == "y")
    {
        cout << "STARTING..." << endl;
        startInputScore -= 1;
        if (startInputScore == 0) {
            break;
        }
    }
    if (startInput == "N" || startInput == "n") {
        cout << "CLOSING..." << endl;
        startInputScore -= 1;
        if (startInputScore == 0) {
            return 0;
        }
    }
    else {
        cout << "INVALID INPUT." << endl;
        startInputScore += 1;
        if (startInputScore == 2) {
            cout << "CLOSING ..." << endl;
            return 0;
        }
    }
}
user user;
cout << "ENTER NAME:" << "";
cin >> userName;
cout << "WELCOME! " << userName << endl;
cout << "YOU HAVE" << endl;
cout << user.health << " HP" << endl;
cout << user.attack << " ATK" << endl;

    //battle loop
    string choice;
    enemy goblin; //making da enemy
    cout << "A WILD " << goblin.type << " APPEARED!" << endl;
    cout << goblin.type << " HAS " << goblin.health << " HP" << endl;

while (user.health > 0 | goblin.health > 0){
    //battle logic
    if (goblin.health <= 0) {
        cout << "YOU WON!" << endl;
        break;
    }
    if (user.health <= 0) {
        cout << "YOU LOST!" << endl;
        break;
    }
    cout << "WHAT WILL YOU DO?" << endl;
    cout << "[ATTACK] [1]" << endl;
    cout << "[RUN] [2]" << endl;
    cin >> choice;
    if (choice == "1") {
        cout << "YOU ATTACKED " << goblin.type << "!" << endl;
        goblin.health -= user.attack;
        cout << "YOU DEALT " << user.attack << " DMG!" << endl;
        if (goblin.health > 0) {
            cout << goblin.type << " NOW HAS " << goblin.health << " HP!" << endl;
            user.health -= goblin.attack;
            cout << goblin.type << " RETALIATED AND DEALT " << goblin.attack << " DAMAGE!" << endl;
            cout << "YOU NOW ONLY HAVE " << user.health << " HP LEFT!" << endl;
        }
        else {
            cout << goblin.type << " HAS DIED!" << endl;
        }
    }
    else if (choice == "2") {
        cout << "YOU RAN AWAY!" << endl;
        break;
    }
}
return 0;
}