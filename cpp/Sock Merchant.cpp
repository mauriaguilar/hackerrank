#include <bits/stdc++.h>
#include <math.h>

using namespace std;

vector<string> split_string(string);

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
  float socks_number, socks_of_this_color;
  bool the_color_was_counted;

  // Constraints 1
  if (n < 1)
    return 0;

  if (n > 100)
    n = 100;

  socks_number = 0;
  for (int i = 0; i < n - 1; i++) {
    // Constraints 2
    if (ar[i] >= 1 && ar[i] <= 100) {
      // Verify if this color is counted yet
      the_color_was_counted = false;
      for (int c = 0; c < i; c++) {
        if (ar[i] == ar[c]) {
          the_color_was_counted = true;
          break;
        }
      }
      // Count number of this color
      if (!the_color_was_counted) {
        socks_of_this_color = 1;
        for (int j = i + 1; j < n; j++) {
          if (ar[i] == ar[j]) {
            socks_of_this_color++;
          }
        }
        socks_number += trunc(socks_of_this_color / 2);
      }
    }
  }

  return socks_number;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string ar_temp_temp;
  getline(cin, ar_temp_temp);

  vector<string> ar_temp = split_string(ar_temp_temp);

  vector<int> ar(n);

  for (int i = 0; i < n; i++) {
    int ar_item = stoi(ar_temp[i]);

    ar[i] = ar_item;
  }

  int result = sockMerchant(n, ar);

  fout << result << "\n";

  fout.close();

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char &x, const char &y) { return x == y and x == ' '; });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(
      input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
