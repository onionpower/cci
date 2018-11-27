#include <iostream>
#include <forward_list>
#include <iterator>

using namespace std;
typedef std::forward_list<int>::iterator forw_list_it;

string to_string(forward_list<int> &l) {  
  string s;
  for(auto it = l.begin(); it != l.end(); it++)
  {
    s.append(to_string(*it));
    s.append(" ");
  }
  return s;
}

forw_list_it insert_after(forward_list<int> &l, forw_list_it it, int v) {
  if (l.begin() == l.end()){
    l.push_front(v);
    it = l.begin();
  } else {
    l.insert_after(it, v);        
    it++;
  }
  return it;
}

forward_list<int> partition(forward_list<int> l, int p) {
  forw_list_it li, ri;
  forward_list<int> left;
  forward_list<int> right;  
  auto i = 0;
  for(auto it = l.begin(); it != l.end(); it++, i++)
  {
    if (i == p) {
      continue;
    }
    if (*it < p) {
      li = insert_after(left, li, *it);
    } else {
      ri = insert_after(right, ri, *it);
    }
  }
  left.insert_after(li, p);
  li++;
  left.splice_after(li, right);

  return left;
}

int main() {
  forward_list<int> l = {1, 2, 3, 4, 5, 5, 1, 2, 3, 4, 5};
  cout << to_string(l) << endl;    
  int p;
  cin >> p;
  if (!cin.good()) {
    cout << "incorrect input" << endl;
    return 0;
  }
  auto pl = partition(l, 3);
  cout << to_string(pl) << endl;    
  return 0;
}