class Solution {
    private char[] preprocess(String s) {
        char[] t = new char[s.length()*2 + 3];
        char[] ss = s.toCharArray();
        t[0] = '$';
        t[ss.length*2 + 2] = '@';
        for (int i = 0; i < ss.length; i++) {
            t[2*i + 1] = '#';
            t[2*i + 2] = ss[i];
        }
        t[ss.length*2 + 1] = '#';
        return t;
    }
    
    public int[] Manacher(String s){
        char[] t = preprocess(s);
        int[] p = new int[t.length];
        int center = 0, right = 0;
        for(int i=1;i<t.length-1;++i){
            int mirror = 2*center - i;
            if(right>i)
                p[i]=Math.min(right-i,p[mirror]);
            while(t[i+(1+p[i])]==t[i-(1+p[i])])
                ++p[i];
            if(i+p[i]>right){
                center=i;
                right=i+p[i];
            }
        }
        return p;
    }
    
    public String longestPalindrome(String s) {
        int[] p = Manacher(s);
        int length = 0;   // length of longest palindromic substring
        int center = 0;   // center of longest palindromic substring
        for (int i = 1; i < p.length-1; i++) {
            if (p[i] > length) {
                length = p[i];
                center = i;
            }
        }
        return s.substring((center - 1 - length) / 2, (center - 1 + length) / 2);
    }
}