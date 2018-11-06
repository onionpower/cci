#include <iostream>
#include <forward_list>
#include <iterator>

using namespace std;

string toString(forward_list<int>::iterator &i, forward_list<int> l) {
  string s;
  while (i != l.end()) {
    s.append(to_string(*i));
    s.append(" ");
    i++;
  }
  return s;
}

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

forward_list<int>::iterator getKthIterator(forward_list<int>::iterator i, forward_list<int> &l, int &k) {
  forward_list<int>::iterator result;
  if (i != l.end())
  {
    auto new_i = i;
    result = getKthIterator(++new_i, l, k);
  } else {
    return l.end();
  }
  k--;
  if (k >= 0)
  {
    return i;
  } else {
    return result;
  }
}

forward_list<int>::iterator fromKthToLastRecursive(forward_list<int> &l, int k) {
  auto i = l.begin();
  auto kth = getKthIterator(i, l, k);
  return kth;
}

forward_list<int>::iterator fromKthToLast(forward_list<int> &l, int k) {
  auto i = l.begin();
  auto kth = getKthIterator(i, l, k);
  return kth;
}

int main() {
  forward_list<int> l = {1, 2, 3, 4, 5, 6};
  cout << toString(l) << endl;  
  int k;
  cin >> k;
  auto nl = fromKthToLastRecursive(l, k);
  cout << "last " << k << " elements are ";
  cout << toString(nl, l) << endl;

  // nl = fromKthToLast(l, k);
  return 0;
}