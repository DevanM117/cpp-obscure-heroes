//************************************************************************
//Author.....: Devan Marion
//Assignment: Banking System
//Despcription: This program provides a simple banking system where users
//              can deposit, withdraw, check their balance, and exit. 
//************************************************************************ 
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

const int SIZE = 10;

// Parallel Arrays
string names[SIZE] = {
    "Squirrel Girl", "Arm-Fall-Off-Boy", "The Tick", "Moon Knight", "Matter-Eater Lad",
    "Ragman", "Doorman", "Zeitgeist", "Ambush Bug", "Hellcow"
};

string powers[SIZE] = {
    "Control Squirrels", "Detachable Limbs", "Super Strength", "Multiple Personalities", "Eat Anything",
    "Absorbs Evil Souls", "Teleportation via Doors", "Acid Vomit", "Teleportation", "Vampiric Cow Abilities"
};

string weaknesses[SIZE] = {
    "Time Limits", "Heavy Objects", "Poor Judgment", "Mental Stability", "Stomach Capacity",
    "Moral Compass", "Must Use Doors", "Digestive Issues", "Too Random", "Sunlight"
};

// Multidimensional Array (2D array for year and universe)
string metadata[SIZE][2] = {
    {"1992", "Marvel"}, {"1989", "DC"}, {"1986", "Other"}, {"1975", "Marvel"}, {"1962", "DC"},
    {"1976", "DC"}, {"1989", "Marvel"}, {"2001", "Marvel"}, {"1982", "DC"}, {"1975", "Marvel"}
};

// Helper Functions
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

string toUpper(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

void searchByName(string query) {
    bool found = false;
    for (int i = 0; i < SIZE; i++) {
        if (toLower(names[i]).find(toLower(query)) != string::npos) {
            cout << "Found: " << names[i] << " | Power: " << powers[i] << " | Weakness: " 
                 << weaknesses[i] << " | Year: " << metadata[i][0] << " | Universe: " << metadata[i][1] << endl;
            found = true;
        }
    }
    if (!found) cout << "No superhero found with that name.\n";
}

void findBySuperpower(string query) {
    bool found = false;
    for (int i = 0; i < SIZE; i++) {
        if (toLower(powers[i]).find(toLower(query)) != string::npos) {
            cout << names[i] << " | Power: " << powers[i] << " | Weakness: " 
                 << weaknesses[i] << " | Year: " << metadata[i][0] << " | Universe: " << metadata[i][1] << endl;
            found = true;
        }
    }
    if (!found) cout << "No superheroes found with that superpower.\n";
}

void sortAlphabetically() {
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (names[i] > names[j]) {
                swap(names[i], names[j]);
                swap(powers[i], powers[j]);
                swap(weaknesses[i], weaknesses[j]);
                swap(metadata[i][0], metadata[j][0]);
                swap(metadata[i][1], metadata[j][1]);
            }
        }
    }
    cout << "Superheroes sorted alphabetically.\n";
}

void displayAll(bool to_upper = true) {
    for (int i = 0; i < SIZE; i++) {
        string name = to_upper ? toUpper(names[i]) : toLower(names[i]);
        string power = to_upper ? toUpper(powers[i]) : toLower(powers[i]);
        string weak = to_upper ? toUpper(weaknesses[i]) : toLower(weaknesses[i]);
        string year = to_upper ? toUpper(metadata[i][0]) : toLower(metadata[i][0]);
        string universe = to_upper ? toUpper(metadata[i][1]) : toLower(metadata[i][1]);

        cout << name << " | Power: " << power << " | Weakness: " << weak 
             << " | Year: " << year << " | Universe: " << universe << endl;
    }
}

// Main Menu
int main() {
    int choice;
    string input;

    do {
        cout << "\n--- Superhero Database ---\n";
        cout << "1. Search by Name\n";
        cout << "2. Find by Superpower\n";
        cout << "3. Sort Alphabetically\n";
        cout << "4. Display All (Uppercase)\n";
        cout << "5. Display All (Lowercase)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter superhero name to search: ";
                getline(cin, input);
                searchByName(input);
                break;
            case 2:
                cout << "Enter a superpower to search for: ";
                getline(cin, input);
                findBySuperpower(input);
                break;
            case 3:
                sortAlphabetically();
                break;
            case 4:
                displayAll(true);
                break;
            case 5:
                displayAll(false);
                break;
            case 0:
                cout << "Exiting the database. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
