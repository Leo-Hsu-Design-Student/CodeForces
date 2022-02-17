#include<iostream>
#include<string>
using namespace std;

int main(){

    int t; cin>>t;
    while(t--){
        
        // cout<<"here\n"<<t<<'\n';
        int n; cin>>n;
        string str; cin>>str;
        int tag = -1;
       
        for(int i = 0; i<n; i++){
            if(str[i] != '?'){
                tag = i;
                break;
            }
        }
        if(tag == -1){
            str[0] = 'B';
            for(int i = 1; i<n; i++){
                if(str[i-1] == 'B'){
                    str[i] = 'R';
                }else{
                    str[i] = 'B';
                }
            }
        }
        else{
            for(int i = tag; i<n; i++){
                if(str[i] == '?'){
                    if(str[i-1] == 'R'){
                        str[i] = 'B';
                    }else{
                        str[i] = 'R';
                    }
                }
            }
            for(int i = tag; i>0; i--){
                if(str[i] == 'R'){
                    str[i-1] = 'B';
                }else{
                    str[i-1] = 'R';
                }
            }
        }
        
        cout<<str<<'\n';
    }
    
    return 0;
}