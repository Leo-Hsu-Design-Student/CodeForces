#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){

    int times; cin>>times;
    while(times--){
        string str; cin>>str;
        map<char, int> mapstr; 
        int cnt = 0;
        int a = 0, b = 0;
        for(int i = 0; i<str.length(); i++){
            auto iter = mapstr.find(str[i]);
            if(iter == mapstr.end()){
                mapstr[str[i]] = 1;
                cnt += 1;
            }else if(mapstr[str[i]] == 1){
                mapstr[str[i]]++;
                cnt += 1;
            }
        }
        cnt /= 2;
        cout<<cnt<<'\n';
    }

    return 0;
}