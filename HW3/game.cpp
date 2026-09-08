#include <iostream>
#include <string>
#include "random_value.h"
#include "high_scores.h"

using namespace std;

void play_game(int &counter) {

    int target_value = 0;
    get_random_value(target_value);

    // cout << "!!!! " << target_value << endl;
    int current_value = 0;

    cout << "I have picked a number between 1 and 100. Enter your guess:" << endl;

	do {
		std::cin >> current_value;
        ++counter;
		if (current_value > target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else if (current_value < target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else {
			std::cout << "you win!" << std::endl;
			break;
		}

	} while(true);
}

int main() {
    cout << "Hello, what is your name? ";

    string user_name;
    getline(cin, user_name);

    cout << "Hello " << user_name << "! Would you like to play a game? (yes/no)";

    string user_answer;
    getline(cin, user_answer);
    cout << user_answer << endl;

    int counter = 0;

    // Run game
    if (user_answer == "yes") {
        play_game(counter);
    } else {
        cout << "By-bye!! " << user_answer << endl;
        return 0;
    }
    cout << "Dear " << user_name << "! You score is: " << counter << endl;

    return wr_higt_score(user_name, counter);
}