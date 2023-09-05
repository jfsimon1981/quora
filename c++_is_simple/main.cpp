#include <iostream>
#include <random>
#include <vector>
using namespace std;

int rnd(int max) {
    random_device dev;
    mt19937 rgen(dev());
    uniform_int_distribution<std::mt19937::result_type> dist(1,max);
    return dist(rgen);
}

class Answers {
	vector<string> ans;
	string qst;
	public:
	Answers(string sin) {qst = sin;}
	void add(string sin) {ans.push_back(sin);}
	void say() {
		cout << qst << endl;
		if (ans.size() >0)
			cout << ans[rnd(ans.size())-1] << endl;
	}
};

int main() {
	Answers asw("why is c++ complicated");
	asw.add("Because someone told me it was ... i did not verify.");
	asw.add("Yes it's so complex, probably because it was designed to make huge software and grew over decades");
	asw.add("No but you can use it all and find it complex, you don't need to, use the subset that suits you best");
	asw.add("What's complicated ? Virtual and Class hierarchies yes of course, but day to day use can be a lot simplet");
	asw.add("I only know a subset for embedded applications and it's not complex, really ...");
	asw.add("I used to find it complex until sombody explained it to me simply, and that it was all clear ...");
	asw.add("Oh yes you're right");
	asw.add("Damn i don't agree with you");
	asw.add("Ok i'll fire up a C++ program and we'll get a better answer ...");
	asw.add("Is it really ? Oh yes the book seems huge ...");
	// asw.add("");
	asw.say();
}
