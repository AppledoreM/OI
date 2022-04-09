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
    public static void main(String[] args){
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int tt = in.nextInt();
        in.nextLine();
        loop: for(int _m = 0; _m < tt; ++_m){
            int n = in.nextInt();
            if(n % 2 == 1){
                System.out.println(0);
                continue;
            }
            n /= 2;
            long ans = 1L;
            for(int i = 1; i <= n; ++i){
                ans = (ans * i) % MOD;
            }
            ans = (ans * ans) % MOD;
            System.out.println(ans);
        }
    }
}