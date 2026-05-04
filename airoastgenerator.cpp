#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to replace {name} with actual user name
string replaceName(string roast, string name) {
    size_t pos = roast.find("{name}");

    // Replace all occurrences of {name}
    while (pos != string::npos) {
        roast.replace(pos, 6, name); // 6 = length of "{name}"
        pos = roast.find("{name}", pos + name.length());
    }

    return roast;
}

int main() {
    srand(time(0));

    // List of roast templates
    vector<string> roasts = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would win gold.",
        "{name} doesn't debug code — they just hope the bug gets tired and leaves.",
        "{name}'s code has more bugs than a jungle.",
        "Even Google searches {name}'s errors.",
        "{name} types so slow, autocorrect gives up.",
        "{name}'s logic is like WiFi in a basement — weak.",
        "{name} treats deadlines like suggestions.",
        "{name} runs code and prays instead of debugging.",
        "{name}'s code compiles only in dreams."
    };

    string name;
    // Keep asking until user enters a valid name (no empty or spaces-only input)
    do {
        cout << "Enter your name: ";
        getline(cin, name);
        if (name.empty() || name.find_first_not_of(' ') == string::npos)
            cout << "Name can't be empty! Try again.\n";
    } while (name.empty() || name.find_first_not_of(' ') == string::npos);

    // Generate random index and pick roast
    string selectedRoast = roasts[rand() % roasts.size()];

    // Replace {name} with actual name using our function
    string finalRoast = replaceName(selectedRoast, name);

    // Display output
    cout << "\n🔥 Roast for you 🔥\n";
    cout << finalRoast << endl;
    cout << "\n(Don't take it personally — it's all in good fun!)" << endl;

    return 0;
}