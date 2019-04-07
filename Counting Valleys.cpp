#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int level = 0, count = 0;
    int is_valley = false;

    // Constraint 1
    if(!(n>=2 && n<=1000000)){
      cout << "Error in number of steps" << endl;
      return 0;
    }
    for (int i = 0; i < n; i++) {
        // Constraint 2
        if (s[i] != 'D' && s[i] != 'U'){
            cout<<"Error in type of step"<<endl;
            return 1;
        }
        // Check out valleys
        if (i != 0 && level == 0 && is_valley){
          count++;
          is_valley = false;
        }
        // Detect valley
        if (level == 0 && s[i] == 'D')
            is_valley = true;
        if (level == 0 && s[i] == 'U')
            is_valley = false;
        // Set current level
        if (s[i] == 'D')
            level -= 1;
        else
            level += 1;
    }
    // Check out valleys
    if (level == 0 && is_valley) {
      count++;
      is_valley = false;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
