#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long count = 0, amount_one_string = 0;
    // Constraints
    if (!(s.size()>=1 && s.size()<=100) || !(n>=1 && n<=1000000000000))
        return 0;

    if(n > s.size()){
      amount_one_string = std::count(s.begin(), s.end(), 'a');
      count = amount_one_string * (n / s.size());
      // amount_one_string * (n / s.size()) == amount_one_string * n / s.size()
      // si y solo si no hay truncamiento en la division
      cout << "amount_one_string = " << amount_one_string << endl;
      cout << "n/s.size() = " << n / s.size() << endl;
      cout << "count = " << count << endl;
    }
    count += std::count(s.begin(), s.begin() + n%s.size(), 'a');
    cout<<"count = "<<count<<endl;

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
