class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // sort greed factors
        sort(s.begin(), s.end()); // sort cookie sizes
        
        int i = 0; // child pointer
        int j = 0; // cookie pointer

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                // Assign cookie to child
                i++; // move to next child
            }
            // Move to next cookie in both cases (whether assigned or not)
            j++;
        }

        return i; // number of content children
    }
};
