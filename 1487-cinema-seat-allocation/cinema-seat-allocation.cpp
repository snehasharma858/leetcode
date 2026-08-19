class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, set<int>> mp;
        for (auto &x : reservedSeats) {
            mp[x[0]].insert(x[1]);
        }

        int ans = 2 * (n - mp.size());

         for (auto &it : mp) {
            set<int> seats = it.second;
             bool left = true;    
            bool middle = true;  
            bool right = true;
             for (int seat = 2; seat <= 5; seat++) {
                if (seats.count(seat))
                    left = false;
            }

            for (int seat = 4; seat <= 7; seat++) {
                if (seats.count(seat))
                    middle = false;
            }

            for (int seat = 6; seat <= 9; seat++) {
                if (seats.count(seat))
                    right = false;
            }
             if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
         }

        
        return ans;

    }
};