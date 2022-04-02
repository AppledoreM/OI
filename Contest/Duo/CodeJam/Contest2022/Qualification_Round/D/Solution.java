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
        in.nextLine();
        loop: for(int _m = 0; _m < tt; ++_m){
            System.out.print("Case #" + (_m + 1) + ": ");
            int n = in.nextInt();
            arr = new long[n + 1];
            map = new HashMap<>();
            map.put(0, new HashSet<>());
            for(int i = 0; i < n; ++i){
                arr[i + 1] = in.nextLong();
                map.put(i + 1, new HashSet<>());
            }
            for(int i = 0; i < n; ++i){
                map.get(in.nextInt()).add(i + 1);
            }
            long[] res = dfs(0);
            System.out.println(res[0]);
        }
    }
}
            