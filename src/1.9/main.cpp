#include <iostream>

using namespace std;

void printIsRotated(string s1, string rotated) {
  string conc = s1 + s1;
  size_t place = conc.find(rotated);
  string conclusion;
  if (place == string::npos) {
    conclusion = "\" isn't rotated \"";
  } else {
    conclusion = "\" is rotated \"";
  }
  cout << "\"" << rotated << conclusion << s1 << "\"" << endl;
}

int main() {
  string s = "origin string";
  string rotated = "gin stringori";
  string noise = "gin strinPori";    
  printIsRotated(s, rotated);
  printIsRotated(s, noise);
  return 0;
}