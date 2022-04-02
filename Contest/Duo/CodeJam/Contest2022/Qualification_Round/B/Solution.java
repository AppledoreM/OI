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
            int[][] arr = new int[3][4];
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 4; ++j){
                    arr[i][j] = in.nextInt();
                }
            }
            for(int j = 0; j < 4; ++j){
                arr[0][j] = Math.min(arr[0][j], Math.min(arr[1][j], arr[2][j]));
            }
            int sum = 0;
            for(int j = 0; j < 4; ++j){
                sum += arr[0][j];
            }
            if(sum < 1000000){
                System.out.println("IMPOSSIBLE");
            }
            else{
                sum = 0;
                for(int j = 0; j < 4; ++j){
                    int amount = Math.min(1000000 - sum, arr[0][j]);
                    System.out.print(amount + " ");
                    sum += amount;
                }
                System.out.println();
            }
        }
    }
}