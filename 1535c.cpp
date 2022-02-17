#include<iostream>
#include<string>
#include<time.h>
using namespace std;

bool check(string sub){
    int len = sub.length();
    int i = 0;
    while(i < len){
        int id = i;
        switch (sub[id]){
            case '0': case '1':
                if(id != len-1){
                    //cout<<"ouput ";
                    if(sub[id+1]==sub[i]){
                        return false;
                    }
                }
                i++;
            case '?':
                id++;
                while(sub[id]=='?'){
                    id++;
                }
                if((id-i)%2 == 1){
                    if(i!=0 && id!=len){
                        if(sub[i-1] != sub[id]){
                            return false;
                        }
                    }
                }
                else{//(id-i)%2 == 0
                    if(i!=0 && id!=len){
                        if(sub[i-1] == sub[id]){
                            return false;
                        }
                    }
                }
                i = id;
        }
    }
    return true;
}

int main(){
    // double a = clock();
    int times;
    cin>>times;
    while(times--){
        string obj;
        cin>>obj;
        int len = obj.length();
        int cnt = len;
        if(check(obj)){
            long long len_ = len;
            long long result = (len_+1)*len_/2;
            cout<<result<<endl;
            // cout<<"You are right\n";
            continue;
        }
        // double c = clock();
        // cout<<"spend f: "<<(c-a)/CLOCKS_PER_SEC<<'\n';
        for(int i = 0; i<len; i++){//different initial point
            for(int j = 2; j<=len; j++){
                if(i+j<=len){
                    string sub = obj.substr(i, j);
                    //cout<<sub<<" is sub: "<<check(sub)<<" !\n";
                    if(check(sub)){
                        cnt++;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        cout<<cnt<<'\n';
    }
    // double b = clock();
    // cout<<"spend: "<<(b-a)/CLOCKS_PER_SEC<<'\n';
    return 0;
}