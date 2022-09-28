//Based on https://leetcode.cn/problems/s5kipK/solution/by-tsreaper-z8by/
//Understood, translated to Java, and improved for scenarios with multiple connected components
import java.util.*;
import java.io.*;
import java.lang.Math;

public class Solution {
  private static long MOD = 1000000007L;
  private static int INF = Integer.MAX_VALUE / 2;
  private static void print(long[] lwler){
    for(int i=0;i<lwler.length;++i){
      System.out.print(lwler[i]+" ");
    }
    System.out.println();
  }
  private static void print(int[] lwler){
    for(int i=0;i<lwler.length;++i){
      System.out.print(lwler[i]+" ");
    }
    System.out.println();
  }

  public static Stack<Integer> stack;
  public static List<List<Integer>> dcc;
  public static List<List<Integer>> edges;
  public static int[] dfn, low;
  public static boolean[] cut;
  public static int n, st, time;

  public static void tarjan(int cur){
    dfn[cur] = ++time;
    low[cur] = time;
    int flag = 0;
    stack.add(cur);
    for(int ne : edges.get(cur)){
      if(dfn[ne] == Integer.MAX_VALUE / 2){
        tarjan(ne);
        low[cur] = Math.min(low[cur], low[ne]);
        if(dfn[cur] <= low[ne]){
          ++flag;
          int t;
          if(cur != st || flag > 1){
            cut[cur] = true;
          }
          dcc.add(new ArrayList<>());
          do{
            t = stack.get(stack.size() - 1);
            stack.pop();
            dcc.get(dcc.size() - 1).add(t);
          } while(t != ne);
          dcc.get(dcc.size() - 1).add(cur);
        }
      }
      else{
        low[cur] = Math.min(low[cur], dfn[ne]);
      }
    }
  }
  public static long minimumCost(int[] cost, int[][] roads) {
    n = cost.length;
    if(n == 1){
      return cost[0];
    }
    stack = new Stack<>();
    dcc = new ArrayList<>();
    edges = new ArrayList<>();
    st = 0;
    time = 0;
    for(int i = 0; i < n; ++i){
      edges.add(new ArrayList<>());
    }
    for(int[] r : roads){
      edges.get(r[0]).add(r[1]);
      edges.get(r[1]).add(r[0]);
    }
    dfn = new int[n];
    low = new int[n];
    cut = new boolean[n];
    Arrays.fill(dfn, Integer.MAX_VALUE / 2);
    Arrays.fill(low, Integer.MAX_VALUE / 2);
    for(int i = 0; i < n; ++i){
      if(dfn[i] == Integer.MAX_VALUE / 2){
        st = i;
        tarjan(i);
      }
    }
    if(dcc.size() == 1){
      int res = Integer.MAX_VALUE;
      for(int ele : cost)
        res = Math.min(res, ele);
      return (long)res;
    }
    List<Integer> leaves = new ArrayList<>();
    for(List<Integer> l : dcc){
      int cut_cnt = 0, min = Integer.MAX_VALUE;
      for(int x : l){
        if(cut[x])
          ++cut_cnt;
        else
          min = Math.min(min, cost[x]);
      }
      if(cut_cnt == 1)
        leaves.add(min);
    }
    Collections.sort(leaves);
    long res = 0L;
    for(int i = 0; i < leaves.size() - 1; ++i){
      res += leaves.get(i);
    }
    return res;
  }

  public static void main(String[] args){
  	Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
  }
}