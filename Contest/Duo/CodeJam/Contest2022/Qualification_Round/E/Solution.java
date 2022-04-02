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
        Random rand = new Random(1L);
        loop: for(int _m = 0; _m < tt; ++_m){
            long n = in.nextLong(), k = in.nextLong(), cur = in.nextLong(), p = in.nextLong();
            long tot = 0;
            int ls = (int)n, i = 0;
            if(ls <= k){
                for(; i < ls; ++i){
                    System.out.println("T " + (i + 1));
                    System.out.flush();
                    in.nextLong();
                    long wh = in.nextLong();
                    tot += wh;
                }
            }
            else{
                HashSet<Integer> visited = new HashSet<>();
                if(ls <= 16000){
                    for(i = 0; i < ls - k; ++i){
                        while(true){
                            int r = rand.nextInt(ls);
                            if(!visited.contains(r)){
                                visited.add(r);
                                break;
                            }
                        }

                    }
                    for(i = 1; i <= ls; ++i){
                        if(!visited.contains(i)){
                            System.out.println("T " + (i + 1));
                            System.out.flush();
                            in.nextLong();
                            long wh = in.nextLong();
                            tot += wh;

                        }
                    }
                }
                else{
                    for(i = 0; i < 8000; ++i){
                        while(true){
                            int r = rand.nextInt(ls);
                            if(!visited.contains(r)){
                                visited.add(r);
                                break;
                            }
                        }
                    }
                    for(int ele : visited){
                        System.out.println("T " + (ele + 1));
                        System.out.flush();
                        in.nextLong();
                        long wh = in.nextLong();
                        tot += wh;
                    }
                }
                i = 8000;
            }
            System.out.println("E " + (tot * n / i) / 2);
            System.out.flush();
        }
    }
}