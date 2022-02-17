#include<iostream>
#include"bits/stdc++.h"

using namespace std;
#define MAXN 1e9+1

void solve(){

    int n;
    cin>> n;
    int maxR = 0, minL = MAXN, minCost = 0, maxLen = 0, costLen = MAXN;
    int costL = 0, costR = 0;
    while(n--){
        int left, right, cost;
        cin>>left>>right>>cost;

        if(maxR < right){
            maxR = right;
            costR = MAXN;
        }
        if(maxR == right){
            costR = min(cost, costR);
        }
        if(left < minL){
            minL = left;
            costL = MAXN;
        }
        if(left == minL){
            costL = min(cost, costL);
        }
        
        if(right - left +1 > maxLen){
            maxLen = right - left +1;
            costLen = MAXN;
        }
        if(right - left +1 == maxLen){
            costLen = min(cost, costLen);
        }

        int minCost = costL + costR;

        if(maxLen == maxR - minL +1){
            minCost = min(minCost, costLen);
        }

        // //one segment
        // if(left < minL && right > maxR){
        //     minL = left;
        //     maxR = right;
        //     minCost = cost;
        //     costL = cost;
        //     costR = cost;
        // }else{//two segment
        //     if(left < minL ){
        //         minL = left;
        //         costL = cost;
        //         if(right == maxR){
        //             if(cost < costR){
        //                 costR = cost;
        //             }
        //             minCost = cost;
        //         }else{
        //             minCost = costL + costR;
        //         }
        //     }else if(left == minL){
        //         if(cost < costL){
        //             costL = cost;
        //         }
        //         if(right > maxR){
        //             maxR = right;
        //             costR = cost;
        //             minCost = cost;
        //         }else if(right == maxR){
        //             if(cost < costR){
        //                 costR = cost;
        //             }
        //             minCost = min(cost, costR + costL);
        //         }else{
        //             minCost = min(minCost, costR + costL);
        //         }
        //     }else{
        //         if(right > maxR){
        //             maxR = right;
        //             costR = cost;
        //         }else if(right == maxR){
        //             if(costR > cost){
        //                 costR = cost;
        //             }
        //         }
        //         minCost = costR + costL;
        //     }
            
        // }
        // cout<<"costL:"<<costL<<" costR:"<<costR<<" cost:"<<minCost<<endl;
        // cout<<"minL:"<<minL<<" maxR:"<<maxR<<endl;
        cout<<minCost<<endl;
    } 
    //find the largest right
    //find the smallest left
    //maintain the largest seg and its cost
    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}