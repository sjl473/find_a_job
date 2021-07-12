#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
using namespace std;

int cutting(int F[], int n)
{
    int* R = new int[n + 1];
    for(int i = 0; i < n; i++) {
        R[i] = 0;
    }
    vector<vector<int> > v = vector<vector<int> >(n + 1, vector<int>());
    //todo: under test
    for(int i = 1; i <= n; i++) {
        int q = -1;  
        for(int j = i; j >= 1; j--) {
            if(q <= F[j - 1] + R[i - j]) {
                q = F[j - 1] + R[i - j];
                vector<int> temp = v[i - j];
                temp.push_back(j);
                v[i] = temp;
            } else {
                q = q;
            }
        }
        R[i] = q;
    }
    return R[n];
}
int main()
{
    const int n = 4;
    int F[n] = {2, 5, 8, 9};
              
    int res = cutting(F, n);

    cout << "answer = " << res << endl;

    
    return 0;
}







