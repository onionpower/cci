#include <iostream>
#include <forward_list>
#include <queue>
#include <iterator>

using namespace std;
typedef std::forward_list<int>::iterator fwd_iterator;
typedef std::forward_list<int> fwd_list;

int compose(fwd_list l) {
  queue<int> s;
  
  for(auto& it : l)
  {
    s.push(it);
  }
  
  int r = 0;
  for(int i = 1; !s.empty(); i *= 10, s.pop())
  {
    r += i * s.front();
  }
  
  return r;
}

int main() {
  fwd_list l1 = {1, 2, 3};
  fwd_list l2 = {4, 5, 6, 7};
  // 321 + 7654 = 7975
  auto sum = compose(l1) + compose(l2);
  cout << "sum = " << sum << endl;
  return 0;
}