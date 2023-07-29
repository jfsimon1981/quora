#include <iostream>
using namespace std;

class Safe_int {
  public:
  int i {0}; // We always init this one (yes good bye "Damn it that's why it failed")
  Safe_int(int init) {
    i = init;
    cout << "Safe_int c'tor (init " << i << ")" << endl;
  };
  ~Safe_int() {cout << "Safe_int d'tor" << endl;};
};

int main() {
  cout << "Entered main" << endl;
  {
    Safe_int i {0};
    static Safe_int j {1};
  }
  cout << "Exit main" << endl;
  return 0;
}