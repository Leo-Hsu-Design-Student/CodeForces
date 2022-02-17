#include<iostream>
#include<vector>
using namespace std;

int main(){

    int times; cin>>times;
    while(times--){
        int len, M_len, P_len;
        cin>>len>>M_len>>P_len;
        int op1[M_len], op2[P_len];
        for(int i = 0; i<M_len; i++){
            cin>>op1[i];
        }
        for(int i = 0; i<P_len; i++){
            cin>>op2[i];
        }
        int cnt = 0;
        int tot = M_len+P_len;
        vector<int> seq;
        int id_M = 0, id_P = 0;
        while(id_M < M_len || id_P < P_len){
            if(id_M<M_len){
                if(op1[id_M] == 0){
                    seq.push_back(op1[id_M]);
                    len++; id_M++; cnt = 0;
                }
                else{
                    if(op1[id_M] > len){
                        cnt++;
                        if(cnt == 2){
                            seq.clear();
                            seq.push_back(-1);
                            break;
                        }
                    }
                    else{
                        seq.push_back(op1[id_M]);
                        id_M++; cnt = 0;
                    }
                }
            }
            if(id_P<P_len){
                if(op2[id_P] == 0){
                    seq.push_back(op2[id_P]);
                    len++; id_P++; cnt = 0;
                }
                else{
                    if(op2[id_P] > len){
                        cnt++;
                        if(cnt == 2){
                            seq.clear();
                            seq.push_back(-1);
                            break;
                        }
                    }
                    else{
                        seq.push_back(op2[id_P]);
                        id_P++; cnt = 0;
                    }
                }
            }
            
        }
        for(int i = 0; i < seq.size(); i++){
            cout<<seq[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}