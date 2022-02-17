#include<iostream>
using namespace std;

int main(){
    int times; cin>>times;
    while(times--){
        int tot; cin>>tot;
        int c1, c2;
        if(tot % 3 == 0){
            c1 = tot/3;
            c2 = c1;
        }
        else if(tot%3 == 1){
            c1 = tot/3;
            c2 = c1;
            c1++;
        }
        else{
            c1 = tot/3;
            c2 = c1; 
            c2++;
        }
        cout<<c1<<' '<<c2<<'\n';
    }

    return 0;
}