#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>


using namespace std;

// Declaring player in a forward declaration.
class Player;

// Global variables
int MAX_AMBROSIA = 10;
int MAX_FOOD_ALLOCATION_PER_DAY = 2;
int MAX_TRAINING_PER_DAY = 2;
int MAX_FOOD_STORED = 0;
int DRACHMA_BANK = 0;
int currentDayPartition = 0;
int minLow = 0; int minHigh = 250;
vector<Player> PerishedAgents;

class Player {
public:
    string name = "Agent";
    bool isGodliving = false;
    int dayCount = 0;
    int maxHealth = 100;
    int maxStamina = 100;
    int maxHunger = 75;
    float hunger = static_cast<float>(maxHunger);
    float health = static_cast<float>(maxHealth);
    float stamina = static_cast<float>(maxStamina);
    bool isAlive = true;
    int drachma = 0;
    int currentFoodCount = 0;

    // Set a min clamp for specific values so a negative won't happen

    void AdvanceDayPartition() {
        currentDayPartition = (currentDayPartition + 1) % 4;
        if (currentDayPartition == 0) {  // A new day begins
            dayCount++;
            MAX_FOOD_ALLOCATION_PER_DAY = MAX_FOOD_STORED;
        }
    }
    void CheckIfAlive()  {
        if (health <= 0 || hunger <= 0) {
            PerishedAgents.push_back(*this);
            isAlive = false;
            cout << "Your character has perished.\n";
        }
    }
    void CheckStamina(){
        if (stamina <= 0){
            StaminaExhaustion();
        }
    }


    // Reorganizing to add the day advances:
    // Train, Eat, Sleep, Wait, Do an odd job.

    void TrainOnce() {
        stamina -= 15;
        maxStamina += 5;
        drachma += 5;
        health -= 3;
        hunger -= 20;
        cout << "You decide to spend your time training.\n";
        AdvanceDayPartition();
        CheckIfAlive();
        CheckStamina();
    }
    void GoToMarket() {
        currentFoodCount++;
        drachma -= 3;
        hunger -= 10;
        DRACHMA_BANK += 3;
        MAX_FOOD_STORED -= 1;
        cout << "You went to the local market to purchase something to eat.\n";
        AdvanceDayPartition();
        CheckIfAlive();
        CheckStamina();
    }
    void GoToSleep() {
        stamina += 20;
        hunger -= 35;
        cout << "You decide to spend some time resting.\n";
        LoadingBarDisplay();
        AdvanceDayPartition();
        CheckIfAlive();
        CheckStamina();
    }
    void StaminaExhaustion(){
        stamina += 15;
        hunger -= 40;
        cout << "You have passed out due to lack of stamina.\n";
        AdvanceDayPartition();
        CheckIfAlive();
        CheckStamina();
    }
    void EatFromInventory() {
        if (currentFoodCount >= 1) {
            currentFoodCount--;
            cout << "You spend some time eating some food.\n";
            hunger += 50;
            AdvanceDayPartition();
            CheckIfAlive();
            CheckStamina();
        } else {
            cout << "You don't have any food.\n";
        }

    }
    void DoAnOddJob() {
        stamina -= 35;
        hunger -= 40;
        health -= 15;
        drachma += 27;
        cout << "You take an odd job, to earn some more drachma. It's money well earned.\n";
        AdvanceDayPartition();
        CheckIfAlive();
        CheckStamina();
    }
    void LoadingBarDisplay() {
        float progress = 0.0;
        int MILLISECONDS = 500;
        while (progress <= 1.0) {
            int barWidth = 100; // How long the bar is

            cout << "[";
            int pos = barWidth * progress;
            for (int i = 0; i < barWidth; i++) {
                if (i < pos) cout << "#";
                else if (i == pos) cout << "|";
                else cout << " ";
            }
            cout << "] " << int(progress * 100.0) << " %\r";
            cout.flush();

            // Increment progress
            progress += 0.10;
            // Sleep for a short duration to simulate loading time
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        cout << endl;
    }
};


bool OlympianGreeting(char chosen);
void LeavingGreeting();
void Experience(Player& player);
string DayPartition(int currentDayState);
void triggerRandomEvent();

// Each day will add max food allocation per day.
// Food costs a specific amount of DRACHMA
// Food brought will go into the DRACHMA Bank

int main() {
    bool isRunning = false;
    char startChosen = 0;
    int _temp = 0;
    int maxTimes = 11;

    Player player;

    isRunning = OlympianGreeting(startChosen);
    while (isRunning) {
        for (int i = 0; i < maxTimes; i++) {
            // Remember it starts at index 0
            cout << "\nHours elapsed: " << i;
            _temp = i;
            isRunning = false;
        }
        if (_temp == maxTimes - 1) {
            // if _temp is max times it will instead run this
            LeavingGreeting();
            Experience(player);
        }
    }

    return 0;
}

void LeavingGreeting() {
    cout << "\n\nHey you, you're finally awake.\n";
}

bool OlympianGreeting(char chosen) {
    cout << "Welcome to Olympus!\nWould you like to continue: Y/N \n";
    cin >> chosen;
    if (chosen == 'Y' || chosen == 'y') {
        return true;
    } else if (chosen == 'N' || chosen == 'n') {
        cout << "Go ahead, take your time...\n";
        return false;
    }
    return false;
}

void Experience(Player& player) {
    bool isExperiencing = true;
    int totalDaysPassed;

    while(isExperiencing && player.isAlive) {

        // Display current status
        cout << "\nDays Alive: " << player.dayCount << endl;
        cout << "Health: " << player.health << endl;
        cout << "Stamina: " << player.stamina << endl;
        cout << "Drachma: " << player.drachma << endl;
        cout << "Hunger: " << player.hunger << endl;
        cout << "Meals: " << player.currentFoodCount << endl;

        // Display options
        cout << "\nChoose an action:" << endl;
        cout << "1. Train Once" << endl; // Trains increases max stamina.
        cout << "2. Go to Market" << endl; // Purchases a meal.
        cout << "3. Go to Sleep" << endl; // Goes to sleep.
        cout << "4. Eat from Inventory" << endl; // Eats meal.
        cout << "5. Do an Odd Job" << endl; // Earns drachma.
        cout << "6. Exit" << endl;

        int choice;
        cin >> choice;

        switch(choice) {
            case 1:
                player.TrainOnce();
                break;
            case 2:
                player.GoToMarket();
                break;
            case 3:
                player.GoToSleep();
                break;
            case 4:
                player.EatFromInventory();
                break;
            case 5:
                player.DoAnOddJob();
                break;
            case 6:
                isExperiencing = false;
                break;
            default:
                cout << "Invalid choice. Please choose again." << endl;
        }

        // Random Event
        if (player.dayCount % 5 == 0){
            triggerRandomEvent();
        }


        if (!player.isAlive) {
            char choice;
            cout << "Would you like to create a new character? (Y/N)\n";
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                player = Player();  // Reset player to a new character
                isExperiencing = true;
                player.isAlive = true;
                cout << "A new character has been created.\n";
            } else {
                isExperiencing = false;
            }
        }
    }
}

// Split day into fours, partitioning the day -- starts in the morning
// min, 0, max 4 0 is twilight, 1 is morning, 2 is afternoon and 3 is evening
string DayPartition(int currentDayState) {
    switch(currentDayState) {
        case 1:
            return "Morning";
        case 2:
            return "Afternoon";
        case 3:
            return "Evening";
        case 4:
            return "Twilight";
        default:
            return "Unknown";
    }
}
void triggerRandomEvent() {
    system("python random_event.py > event_output.txt");

    // find the file called this and if its open get the random line, print then close the file.
    std::ifstream file("event_output.txt");
    string line;
    if (file.is_open()){
        while(getline(file, line)) {
            cout << "Random Event: " << line << endl;
        }
        file.close();
    }
}
