#include <iostream>

using namespace std;

bool isOneCharAway(string lowest, string greatest) {
  auto found = false;
  for (int l = 0, g = 0; l < lowest.size(); l++, g++) {
    if (lowest[l] != greatest[g]) {
      if (found) {
        return false;
      }
      found = true;
      g++;
    }
  }
  return true;
}

bool isOneReplaced(string s1, string s2){
  auto oneFound = false;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] != s2[i]) {
      if (oneFound) {
        return false;
      }
      oneFound = true;
    }
  }
  return true;
}

bool isOneAway(string s1, string s2) {
  if (s1.size() == s2.size() - 1) {
    return isOneCharAway(s1, s2);
  }
  if (s1.size() == s2.size() + 1) {
    return isOneCharAway(s2, s1);
  }
  if (s1.size() == s2.size()) {
    return isOneReplaced(s1, s2);
  }
  return false;
}

int main() {
  auto origin = "origin";
  string test[] = {"orgin", "ogigin", "orign", "origiin", "oriigin", "aorigin", "orin", "ogriin", "oligid", "origin"};
  for (auto t : test) {
    cout << origin << " " << t << " " << isOneAway(origin, t) << endl;
  }
  return 0;
}