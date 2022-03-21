#include <vector>
#include <iostream>
#include <functional>

using namespace std;

int main() {
  vector<int> int_vec{1,   23,   43,  324, 10, 222, 424,
                      649, 1092, 110, 129, 40, 3024};

  vector<int> sub_vec{&int_vec[0], &int_vec[5]};
  vector<reference_wrapper<int>> ref_sub_vec{int_vec.begin() + 0,
                                             int_vec.begin() + 5};

  for (auto it = sub_vec.begin(); it < sub_vec.end(); it++) {
    cout << (*it) << "   ";
    *it = 0;
  }
  cout << endl;

  for (auto it = sub_vec.begin(); it < sub_vec.end(); it++) {
    cout << (*it) << "   ";
  }
  cout << endl;

  for (auto it = int_vec.begin(); it < int_vec.end(); it++) {
    cout << (*it) << "   ";
  }
  cout << endl;

  cout << endl;
  for (auto &item : ref_sub_vec) {
    cout << item.get() << "   ";
    item.get() = 0;
  }
  cout << endl;

  for (auto it = sub_vec.begin(); it < sub_vec.end(); it++) {
    cout << (*it) << "   ";
  }
  cout << endl;

  for (auto it = int_vec.begin(); it < int_vec.end(); it++) {
    cout << (*it) << "   ";
  }
  cout << endl;

  return EXIT_SUCCESS;
}