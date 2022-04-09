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
    public static void print(char[] aa){
        System.out.print("[");
        for(int i = 0; i < aa.length; ++i)
            System.out.print(aa[i] + ",");
        System.out.print("]");
    }
    public static class Pair{
        char[] a;
        int b;
        public Pair(char[] a, int b){
            this.a = a;
            this.b = b;
        }
    }
    public static HashSet<Pair> ne, set;
    public static int[] arr;
    public static int E, W;
    public static void gen(int ind, int len, String cur){
        if(ind == len){
            char[] s = cur.toCharArray();
            int min = 1000000007;
            for(Pair p : set){
                char[] prev = p.a;
                int i = 0;
                for(; i < Math.min(prev.length, s.length); ++i){
                    if(prev[i] != s[i]){
                        break;
                    }
                }
                int cost = p.b + (prev.length + s.length - i * 2);
                min = Math.min(min, cost);
            }
            ne.add(new Pair(s, min));
            return;
        }
        for(int i = 0; i < W; ++i){
            if(arr[i] > 0){
                --arr[i];
                String aaa = "";
                aaa += cur;
                aaa += i;
                gen(ind + 1, len, aaa);
                ++arr[i];
            }
        }
    }
    public static void main(String[] args){
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int tt = in.nextInt();
        in.nextLine();
        loop: for(int _m = 0; _m < tt; ++_m){
            System.out.print("Case #" + (_m + 1) + ": ");
            E = in.nextInt();
            W = in.nextInt();
            set = new HashSet<>();
            ne = new HashSet<>();
            arr = new int[W];
            char[] emp = new char[0];
            set.add(new Pair(emp, 0));
            for(int i = 0; i < E; ++i){
                int sum = 0;
                for(int j = 0; j < W; ++j){
                    arr[j] = in.nextInt();
                    sum += arr[j];
                }
                gen(0, sum, "");
                /*for(Pair ele : ne){
                    print(ele.a);
                    System.out.println(ele.b);
                }*/
                set = new HashSet<>();
                for(Pair ele : ne){
                    set.add(ele);
                }
                ne = new HashSet<>();
            }
            int min = 1000000000;
            for(Pair p : set){
                min = Math.min(min, p.b + p.a.length);
            }
            System.out.println(min);
        }
    }
}