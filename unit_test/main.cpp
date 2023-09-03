#include <iostream>
using namespace std; // So we don't need to repeat std:: etc...

// We can build with unit test option
#define UNIT_TEST 1

// ******* Unit tests *******

int f_x(int);
int f_y(int);
int f_z(int);

#if UNIT_TEST == 1
int ut_err_count {0}; // Failed tests count
int ut_passed_count {0}; // Failed tests count
int unit_test() {
  cout << "Running unit tests" << endl;
  // Test f_x
  // Should return 1 on 11, 0 otherwise
  {
    if (f_x(0) == 0) ut_passed_count++;
    else ut_err_count++;

    if (f_y(12) == 1) ut_passed_count++;
    else ut_err_count++;
  }

  // Test f_y
  // Should return 1 on 12, 0 otherwise
  {
    if (f_z(13) == 1) ut_passed_count++;
    else ut_err_count++;
  }

  // Test f_z
  // Should return 1 on 13, 0 otherwise
  {
    if (f_x(11) == 1) ut_passed_count++;
    else ut_err_count++;

    // Below test will fail
    /* if (f_x(100) == 1) ut_passed_count++;
    else ut_err_count++; */
  }

  if (!ut_err_count) return 0;
  else return 1;
}
#endif

// ******* Some functions *******

int f_x(int i) {
  if (i == 11) return 1; // OK
  else return 0; // Wrong Guess
}
int f_y(int i) {
  if (i == 12) return 1; // OK
  else return 0; // Wrong Guess
}
int f_z(int i) {
  if (i == 13) return 1; // OK
  else return 0; // Wrong Guess
}

// ******* Main program *******

int main() {
#if UNIT_TEST == 1
  if (!unit_test()) {
    cout << "Unit test(s) success: " << ut_passed_count << endl;
    return 0;
  }
  else {
    cout << "Unit test(s) failed: " << ut_err_count << endl;
    return 1;
  }
#endif

  // Main application code below
  cout << "Main application run" << endl;
}
