#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void solve(vector<int> A,vector<int> op,multiset<vector<int>> &res){
        if(A.size()==0){
            res.insert(op);
            return;
        }
        vector<int> op1=op;
        vector<int> op2=op;
        op1.push_back(A[0]);
        A.erase(A.begin());
        solve(A,op2,res);
        solve(A,op1,res);
        return;
    }
    vector<vector<int> > subsets(vector<int>& A)
    {  vector<int> op;
       multiset<vector<int>> res; //Multiset to return repeated subsets and not onl unique ones
       solve(A,op,res);
    //   return res;
       vector<vector<int>> v;
       while(!res.empty()){
           auto t=*(res.begin());
           v.push_back(t);
           res.erase(res.begin());
       }
       return v;
    }
};

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}
	}

	return 0;
}
