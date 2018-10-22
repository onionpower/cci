#include <iostream>
#include <list>
#include <unordered_set>

using namespace std;

string toString(list<int> &l) {
  string s;
  int size = l.size()*3-2;
  s.reserve(size);
  auto it = l.begin();
  while (true) {
    s.append(to_string(*it));
    it++;    
    if (it == l.end()) {
      break;
    }
    s.append(", ");
  }
  return s;
}

void deleteDuplicates(list<int> &l) {
  unordered_set<int> set;  
  for (auto it = l.begin(); it != l.end(); it++) { 
    if (set.find(*it) == set.end()) {
      set.insert(*it);
      continue;
    }
    l.erase(it);
    it--;
  }
}

void deleteDuplicatesWithoutAlloc(list<int> &l) {
  for (auto it1 = l.begin(); it1 != l.end(); it1++) {
    for (auto it2 = next(it1, 1); it2 != l.end(); it2++) {
      if (*it1 == *it2) {
        l.erase(it2);
        it2--;
      }
    }
  }
}

int main() {
  list<int> l = { 1, 4, 4, 7, 12, 1, 4, 7, 9, 0, 9, 6, 5 };
  cout << toString(l) << endl;
  deleteDuplicates(l);
  cout << toString(l) << endl << endl;
  l = { 1, 4, 4, 7, 12, 1, 4, 7, 9, 0, 9, 6, 5 };
  cout << toString(l) << endl;
  deleteDuplicatesWithoutAlloc(l);
  cout << toString(l) << endl;
  return 0;
}