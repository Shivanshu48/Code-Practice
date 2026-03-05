class Solution {
public:
    vector<pair<int,int>> previ(int x,int y)
    {
        vector<pair<int,int>> can;
        if(x==y)
        {
            can.push_back({0,y});
            can.push_back({x,0});
            return can;
        }
        if(y<x)
        {
            if(x%2==0)
            {
                if(x/2>=y) can.push_back({x/2,y});
                else
                {
                    if(x-y<=y) can.push_back({x-y,y});
                }
            }
            else
            {
                if(x-y<=y) can.push_back({x-y,y});
            }
        }
        if(x<y)
        {
            if(y%2==0)
            {
                if(y/2>=x) can.push_back({x,y/2});
                else
                {
                    if(y-x<=x) can.push_back({x,y-x});
                }
            }
            else
            {
                if(y-x<=x) can.push_back({x,y-x});
            }
        }
        return can;
    }
    int dfs(int sx,int sy,int a,int b)
    {
        if(a<sx||b<sy) return 1e9;
        if(a==sx&&b==sy) return 0;
        vector<pair<int,int>> pre = previ(a,b);
        int ans=1e9;
        for(auto[x,y]: pre)
        {
            ans = min(ans,1+dfs(sx,sy,x,y));
        }
        return ans;
    }
    int minMoves(int sx, int sy, int tx, int ty) {
        int ans = dfs(sx,sy,tx,ty);
        return ans>=1e9?-1:ans;
    }
};