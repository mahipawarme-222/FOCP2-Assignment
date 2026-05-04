#include <iostream>
#include <vector>
#include <random>
using namespace std;

class ExcuseGenerator {
private:
    vector<string> excuses;
    mt19937 gen;

public:
    // Constructor
    ExcuseGenerator() {
        // Initialize random generator
        random_device rd;
        gen = mt19937(rd());

        // Add templates
        excuses = {
            "{name} couldn't submit because the laptop started updating at the worst time.",
            "{name} was about to submit when the Wi-Fi disappeared.",
            "{name}'s file vanished like it never existed.",
            "{name}'s dog deleted the homework out of personal opinion.",
            "{name} reached 99% and the system froze.",
            "{name}'s computer restarted without saving anything.",
            "{name} was ready, but the power cut ruined everything.",
            "{name}'s antivirus blocked the assignment.",
            "{name} tried everything, but technology said no.",
            "{name} did the work, but the system disagreed."
        };
    }

    // Function to generate excuse
    string generateExcuse(string name) {
        uniform_int_distribution<> dist(0, excuses.size() - 1);
        string excuse = excuses[dist(gen)];

        // Replace {name}
        size_t pos = excuse.find("{name}");
        if (pos != string::npos) {
            excuse.replace(pos, 6, name);
        }

        return excuse;
    }
};

int main() {
    ExcuseGenerator eg;
    string name, choice;

    while (true) {
        cout << "\nEnter student name: ";
        getline(cin, name);

        if (name.empty()) {
            cout << "Invalid input. Try again.\n";
            continue;
        }

        cout << "\nExcuse: " << eg.generateExcuse(name) << endl;

        // Ask user to continue
        cout << "\nGenerate another excuse? (yes/no): ";
        getline(cin, choice);

        if (choice != "yes" && choice != "y") {
            cout << "Goodbye!\n";
            break;
        }
    }

    return 0;
}