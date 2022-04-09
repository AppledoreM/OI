import java.util.*;
import java.io.*;
import java.lang.Math;

public class Solution {
    static long MOD = 998244353L;
    public static void print(long[] aa){
        for(int i = 0; i < aa.length; ++i)
            System.out.print(aa[i] + "\t");
        System.out.println();
    }
    public static void print(int[] aa){
        for(int i = 0; i < aa.length; ++i)
            System.out.print(aa[i] + "\t");
        System.out.println();
    }
    public static class Pair{
        int a, b, c, d;
        public Pair(int a, int b, int c, int d){
            this.a = a;
            this.b = b;
            this.c = c;
            this.d = d;
        }
    }
    public static long dfs(long l, long r, HashSet<Long> s){
        if(l % 2 == 0 && r % 2 == 1){
            HashSet<Long> t = new HashSet<>();
            for(long v : s){
                t.add(v >> 1);
            }
            return (dfs(l >> 1, r >> 1, t)) << 1;
        }
        else{
            for(long v : s){
                if(!s.contains(v ^ 1)){
                    boolean ok = true;
                    long ans = v;
                    if(l % 2 == 0){
                        ans ^= r;
                    }
                    else{
                        ans ^= l;
                    }
                    for(long x : s){
                        if((x ^ ans) < l || (x ^ ans) > r){
                            ok = false;
                            break;
                        }
                    }
                    if(ok){
                        return ans;
                    }
                }
            }
        }
        return -1;
    }
    public static void main(String[] args){
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int tt = in.nextInt();
        in.nextLine();
        loop: for(int _m = 0; _m < tt; ++_m){
            long l = in.nextLong(), r = in.nextLong();
            HashSet<Long> set = new HashSet<>();
            for(long i = l; i <= r; ++i){
                set.add(in.nextLong());
            }
            System.out.println(dfs(l, r, set));
        }
    }
}