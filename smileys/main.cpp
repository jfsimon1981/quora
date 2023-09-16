#include <iostream>
#include <string>
#include <vector>
using namespace std;

// A simple smiley class
class Smileys {
		string smiley_str;
	public:
		enum Mood {Happy, Crying, Neutral, Doubtful, Blink};
		void set_mood(Mood m_in) {
			switch (m_in) {
				case Blink:
					smiley_str=";)";
					break;
				case Happy:
					smiley_str=":)";
					break;
				case Crying:
					smiley_str=";(";
					break;
				case Neutral:
					smiley_str=":|";
					break;
				case Doubtful:
					smiley_str=":\\";
					break;
				default:
					smiley_str=":)";
					break;
			}
		}
		Smileys() {set_mood(Mood::Happy);}
		Smileys(Mood mood_in) {set_mood(mood_in);}
		void print() {cout << smiley_str << endl;}
};

int main(int argc, char** argv) {
	// Store user args
	vector<string> args;
	for (auto p {argv}; *p!=0; p++) args.push_back(*p);

	// Our Smiley app
	Smileys smy(Smileys::Mood::Happy);

	// Take into account argument (ex. "smiley.exe Happy" or ./smiley Happy)
	if (argc == 2) {
		if ((args[1] == "Happy") || (args[1] == "happy")) smy.set_mood(Smileys::Mood::Happy);
		else if ((args[1] == "Neutral") || (args[1] == "neutral")) smy.set_mood(Smileys::Mood::Neutral);
		else if ((args[1] == "Crying") || (args[1] == "crying")) smy.set_mood(Smileys::Mood::Crying);
		else if ((args[1] == "Doubtful") || (args[1] == "doubtful")) smy.set_mood(Smileys::Mood::Doubtful);
		else if ((args[1] == "Blink") || (args[1] == "blink")) smy.set_mood(Smileys::Mood::Blink);
		else {
			cout << "Smileys app supports: Happy, Crying, Neutral, Doubtful, Blink" << endl;
		}
	}
	else cout << "You can provide the smiley ie execute smiley Blink." << endl;

	// Prints the smiley
	smy.print();
	return 0;
}
