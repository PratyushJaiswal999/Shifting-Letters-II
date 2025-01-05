#BEST Solution
#Pratyush Jaiswal
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shift(n+1,0);
        for(auto& sh : shifts){
            int start = sh[0] , end = sh[1] , dir = sh[2];
            shift[start] += (dir == 1?1:-1);
            shift[end+1] -= (dir == 1?1:-1);
        }
        int currentshift = 0;
        for(int i=0;i<n;i++){
            currentshift += shift[i];
            shift[i] = currentshift;
        }
        for(int i=0;i<n;i++){
            int netsht = (shift[i]%26+26)%26;
            s[i] = 'a' + (s[i] - 'a' + netsht)%26;
        }
        return s;
    }
};
