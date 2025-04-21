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

