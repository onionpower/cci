#include <iostream>

using namespace std;

bool ArePermutations(string s1, string s2);

int main() {
  cout << ArePermutations("thyea re", "they are") << endl;
  cout << ArePermutations("thyea re n0t", "they are not") << endl;
  return 0;
}

bool ArePermutations(string s1, string s2) {
  if (s1.size() != s2.size()) {
    return false;
  }

  auto ss1 = s1;
  sort(ss1.begin(), ss1.end());;
  auto ss2 = s2;
  sort(ss2.begin(), ss2.end());;
  for (int i = 0; i < ss1.size(); i++) {
    if (ss1[i] != ss2[i]) {
      return false;
    }
  }
  return true;
}