#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        vector<int> vec;
        int n;cin>>n;
        for(int i = 0; i<n; i++){
            int a;cin>>a;
            vec.push_back(a);
        }
        
        sort(vec.begin(), vec.end());
        int min = -1;
        for(int i = 0; i<n; i++){
            if(min == -1){
                min = vec[n-1]&vec[i];
            }
            else{
                min = min > (min&vec[i])?(min&vec[i]):min;
            }
        }
        
        cout<<min<<'\n';
    }
    
    return 0;
}