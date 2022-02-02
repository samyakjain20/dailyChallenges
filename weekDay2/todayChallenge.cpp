#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    
    stack<int> st, maxEle;
    for(int i=0; i<n; i++){
        int t, x=0;
        cin>>t;
        if(t==1){                                   //type1 query
            cin>>x;
            st.push(x);                             //push element to the stack
            if(maxEle.empty())
                maxEle.push(x);
            else
                maxEle.push(max(x, maxEle.top()));  //mainting max element in the stack
        }
        else if(t==2){                              //type2 query
            st.pop();                               //poping the element
            maxEle.pop();                           
        }
        else
            cout<<maxEle.top()<<endl;               //printing the max element in the stack
    }
        
    return 0;
}