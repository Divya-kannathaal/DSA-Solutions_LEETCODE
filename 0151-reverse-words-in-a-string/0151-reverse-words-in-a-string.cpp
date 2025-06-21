class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int start = 0, end=0;
        
        int i=0;
        while(i<n){
            while(i<n && s[i] == ' ') i++;
            if(i==n) break;
            
            while(i<n && s[i] != ' '){
                s[end] = s[i];
                end++ ; i++;
            }
            reverse(s.begin() + start, s.begin() + end);
            s[end] = ' ';
            end++; i++;
            start = end;
        }
        s.resize(end-1);
        reverse(s.begin(), s.end());
        return s;
    }
};