#include <iostream>
#include <random>
using namespace std; // So we don't need to repeat std:: etc...

// Random returns a RND value between 0-,
int random(int n) {
    if (n<1)
        return 1;
    // Prepare the random generator
    random_device rnd;
    std::mt19937 rnd_gen(rnd());
    std::uniform_int_distribution<std::mt19937::result_type> rng_algo(1,n);
    // Make the random number and return it
    return rng_algo(rnd_gen);
}

int main() {
    // Game parameters
    const int r_max {100};
    const int r_trials {13};

    // Variables
    int user_val {0}; // Initialyze X to 0. We will read keyboard into it.
    int trials_count {0};
    int success {0};

    // Random gen
    int r_val {random(r_max)}; // Random between 0-100

    // Print and start
    cout << "Guess a number between 0 and " << r_max << endl;

    while ((user_val != r_val) && (trials_count++ < r_trials)) {
        cin >> user_val;
	if (user_val == r_val) {
		success = 1;
		cout << "Success" << endl;
		break;
	}
        cout << "Try again ..." << endl;
    }
    if (!success) {
	    cout << "It was " << r_val << endl;
    }
}
