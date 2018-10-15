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

int main() {  
  int m[4][4] = {
    {1, 2, 0, 3},
    {0, 2, 3, 0},
    {1, 2, 3, 4},
    {1, 2, 3, 0}
  };
  cout << toString(*m, 4, 4) << endl;
  return 0;
}