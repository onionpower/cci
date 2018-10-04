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

bool isOneAway(string origin, string candidate) {
  if (origin.size() == candidate.size() - 1) {
    return isOneCharAway(origin, candidate);
  }
  if (origin.size() == candidate.size() + 1) {
    return isOneCharAway(candidate, origin);
  }
  if (origin.size() == candidate.size()) {
    for (int i = 0; i < origin.size(); i++) {
      if (origin[i] != candidate[i])
        return false;
    }
    return true;
  }
  return false;
}

int main() {
  auto origin = "origin";
  string test[] = {"orgin", "orign", "origiin", "oriigin", "aorigin", "orin", "ogriin", "oligid", "origin"};
  for (auto t : test) {
    cout << origin << " " << t << " " << isOneAway(origin, t) << endl;
  }
  return 0;
}