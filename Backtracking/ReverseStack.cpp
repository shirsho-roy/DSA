
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void insertback(stack<int> &St,int el){
        if(St.size()==0){
            St.push(el);
            return;
        }
        int t=St.top();
        St.pop();
        insertback(St,el);
        St.push(t);
        return ;
    }
    void Reverse(stack<int> &St){
        if(St.size()==1) return;
        int t=St.top();
        St.pop();
        Reverse(St);
        insertback(St,t);
        return;
    }
};

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
