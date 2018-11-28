#include <iostream>
#include <forward_list>
#include <queue>
#include <iterator>

using namespace std;
typedef std::forward_list<int>::iterator fwd_iterator;
typedef std::forward_list<int> fwd_list;

int compose_using_queue(fwd_list l) {
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

int compose_using_mul(fwd_list l) {
  auto r = 0;
  auto mul = 1;
  for(auto& it : l)
  {
    r += it * mul;
    mul *= 10;
  }
  return r;
}

int sum_lists_using_queue(fwd_list l1, fwd_list l2) {
  auto sum = compose_using_queue(l1) + compose_using_queue(l2);
  return sum;
}

int sum_lists_using_mul(fwd_list l1, fwd_list l2) {
  auto sum = compose_using_mul(l1) + compose_using_mul(l2);
  return sum;
}

int main() {
  fwd_list l1 = {1, 2, 3};
  fwd_list l2 = {4, 5, 6, 7};
  // 321 + 7654 = 7975
  auto sum = sum_lists_using_queue(l1, l2);
  cout << "queue: sum = " << sum << endl;
  sum = sum_lists_using_mul(l1, l2);
  cout << "mul: sum = " << sum << endl;
  int i = 1;
  cout << i << endl;
  i = i << 1;
  cout << i << endl;
  return 0;
}