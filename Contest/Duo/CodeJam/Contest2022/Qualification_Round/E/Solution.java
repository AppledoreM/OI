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
    public static long[] arr;
    public static HashMap<Integer, HashSet<Integer>> map;
    public static long[] dfs(int cur){
        long sum = 0L, min = 1000000000000L, max = 0L;
        if(map.get(cur).isEmpty()){
            long[] ret = {arr[cur], arr[cur]};
            return ret;
        }
        for(int ele : map.get(cur)){
            long[] res = dfs(ele);
            sum += res[0];
            min = Math.min(min, res[1]);
            max = Math.max(max, res[1]);
        }
        if(min < arr[cur]){
            sum += arr[cur] - min;
        }
        long[] ret = {sum, Math.max(min, arr[cur])};
        return ret;
    }
    public static void main(String[] args){
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int tt = in.nextInt();
        Random rand = new Random();
        loop: for(int _m = 0; _m < tt; ++_m){
            long n = in.nextLong(), k = in.nextLong(), cur = in.nextLong(), p = in.nextLong();
            double tot = 0.0;
            long[] deg = new long[(int)n + 1];
            for(int i = 0; i < 4000; ++i){
                System.out.println("T " + (rand.nextInt((int)n) + 1));
                System.out.flush();
                in.nextLong();
                long A = in.nextLong();
                tot += A;
                System.out.println("W");
                System.out.flush();
                long r = in.nextLong();
                long B = in.nextLong();
                deg[(int)r] = B;
            }
            tot = tot / 4000;
            double res = 0.0;
            for(int i = 1; i <= (int)n; ++i){
                if(deg[i] == 0L){
                    res += tot;
                }
                else{
                    res += deg[i];
                }
            }
            long EE = (long)(res / 2 + 0.5);
            System.out.println("E " + EE);
            System.out.flush();
        }
    }
}