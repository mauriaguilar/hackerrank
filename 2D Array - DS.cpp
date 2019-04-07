#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int sum[16], max=-999;
    for(int i=1, n=0; i<arr[0].size()-1; i++){
        for(int j=1; j<arr[0].size()-1; j++, n++){
            if(arr[i][j] < -9 || arr[i][j] > 9){
                sum[n]=0;
                break;
            }
            sum[n] = arr[i - 1][j - 1] + arr[i - 1][j] + arr[i - 1][j+1]
                   + arr[i][j]
                   + arr[i + 1][j - 1] + arr[i + 1][j] + arr[i + 1][j + 1];
        }
        cout<<endl;
    }

    for (int i = 0; i < 16 ; i++){
        if (sum[i]>max)
            max = sum[i];
    }

    cout<<"max "<<max;
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
