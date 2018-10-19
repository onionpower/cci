#include <iostream>

using namespace std;

string toString(int *m, int r, int c){
  if (c == 0 || r ==0) {
    return "";
  }
  string res;
  res.reserve(r*c*3+r);
  int lastCommaIndex = c - 1;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      res += to_string(m[i*c+j]);
      if (j < lastCommaIndex)
        res += ", ";
    }
    res += "\n";
  }
  return res;
}

void memInFirstRowsAndCols(int *m, int r, int c) {
  for (int i = 1; i < r; i++) {
    for (int j = 1; j < c; j++) {
      if (m[i*c+j] == 0) {
        m[i*c] = 0;
        m[j] = 0;
      }
    }
  }
}

void nullifyRows(int *m, int r, int c) {
  for (int i = 0; i < r; i++) {
    if (m[i*c] == 0) {
      for (int j = 1; j < c; j++) {
        m[i*c+j] = 0;
      }
    }
  }
}

void nullifyCols(int *m, int r, int c) {
  for (int i = 0; i < c; i++) {
    if (m[i] == 0) {
      for (int j = 1; j < r; j++) {
        m[j*c+i] = 0;
      }
    }
  }
}

void nullifyRow(int *m, int row, int c) {
  for (int i = 0; i < c; i++) {
    m[row*c+i] = 0;
  }
}

void nullifyCol(int *m, int col, int r, int c) {
  for (int i = 0; i < r; i++) {
    m[i*c+col] = 0;
  }
}

void nullify(int *m, int r, int c) {
  bool firstRowHasZero = false;
  bool firstColHasZero = false;

  for (int i = 0; i < c; i++) {
    if (m[i] == 0) {
      firstRowHasZero = true;
      break;
    }
  }

  for (int i = 0; i < r; i++) {
    if (m[i*r] == 0) {
      firstColHasZero = true;
      break;
    }
  }

  memInFirstRowsAndCols(m, r, c);
  nullifyRows(m, r, c);
  nullifyCols(m, r, c);

  if (firstRowHasZero) {
    nullifyRow(m, 0, r);
  }
  if (firstColHasZero) {
    nullifyCol(m, 0, c, r);
  }
}

int main() {  
  int m[4][4] = {
    {1, 2, 1, 3},
    {0, 2, 3, 0},
    {1, 2, 3, 4},
    {1, 2, 3, 0}
  };
  cout << toString(*m, 4, 4) << endl;
  nullify(*m, 4, 4);
  cout << toString(*m, 4, 4) << endl;
  return 0;
}