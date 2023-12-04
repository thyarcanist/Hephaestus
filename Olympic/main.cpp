#include <cstdlib>
#include <iostream>
#include <fstream>

// Function to generate initial game state
void generateInitialState() {
    // Load the model and start generating
    // Will need to start another py to do that. will need to use a small model size
    // Call AI service or perform some generation logic
    // Save the state to a file or database
}

// Function to delete the game state
void deleteState() {
    // Remove the state file or clear the database
}


int main() {

    // Check if state exists, if not, generate a new state
    generateInitialState();

    // Start the local web server that serves as the game's front end
    std::system("C:venv/Scripts/python.exe C:server.py");

    // Rest of your C++ code...

    return 0;
}
