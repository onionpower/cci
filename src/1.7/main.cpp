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
    cout << endl;
    for (int j = i; j < c - i*2 - 1; j++) {
      int tmp = m[i*c+j];
      m[i*c+j] = m[(r-1-j)*c+i];
      m[(r-1-j)*c+i] = m[(r-1-i)*c+(c-1-j)];
      m[(r-1-i)*c+(c-1-j)] = m[(j)*c+(c-1-i)];
      m[(j)*c+(c-1-i)] = tmp;
      // m[(j)*c+(c-1-j)] = m[(r-1-j)*c+(c-1-i)];
      // m[(r-1-i)*c+j] = m[(r-j)*c+(r-i-1)];
      // m[]
      // cout << m[(r-1-i)*c+(c-1-j)] << endl;
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

// 1,1 -> tmp
// 2,1 -> 1,1
// 2,2 -> 1,2
// 1,2 -> 

// 0,0 -> tmp
// 3,0 -> 0,0
// 3,3 -> 3,0
// 0,3 -> 3,3

// tmp -> 0,3
// 1,0 -> tmp
// 2,0 -> 1,0
// 
int main() {
  int m[4][4] = {
    {11,12,13,14},
    {21,22,23,24},
    {31,32,33,34},
    {41,42,43,44}};
  print(*m, 4, 4);
  rotate(*m, 4, 4);
  cout << endl << endl;
  print(*m, 4, 4);

  int mr[4][4] = {
    {11,12,13,14},
    {21,22,23,24},
    {31,32,33,34},
    {41,42,43,44}};
  cout << "matrix are equal: " << boolalpha << assertEquals(*m, *mr, 4, 4) << endl;
  // delete m;
  return 0;
}