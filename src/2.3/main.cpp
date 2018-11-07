#include <iostream>
#include <forward_list>
#include <iterator>

using namespace std;
string to_string(forward_list<int> l) {
  string s;  
  for(auto it = l.begin(); it != l.end(); it++)
  {
    s.append(to_string(*it));
    s.append(" ");
  }
  
  return s;
}

forward_list<int> remove_simple(forward_list<int> l, int nodeVal) {
  l.remove(nodeVal);
  return l;
}

forward_list<int> remove_with_iterator(forward_list<int> l, int nodeVal) {
  auto it = l.begin();
  if (it == l.end()) {
    return l;
  }
  for(;; it++)
  {
    auto next = it;
    next++;
    if (next == l.end()) {
      break;
    }
    if (*next == nodeVal) {
      l.erase_after(it);
      break;
    }
  }
  return l;    
}

int main() {
  forward_list<int> l = {1, 2, 3, 4, 5, 6};
  cout << to_string(l) << endl;
  int rmNodeVal;
  cin >> rmNodeVal;
  if (!cin.good()) {
    cout << "incorrect input" << endl;
    return 0;
  }
  auto modifiedList = remove_simple(l, rmNodeVal);
  cout << to_string(modifiedList) << endl;

  auto modifiedList2 = remove_with_iterator(l, rmNodeVal);
  cout << to_string(modifiedList2) << endl;
  return 0;
}