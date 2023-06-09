//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    vector<pair<int,int>> movements={
        {-1,2},{1,2},
        {-1,-2},{1,-2},
        {-2,1},{2,1},
        {-2,-1},{2,-1}
    };
    const int inf=1e9+10;
    bool isValid(int N,int x,int y){
        return x>=0 && y>=0 && x<N && y<N;
    }
    int bfs(int N,vector<int>&KnightPos,vector<int>&TargetPos,map<pair<int,int>,int> &vis,map<pair<int,int>,int> &lvl)
      {
          int sourcex=KnightPos[0]-1;
          int sourcey=KnightPos[1]-1;
          int destx=TargetPos[0]-1;
          int desty=TargetPos[1]-1;
          queue<pair<int,int>> q;
          q.push({sourcex,sourcey});
          vis[{sourcex,sourcey}]=1;
          lvl[{sourcex,sourcey}]=0;
          while(!q.empty()){
              auto curr=q.front();
              int x=curr.first;
              int y=curr.second;
              q.pop(); 
              for(auto movement:movements){
                  int x2=x+movement.first;
                  int y2=y+movement.second;
                  if(!isValid(N,x2,y2)) continue;
                  
                  if(!vis[{x2,y2}])//Map ka rndom access complexity is O(n) so 2d array is preffered for this visited for optimisation
                  {
                  q.push({x2,y2});
                  vis[{x2,y2}]=1;
                  lvl[{x2,y2}]=lvl[{x,y}]+1;
                      if(x2==destx && y2==desty)
                           return lvl[{x2,y2}];
                  }
              }
              
          }
          return lvl[{destx,desty}];
      }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{ map<pair<int,int>,int> vis;
	  map<pair<int,int>,int> lvl;
	   int destx=TargetPos[0]-1;
       int desty=TargetPos[1]-1;
    
	    int res=bfs(N,KnightPos,TargetPos,vis,lvl);
	    if(res==INT_MAX) return -1;
	    else return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends