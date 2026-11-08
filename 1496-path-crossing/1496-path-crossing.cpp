class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> st;
        int x = 0,y=0;
        st.insert({0,0});
        for(auto it : path){
            if(it == 'N'){
                y++;
            }
            else if(it == 'E')x++;
            else if(it == 'S')y--;
            else x--;
            if(st.count({x,y}))return true;
            st.insert({x,y});
        }
        return false;
    }
};