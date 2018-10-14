#include <iostream>
#include <math.h>

using namespace std;

void print(int *m, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << to_string(m[i*c+j]) << " ";
    }
    cout << endl;
  }
}

void rotate(int *m, int r, int c) {
  for (int i = 0; i < r/2; i++) {
    for (int j = i; j < c - i - 1; j++) {
      int tmp = m[i*c+j];
      m[i*c+j] = m[(r-1-j)*c+i];
      m[(r-1-j)*c+i] = m[(r-1-i)*c+(c-1-j)];
      m[(r-1-i)*c+(c-1-j)] = m[(j)*c+(c-1-i)];
      m[(j)*c+(c-1-i)] = tmp;
    }
  }
}

bool assertEquals(int *m1, int *m2, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (m1[i*c+j] != m2[i*c+j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int m[4][4] = {
    {11,12,13,14},
    {21,22,23,24},
    {31,32,33,34},
    {41,42,43,44}};
  print(*m, 4, 4);
  rotate(*m, 4, 4);
  cout << endl << endl;

  int mr[4][4] = {
    {41,31,21,11},
    {42,32,22,12},
    {43,33,23,13},
    {44,34,24,14}};
  print(*mr, 4, 4);
  cout << "equals " << endl;
  print(*m, 4, 4); 
  cout << boolalpha << assertEquals(*m, *mr, 4, 4) << endl;
  return 0;
}