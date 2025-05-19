class Solution {
    public boolean isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int num = x;
        int revnum= solution(x,0);
        if(num==revnum){
            return true;
        }
        else{
            return false;
        }
    }
    public int solution(int x, int rev){
        if(x==0){
            return rev;
        }
        if(rev>Integer.MAX_VALUE/10 || rev<Integer.MIN_VALUE/10){
            return 0;
        }
        int rem = x%10;
        x=x/10;
        rev=rev*10 + rem;
        
        return solution(x,rev) ;
    }
}