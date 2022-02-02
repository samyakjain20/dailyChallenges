#include <bits/stdc++.h>
using namespace std;

int avgWaitTime(int orderT[], int cookT[], int n){
    int currT=0;                            //to maintain time 
    int waitT=0;                            //adding the wait time
    int ctr=0, minT = INT_MAX, id=0;
    bool flag = false, orders[n];
    memset(orders, true, sizeof(orders));   //in start all orders need to be cooked
    
    while(ctr<n){
        for(int i=0; i<n; i++)
            if(orders[i] && orderT[i] <= currT && minT >= cookT[i]){
                flag = true;
                minT = cookT[i];            //min cooking time
                id = i;                     //index of the order with min cooking time
            }
        
        if(flag){
            flag = false;
            orders[id] = false;             //to make this order is cooked
            minT = INT_MAX;
            currT += cookT[id];             //time after this order is cooked
            waitT += (currT - orderT[id]);  //adding the wait for this order
            ctr++;                          //increase the count for order's served 
        }
        else currT++;
    }
    
    return waitT/n;                 //returning the total avg wait time
} 

int main() {
    int n;
    cin>>n;                         //no of orders
    
    int orderT[n];                  //customer order time
    int cookT[n];                   //time req to cook their respective pan 
    for(int i=0; i<n; i++)
        cin>>orderT[i]>>cookT[i];
        
    cout<<"Avg Wait Time will be: "<<avgWaitTime(orderT, cookT, n);
	return 0;
}