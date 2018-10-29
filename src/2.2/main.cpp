#include <iostream>
#include <forward_list>
#include <iterator>

using namespace std;

string toString(forward_list<int> &l) {
  string s;
  
  int size = 0;
  for(auto i = l.begin(); i != l.end(); i++)
  {
    size++;
  }
  
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

void stepIn(forward_list<int>::iterator i, forward_list<int> &l, int &k) {
  cout << k << endl;
  if (++i != l.end())
  {
    stepIn(i, l, k);
  }
  k--;
  cout << k << endl;
  if (k == 0)
  {
    cout << "here" << *i << endl;
  }
}

forward_list<int> fromKthToLast(forward_list<int> &l, int k) {
  auto i = l.begin(); 
  stepIn(i, l, k);
  return l;
}

int main() {
  forward_list<int> l = {1, 2, 3, 4, 5, 6};
  cout << toString(l) << endl;
  auto nl = fromKthToLast(l, 1);
  cout << toString(nl) << endl;
  return 0;
}