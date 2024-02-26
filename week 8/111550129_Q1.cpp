#include <bits/stdc++.h>

using namespace std;

int bubble_sort(vector<int> a){
    int cnt = 0;
    int n = a.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int k;
    cin>>k;
    if(k>=0&&k<=50){
        for(int i=0;i<k;i++){
             int n;
            cin >> n;
            vector<int> a(n);
                for(int i=0;i<n;i++){
                    cin >> a[i];
                }
            cout <<"The minimum number of exchanges needed is "<< bubble_sort(a) <<"."<< endl;
            }
    }
}
