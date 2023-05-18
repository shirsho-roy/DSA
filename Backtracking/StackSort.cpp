#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &st,int t){
    if(st.size()==0 || st.top()<t){
        st.push(t);
        return;
    }
    int temp=st.top();
    st.pop();
    insert(st,t);
    st.push(temp);
    return;
}
 void sort(stack<int> &st){
    if(st.size()==1) return;
    int top=st.top();
    st.pop();
    sort(st);
    insert(st,top);
    return;
 }
 int main(){
    stack<int> st;
    st.push(2);
    st.push(1);
    st.push(4);
    st.push(5);
    st.push(3);
    sort(st);
    while(!st.empty()){
        int x=st.top();
        cout<<x<<" ";
        st.pop();
    }
    return 0;
 }