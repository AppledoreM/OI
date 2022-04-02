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
    public static void main(String[] args){
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int tt = in.nextInt();
        in.nextLine();
        loop: for(int _m = 0; _m < tt; ++_m){
            System.out.print("Case #" + (_m + 1) + ": ");
            int n = in.nextInt();
            int[] arr = new int[n];
            for(int i = 0; i < n; ++i){
                arr[i] = in.nextInt();
            }
            Arrays.sort(arr);
            int ct = 0, cur = 1;
            for(int i = 0; i < n; ++i){
                if(arr[i] < cur){
                    continue;
                }
                ++ct;
                ++cur;
            }
            System.out.println(ct);
        }
    }
}