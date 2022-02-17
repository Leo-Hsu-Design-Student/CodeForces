#include<iostream>
#include<string>
#include<vector>
using namespace std;

// void print_v(vector< vector<int> > fg){
//     int size = fg.size();
//     for(int i = 0; i<size; i++){
//         for(int j = 0; j<fg[i].size(); j++){
//             cout<<fg[i][j]<<' ';
//         }
//         cout<<'\n';
//     }
// }

int main(){

    int times; cin>>times;
    while(times--){
        string obj; cin>>obj;
        int len = obj.length();
        //cout<<"length: "<<len<<'\n';
        long long len_ = len;
        long long cnt = (len_+1)*len_/2;
        //set the standard of the "false"!
        //1.consecutively show up "0" or "1"
        //2.There are odd number of "?" between "0" and "1"
        //3.There are even number of "?" between two "0" or two "1"
        //check the pos of the false:
        vector< vector<int> > fg;
        int i = 0;
        while(i < len){
            int id = i;
            if(obj[i] == obj[i+1] && obj[i]!='?'){//1
                vector<int> store;
                store.push_back(i);
                store.push_back(i+1);
                fg.push_back(store);
            }
            else{
                if(obj[i] == '0' || obj[i] == '1'){
                    while(obj[id+1] == '?'){
                        id++;
                    }
                    if(((id - i)%2 == 0 && obj[id+1] == obj[i]) || ((id - i)%2 == 1 && obj[id+1] != obj[i])){
                        vector<int> store;
                        store.push_back(i);
                        store.push_back(id+1);
                        fg.push_back(store);
                        i = id+1;
                        continue;
                    }
                }
            }
            i++;
        }
        //print_v(fg);
        int fg_size = fg.size();
        for(int i = 0; i<fg_size; i++){
            int minus = 0;
            if(i == fg_size-1){//the last false case 
                minus = (fg[i][0]+1)*(len - fg[i][1]);
            }
            else{
                minus = (fg[i][0]+1)*(fg[i+1][1] - fg[i][1]);
            }
            //cout<<"cnt: "<<cnt<<'\n';
            cnt -= minus;
        }
        cout<<cnt<<'\n';
        

    }

    return 0;
}