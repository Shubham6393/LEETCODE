class Solution {
public:
    void fun(vector<int> &temp, int low, int high){
        while(low<high){
            swap(temp[low],temp[high]);
            low++;
            high--;
        }

    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        vector<int> temp;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                temp.push_back(grid[i][j]);
            }
        }
        int len = temp.size();
        int ktemp = k % len;
        fun(temp,0,len - ktemp - 1);  // for first half like 'k' ke pehle jitne element hai uske liye reverse karenge
        fun(temp,len - ktemp, len-1); // for second half like 'k' ke baad jitne elemennt hai usko reverse karega
        fun(temp,0,len - 1); // aab jitna bhi temp me update hua hai pure ko reverse kar do
        vector<vector<int>> ans( grid.size() /* m */ , vector<int>(grid[0].size()  /* n */ , 0  /* initialize with 0 */));
        int ind = 0;
        for(int i =0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                ans[i][j] = temp[ind++];
            }
        }
        return ans;
    }
};