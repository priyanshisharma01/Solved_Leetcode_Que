// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:


vector<vector<int>> floodFillHelper(vector<vector<int>>& image, int sr, int sc, int newColor,int prev) {
        
        if(sr<0 || sr >= image.size() || sc <0 || sc >= image[0].size())
        {
            return image;
        }
        if(image[sr][sc]==newColor)
        {
            return image;
        }
        if(image[sr][sc]!=prev)
        {
            return image;
        }
        if(image[sr][sc]==prev)
        {
            image[sr][sc]=newColor;
        }
        
         image= floodFillHelper(image,  sr+1,  sc,  newColor,prev);
        image= floodFillHelper(image,  sr-1,  sc,  newColor,prev);
        image= floodFillHelper(image, sr,  sc+1,  newColor,prev);
         image= floodFillHelper(image,  sr,  sc-1,  newColor,prev);
        return image;
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int prev=image[sr][sc];
        
         image= floodFillHelper(image,  sr,  sc,  newColor,prev);
        
        return image;
        
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends