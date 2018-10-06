#include <iostream>

using namespace std;

string compress(string s) {
  if (s.size() < 2) {
    return s;
  }

  string compressed;
  char c = s[0];
  for (int i = 1, counter = 1; i < s.size(); i++) {
    if (i == s.size() - 1) {
      if (s[i] == c) {
        compressed += c;
        compressed += to_string(++counter);
        break;
      }
      compressed += c;
      compressed += to_string(counter);
      compressed += s[i];
      compressed += to_string(1);
      break;
    }
    if (s[i] == c) {
      counter++;
      continue;
    }
    compressed += c;
    compressed += to_string(counter);
    c = s[i];
    counter = 1;
  }
  return compressed.size() < s.size() ? compressed : s;
}

int main() {
  string samples[] = {
    "abbccdeeefg",
    "aaabbbbddddeeeeffff",
    "abcdeeeeee",
    "abcdef",
    "aabbccdd"
    };
  for (auto& s : samples) {
    cout << s << " -> " << compress(s) << endl;
  }
  return 0;
}