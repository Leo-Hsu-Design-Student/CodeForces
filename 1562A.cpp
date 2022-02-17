#include<iostream>

using namespace std;
int main(){

    int rounds;
    cin>>rounds;
    int f, s;
    while(rounds--){
        cin>>f>>s;
        if((s/f) > 1){
            int div = s/2 + 1;
            cout<<s % div<<'\n';
        }
        else{
            cout<<s%f<<'\n';
        }
    }

    return 0;
}