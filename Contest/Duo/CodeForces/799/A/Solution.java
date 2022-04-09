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
            int n = in.nextInt(), ct = 0;
            in.nextLine();
            char[] s = in.nextLine().toCharArray();
            for(int i = 0; i < s.length; ++i){
                if(i < s.length - 1 && s[i] == '0' && s[i + 1] == '0'){
                    ct += 2;
                }
                else if(i < s.length - 2 && s[i] == '0' && s[i + 1] == '1' && s[i + 2] == '0'){
                    ++ct;
                }
            }
            System.out.println(ct);
        }
    }
}