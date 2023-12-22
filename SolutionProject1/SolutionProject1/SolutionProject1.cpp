#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    int Count = 0;
    int RCount = 1;
    int Temp = 0;
    int X = 0;
    int Y = 0;
    int BoolX = true;
    int BoolY = false;
    vector<vector<int>> v1;
    vector<int> v2(n);
    for (int i = 0; i < n; ++i) {
        v1.push_back(v2);
    }

    for (int i = 0; i < n; ++i) {
        v1[0][i] = i;
    }

    while (Count != n * n) {

        Temp = n;
        while (Temp - Count) {
            v1[0][n - ];
            --Temp;
        }



        ++Count;
        if (Count == 2) {
            ++RCount;
            Count = 0;
        }
    }
    vector<vector<int>> answer;
    return answer;
}