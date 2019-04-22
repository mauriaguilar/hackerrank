// Project Euler #1: Multiples of 3 and 5

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Solution 1: Common Solution
int main1() {
  int t, sum;
  cin >> t;

  // Constraint 1
  if (t >= 1 && t <= 100000)
    for (int a0 = 0; a0 < t; a0++) {
      int n;
      cin >> n;
      sum = 0;
      // Constraint 2
      if (n >= 1 && n <= 1000000000) {
        for (int i = 1; i < n; i++) {
          // Check multiples and add
          if (i % 3 == 0 || i % 5 == 0){
            sum += i;
          }
        }
        cout << sum << endl;
      }
    }
  return 0;
}

int calcSum(std::set<int> numbers, int baseIncrement, int n){
    int sum = 0;
    int sumT = 0;
    int base = 0;
    int last = *--numbers.end();
    std::set<int>::iterator it;

    // Calculate the sum of the multiples
    for (it = numbers.begin(); it != numbers.end(); ++it)
        sumT += *it;

    // Add multiples in blocks
    while (base + last < n) {
        sum += numbers.size() * base + sumT;
        base += baseIncrement;
    }
    // Iterate one more time and add
    for (it = numbers.begin(); it != numbers.end(); ++it)
        if (base + *it < n) {
            sum += (base + *it);
        } else
            break;

    return sum;
}

// Solution 2: More efficient!
int main() {
  int t, sum;
  std::set<int> numbers3 = {3, 6, 9, 12, 18, 21, 24, 27}; // AND NOT *5
  std::set<int> numbers5 = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};

  cin >> t;
  // Constraint 1
  if (t >= 1 && t <= 10e5)
    for (int a0 = 0; a0 < t; a0++) {
      int n;
      cin >> n;
      sum = 0;

      // Constraint 2
      if (n >= 1 && n <= 10e9)
        cout << calcSum(numbers3, 30, n) + calcSum(numbers5, 50, n) << endl;
    }
  return 0;
}
