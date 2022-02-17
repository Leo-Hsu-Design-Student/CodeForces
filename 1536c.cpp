#include<iostream>
#include<string>
#include<vector>
#include<time.h>
using namespace std;

void print_v(vector<int> seg_pos){
    for(int i = 0; i<seg_pos.size(); i++){
        cout<<seg_pos[i]<<' ';
    }
}

int min(int a, int b){
    return a<b?a:b;
}

int gcd(int a, int b){//greatset common divisor
    return (b==0)?a:gcd(b, a%b);
}

int main(){
    double a = clock();
    int times; cin>>times;
    while(times--){
        int len; cin>>len;
        string str; cin>>str;
        int d_num = 0, k_num =0;
        int prefix[500001][2] = {0};
        //vector<vector<int>> warehouse;

        
        for(int i = 0; i<len; i++){
            int seg = 1;//segments
            if(str[i] == 'D'){
                d_num++;
            }
            else{
                k_num++;
            }
            prefix[i][0] = d_num;
            prefix[i][1] = k_num;
            if(d_num == 0 || k_num == 0){
                seg = (d_num == 0)?k_num:d_num;
                cout<<seg<<' ';
            }
            else{
                vector<int> seg_pos;
                for(int j = i; j>=0; j--){
                    if(prefix[j][0]*prefix[i][1] == prefix[j][1]*prefix[i][0]){
                        seg_pos.push_back(j);
                    }
                }
                cout<<seg_pos.size()<<' ';
                //print_v(seg_pos);
                //cout<<"i: "<<i<<'\n';
            }
        }
        //cout<<"times: "<<times<<'\n';
        cout<<'\n';
    }

    double b = clock();
    cout<<(b-a)/CLOCKS_PER_SEC<<'\n';
    return 0;
}