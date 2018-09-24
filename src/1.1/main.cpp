#include <iostream>

using namespace std;

bool ContainsUniqueCharactersOnly(string s);

int main() {
  string s = "stringwithununiquehractrs";
  cout << s << " -> " << ContainsUniqueCharactersOnly(s) << endl;
  s = "abcdegh";
  cout << s << " -> " <<  ContainsUniqueCharactersOnly(s) << endl;
  return 0;
}

bool ContainsUniqueCharactersOnly(string s) {
  if (s.size() > 128 || s.size() == 0) {
    return false;
  }
  if (s.size() == 1) {
    return true;
  }

  string sortedS = s;
  sort(sortedS.begin(), sortedS.end());;
  auto c = sortedS[0];
  for (int i = 1; i < sortedS.size(); i++) {
    if (sortedS[i] == c) {
      return false;
    }
    c = sortedS[i];
  }
  return true;
}