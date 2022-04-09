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
        //in.nextLine();
        loop: for(int _m = 0; _m < tt; ++_m){
            int n = in.nextInt(), ct = 0;
            long st = 1L, sum = 0L;
            List<Long> l = new ArrayList<>();
            long[] arr = new long[40];
            while(st <= 1000000000L){
                l.add(st);
                sum += st;
                arr[ct] = st;
                ++ct;
                st *= 2;
            }
            HashSet<Long> set = new HashSet<>();
            st = 1000000000L;
            while(ct < n){
                l.add(st);
                sum += st;
                set.add(st);
                --st;
                ++ct;
            }
            StringBuilder sb = new StringBuilder();
            for(long ele : l){
                sb.append(ele);
                sb.append(" ");
            }
            System.out.println(sb.toString());
            System.out.flush();
            for(int i = 0; i < n; ++i){
                long a = in.nextLong();
                sum += a;
                set.add(a);
            }
            sum /= 2;
            //for(long ele : set){
            //    System.out.println(ele);
            //}
            //System.out.println(sum);
            sb = new StringBuilder();
            for(long ele : set){
                if(sum > 1000000000L){
                    sum -= ele;
                    sb.append(ele);
                    sb.append(" ");
                }
            }
            int ind = 0;
            while(sum > 0){
                if((sum & arr[ind]) > 0){
                    sb.append(arr[ind]);
                    sb.append(" ");
                    sum -= arr[ind];
                }
                ++ind;
            }
            System.out.println(sb.toString());
            System.out.flush();
        }
    }
}