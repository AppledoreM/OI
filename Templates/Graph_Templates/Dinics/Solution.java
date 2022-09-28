// Based on https://github.com/williamfiset/Algorithms/tree/master/src/main/java/com/williamfiset/algorithms/graphtheory/networkflow/examples
// Understood and optimized / shortened for Competitive Programming
import java.util.*;
import java.io.*;
import java.lang.Math;

public class Solution {
  private static long MOD = 1000000007L;
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

  private static class Edge{
  	public int from, to;
  	public long flow, capacity;
  	public Edge residual;

  	public Edge(int from, int to, long capacity){
  		this.from = from;
  		this.to = to;
  		this.capacity = capacity;
  	}

  	public void augment(long bottle){
  		flow += bottle;
  		residual.flow -= bottle;
  	}
  }

  private static class Dinics{
  	static final long INF = Long.MAX_VALUE / 2;
  	int n, s, t;
  	public long maxFlow;
  	public List<Edge>[] graph;
  	private int[] level, next;

  	public Dinics(int n, int s, int t){
  		this.n = n;
  		this.s = s;
  		this.t = t;
  		level = new int[n];
  		next = new int[n];
  		graph = new ArrayList[n];
  		for(int i = 0; i < n; ++i){
  			graph[i] = new ArrayList<Edge>();
  		}
  	}

  	public void addEdge(int from, int to, long capacity){
  		Edge e = new Edge(from, to, capacity);
  		Edge er = new Edge(to, from, 0);
  		e.residual = er;
  		er.residual = e;
  		graph[from].add(e);
  		graph[to].add(er);
  	}

  	private boolean bfs(){
  		Arrays.fill(level, -1);
  		Queue<Integer> q = new LinkedList<>();
  		q.add(s);
  		level[s] = 0;
  		while(!q.isEmpty()){
  			int cur = q.poll();
  			for(Edge e : graph[cur]){
  				long space = e.capacity - e.flow;
  				if(space > 0 && level[e.to] == -1){
  					level[e.to] = level[cur] + 1;
  					q.add(e.to);
  				}
  			}
  		}
  		return level[t] != -1;
  	}

  	private long dfs(int cur, long flow){
  		if(cur == t)
  			return flow;
  		int ns = graph[cur].size();
  		while(next[cur] < ns){
  			Edge e = graph[cur].get(next[cur]);
  			long space = e.capacity - e.flow;
  			if(space > 0 && level[e.to] == level[cur] + 1){
  				long bottle = dfs(e.to, Math.min(flow, space));
  				if(bottle > 0){
  					e.augment(bottle);
  					return bottle;
  				}
  			}
  			++next[cur];
  		}
  		return 0;
  	}

  	public void solve(){
  		while(bfs()){
  			Arrays.fill(next, 0);
  			long f = dfs(s, INF);
  			while(f != 0){
  				maxFlow += f;
  				f = dfs(s, INF);
  			}
  		}
  	}
  }
  public String tricoloring(int[] A){
    int n = A.length;
    int[] val = new int[3];
    String[] colors = {"R","G","B"};
    for(int i = 0; i < (int)Math.pow(3, n); ++i){
      int tmp = i;
      for(int j = 0; j < n; ++j){
        val[tmp % 3] += A[j];
        tmp /= 3;
      }
      if(val[0] == val[1] && val[1] == val[2] && val[0] == val[2]){
        tmp = i;
        String S = "";
        for(int j = 0; j < n; ++j){
          S += colors[tmp % 3];
          tmp /= 3;
        }
        return S;
      }
      Arrays.fill(val, 0);
    }
    return "None";
  }
  public static void main(String[] args){
  	Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
  }
}