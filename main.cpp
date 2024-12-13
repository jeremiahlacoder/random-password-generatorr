#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototypes
void passwordGenerator(string specialCharacters);
void specialCharacters(); // Corrected function declaration

int main() {
    specialCharacters(); // Call special characters function

    return 0;
}

void passwordGenerator(string specialCharacters) {
    string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" + specialCharacters;
    srand(time(0)); // Seed the random number generator
    string randomString = ""; // Declare the random string variable       
    using std::cout;
    int passwordLength; // Declare passwordLength here
    cout << "How long do you want your password to be? (8-20 characters): " << endl;
    cin >> passwordLength;
    // Validate password length
    if (passwordLength < 8 || passwordLength > 20) {
        cout << "Your password does not meet the minimum or maximum length requirements. Please try again." << endl;
    }
    else {
        cout << "Password length accepted: " << passwordLength << " characters." << endl;
        for (int i = 0; i < passwordLength; i++) { // Now passwordLength is defined within the scope of the function
            int randomIndex = rand() % charset.length();  // Generate a random index
            randomString += charset[randomIndex];
        }
        cout << "Your generated password is: " << randomString << endl;
    }
}

// Function definition for specialCharacters
void specialCharacters() {
    char answer;
    string specialCharacter;  // Use string to store special characters input
    cout << "Do you want any special characters to be included in your password? (Y/N): " << endl;
    cin >> answer;
    // Check if user wants special characters
    if (answer == 'y' || answer == 'Y') {
        cout << "What special characters would you like to include?: " << endl;
        cin.ignore(); // To clear the newline left by previous cin >> answer
        getline(cin, specialCharacter); // Read a whole line including spaces
        cout << "Special characters included: " << specialCharacter << endl;
        passwordGenerator(specialCharacter);
    }
    else if (answer == 'n' || answer == 'N') {
        cout << "Okay, no special characters will be included in your password." << endl;
        passwordGenerator("");
    }
    else {
        cout << "Invalid answer. Please try again." << endl;
    }
}