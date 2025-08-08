class Solution {
public:
    double dp[200][200];

    double probability(int a , int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1;
        if (b <= 0) return 0;
        if (dp[a][b]) return dp[a][b];

        return dp[a][b] = 0.25 * (probability(a - 4 , b) + probability(a - 3 , b - 1) + probability(a - 2 , b - 2) + probability(a - 1 , b - 3));
    }

    double soupServings(int n) {
        return  n > 4600 ? 1.0 : probability((n + 24) / 25 , (n + 24) / 25);
    }
};