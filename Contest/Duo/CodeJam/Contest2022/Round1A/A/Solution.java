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
        char a;
        int b;
        public Pair(char a, int b){
            this.a = a;
            this.b = b;
        }
    }
    public static void main(String[] args){
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int tt = in.nextInt();
        in.nextLine();
        loop: for(int _m = 0; _m < tt; ++_m){
            System.out.print("Case #" + (_m + 1) + ": ");
            Stack<Pair> l = new Stack<>();
            int ct = 0;
            char cur = '#';
            char[] s = in.nextLine().toCharArray();
            for(char c : s){
                if(c != cur){
                    if(!l.isEmpty()){
                        Pair p = l.get(l.size() - 1);
                        if(cur < p.a){
                            p.b /= 2;
                        }
                    }
                    l.add(new Pair(cur, ct));
                    ct = 2;
                    cur = c;
                }
                else{
                    ct += 2;
                }
            }
            if(!l.isEmpty()){
                Pair p = l.get(l.size() - 1);
                if(cur < p.a){
                    p.b /= 2;
                }
            }
            l.add(new Pair(cur, ct / 2));
            StringBuilder sb = new StringBuilder();
            for(Pair p : l){
                for(int i = 0; i < p.b; ++i){
                    sb.append(p.a);
                }
            }
            System.out.println(sb.toString());
        }
    }
}