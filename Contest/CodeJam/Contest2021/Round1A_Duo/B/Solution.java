import java.util.*;
import java.io.*;
import java.lang.Math;

public class Solution {
    static long MOD = 1000000007L;
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
    static long[][] arr;
    static long max, tot;
    public static void dfs(long p, long rem, int ind){
        //base case
        if(rem == p){
            max = Math.max(p, max);
            return;
        }
        if(ind == arr.length){
            return;
        }
        int i = 0;
        if((rem - arr[ind][0]) / p < arr[ind][0]){
            return;
        }
        for(i = 0; i <= (int)arr[ind][1]; ++i){
            dfs(p, rem, ind + 1);
            if(rem >= max + arr[ind][0] && (rem - arr[ind][0]) / p >= arr[ind][0]){
                p *= arr[ind][0];
                rem -= arr[ind][0];
            }
            else{
                return;
            }
        }
    }
    public static void main(String[] args){
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int tt = in.nextInt();
        in.nextLine();
        loop: for(int _m = 0; _m < tt; ++_m){
            System.out.print("Case #" + (_m + 1) + ": ");
            int m = in.nextInt();
            arr = new long[m][2];
            max = 0L;
            tot = 0L;
            for(int i = 0; i < m; ++i){
                arr[i][0] = in.nextLong();
                arr[i][1] = in.nextLong();
                tot += arr[i][0] * arr[i][1];
            }
            dfs(1L, tot, 0);
            System.out.println(max);
        }
    }
}