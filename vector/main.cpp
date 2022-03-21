#include <vector>
#include <iostream>

using namespace std;

int main() {
  vector<int> v1;

  for (int i = 0; i < 50; i++) {
    v1.push_back(i + 1);
    cout << v1.at(i) << "   ";
  }
  cout << endl;

  vector<int>::iterator it;

  int a = 5;
  int b = 9;

  for (it = v1.begin() + a; it <= v1.begin() + b; it++) {
    cout << (*it) << "   ";
  }
  cout << endl;
}