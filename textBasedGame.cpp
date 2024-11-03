#include <iostream>
using namespace std;

class Character {
public:
    int health;
    int attackPower; // The amount of damage an attack does
    string attackType; // The name of the attack (i.e., slash, stab, etc.)

    // Constructor initializes health, attack power, and attack type
    Character(int hp, int power, string type) : health(hp), attackPower(power), attackType(type) {}

    void takeDamage(int damage){
    health-= damage;
    }

    bool isAlive() const{
        return health > 0; 
    }
};

int main() {
    char choice; // Taking input to start the game
    Character player(100, 50, "Slash");  // Setting player health, attack power, and attack type
    Character monster(75, 25, "Bite");   // Setting monster health, attack power, and attack type

    cout << "*******************WELCOME TO [name] *****************************\n";
    cout << "Would you like to create a new player and begin? Y/N: \n";
    cin >> choice;

    if (choice == 'Y' || choice == 'y') { // Ask user if they want to create player and start game
        cout << "Player created with " << player.health << " health, " << player.attackPower
             << " attack power, and the attack of " << player.attackType << '\n'; // Display player stats
    } else if (choice == 'N' || choice == 'n') {
        cout << "Goodbye!\n";
        return 0;  // Exit the program if the player chooses not to start
    } else {
        cout << "Invalid input\n";
        return 0;  // Exit if invalid input is given
    }

    int decision;
    cout << "Your player is now ready! \n";
    cout << endl;
    cout << "What way would you like to go first? (enter 1 or 2) \n";
    cout << "1. Left \n";
    cout << "2. Right \n";
    cin >> decision;

    switch (decision) {
        case 1:  
            cout << "You run into a monster!\n";
            cout<<"Monsters health: "<<monster.health<<", monsters attack power: "<<monster.attackPower<< '\n';
            cout << "You attack the monster with 'Slash' inflicting " << player.attackPower << " damage.\n";
            monster.takeDamage(player.attackPower);
            cout<<"Monsters remaining health is: "<< monster.health<<'\n';
            
            if (!monster.isAlive()) {
                cout << "The monster has been defeated!\n";
            }
           
          
            break;
        case 2:
            cout << "You get lost in the woods.\n";
            break;
        default:
            cout << "Invalid choice. Please enter 1 or 2.\n";
            break;
    }

    return 0;
}


