#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) {
    int n = c.size();
    int jumps = 0;

    // Constraints 1
    if(!(n>=2 && n<=100))
        return 0;

    for(int i=0; i<n-1; i++){
        // c[i] is ever 0
        if(c[i+2]==0){
            i += 1;
            jumps += 1;
            //cout << "s2, i=" << i+1 << "  jumps=" << jumps << endl;
        } else { // i+2=>1
            if (c[i + 1] == 0) {
                jumps += 1;
                //cout << "s1, i=" << i + 1 << "  jumps=" << jumps << endl;
            } else {
                //cout << "Error";
                return 0;
                //cout << "b2, i=" << i + 1 << "  jumps=" << jumps << endl;
            }
        }
    } // end for

    return jumps;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

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

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
