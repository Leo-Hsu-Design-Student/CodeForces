#include<iostream>
#include<vector>
#include<map>
using namespace std;

const int MAX_N = 200000 + 1;

int main(){

    int times; cin>>times;
    while(times--){
        int num, color; cin>>num>>color;
        int seq[MAX_N] = {0};
        int cnt = 0;
        map< int, vector<int> > Map;
        for(int i  = 0 ; i< num; i++){
            cin>>seq[i];
            if(Map[seq[i]].size() < color){
                Map[seq[i]].push_back(i);
                cnt ++;
            }
        }
        cnt /= color;

        int output[MAX_N] = {0};
        int cnt2 = 0;
        for(auto i : Map){
            for(auto j : i.second){
                cnt2 ++;
                output[j] =  cnt2;
                if(cnt2 == color){
                    cnt--;
                }
                cnt2 %= color;
                if(cnt == 0){
                    goto print_;
                }
            }
        }
        print_:
            for(int i = 0; i<num; i++){
                cout<<output[i]<<' ';
            }
            cout<<'\n';
    }   

    return 0;
}