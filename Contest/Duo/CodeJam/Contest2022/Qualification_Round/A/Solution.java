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
            System.out.println();
            int r = in.nextInt(), c = in.nextInt();
            r = 2 * r + 1;
            c = 2 * c + 1;
            char[][] arr = new char[r][c];
            for(int i = 0; i < r; ++i){
                Arrays.fill(arr[i], '.');
            }
            for(int j = 2; j < c; ++j){
                arr[0][j] = (j % 2 == 0 ? '+' : '-');
                arr[1][j] = (j % 2 == 0 ? '|' : '.');
            }
            for(int i = 2; i < r; i += 2){
                for(int j = 0; j < c; ++j){
                    arr[i][j] = (j % 2 == 0 ? '+' : '-');
                    if(i + 1 < r)
                        arr[i + 1][j] = (j % 2 == 0 ? '|' : '.');
                }
            }
            for(int i = 0; i < r; ++i){
                for(int j = 0; j < c; ++j){
                    System.out.print(arr[i][j]);
                }
                System.out.println();
            }
        }
    }
}