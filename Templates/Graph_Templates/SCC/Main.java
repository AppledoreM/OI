import java.util.*;
import java.io.*;
import java.lang.Math;

public class Main {
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
        int a;
        int b;
        int c;
        public Pair(int a, int b, int c){
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }
    public static int[] dir = {0,1,0,-1,0};
    public static int[] dfn, low;
    public static List<List<Integer>> scc;
    public static int time;
    public static HashSet<Integer>[] map;
    public static Stack<Integer> stack;
    public static boolean[] stkItem;
    public static void tarjan(int cur){
        //System.out.println(cur);
        ++time;
        dfn[cur] = time;
        low[cur] = time;
        stack.add(cur);
        stkItem[cur] = true;
        //System.out.println(cur + " " + stack);
        for(int ne : map[cur]){
            if(dfn[ne] == Integer.MAX_VALUE / 2){
                tarjan(ne);
                low[cur] = Math.min(low[ne], low[cur]);
            }
            else if(stkItem[ne]){
                //TODO: check
                low[cur] = Math.min(low[cur], dfn[ne]);
            }
        }
        int t = 0;
        //System.out.println(cur + " " + stack);
        if(low[cur] == dfn[cur]){
            List<Integer> l = new ArrayList<>();
            while(stack.get(stack.size() - 1) != cur){
                t = stack.get(stack.size() - 1);
                stkItem[t] = false;
                l.add(t);
                stack.pop();
            }
            stack.pop();
            l.add(cur);
            scc.add(l);
            stkItem[cur] = false;
        }
    }
    public static void main(String[] args){
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = in.nextInt(), m = in.nextInt();
        map = new HashSet[n + 1];
        for(int i = 1; i <= n; ++i){
            map[i] = new HashSet<>();
        }
        for(int i = 0; i < m; ++i){
            map[in.nextInt()].add(in.nextInt());
        }
        stack = new Stack<>();
        scc = new ArrayList<>();
        dfn = new int[n + 1];
        low = new int[n + 1];
        stkItem = new boolean[n + 1];
        Arrays.fill(dfn, Integer.MAX_VALUE / 2);
        Arrays.fill(low, Integer.MAX_VALUE / 2);
        time = 0;
        for(int i = 1; i <= n; ++i){
            if(dfn[i] == Integer.MAX_VALUE / 2){
                tarjan(i);
            }
        }
    }
}