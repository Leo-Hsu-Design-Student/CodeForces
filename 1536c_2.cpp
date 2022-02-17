#include<iostream>
#include<string>
#include<map>
#include<utility>
using namespace std;

int gcd(int a, int b){//greatset common divisor
    return (b == 0)?a:gcd(b, a%b);
}

int main(){

    int times; cin>>times;
    while(times--){
        int len; cin>>len;
        string str; cin>>str;
        int d_num = 0, k_num = 0;
        map<pair<int, int>, int> table;
        for(int i = 0; i<len; i++){
            if(str[i] == 'D')
                d_num++;
            else
                k_num++;
            //store int the map table
            int hcf = gcd(d_num, k_num);
            int first = d_num/hcf;
            int second = k_num/hcf;
            pair<int, int> key(first, second);
            if(table.find(key) != table.end()){
                table[key]++;
            }
            else{
                table.insert(make_pair(key, 1));
            }
            cout<<table[key]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}