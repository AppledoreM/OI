import java.util.*;
import java.io.*;
import java.lang.Math;
public class Dinics {
  static long MOD = 1000000007L;
  public static void print(long[] lwler){
  	for(int i=0;i<lwler.length;++i){
  			System.out.print(lwler[i]+" ");
  		}
  		System.out.println();
  }
  public static void print(int[] lwler){
  	for(int i=0;i<lwler.length;++i){
  			System.out.print(lwler[i]+" ");
  		}
  		System.out.println();
  }

  private static class Edge{
    public int from, to;
    public Edge residual;
    public long flow;
    public final long capacity;

    public Edge(int from, int to, long capacity){
      this.from = from;
      this.to = to;
      this.capacity = capacity;
    }

    public boolean isResidual(){
      return capacity == 0;
    }

    public long remainingCapacity(){
      return capacity - flow;
    }

    public void augment(long bottleNeck){
      flow += bottleNeck;
      residual.flow -= bottleNeck;
    }

    public String toString(int s, int t){
      String u = (from == s) ? "s" : ((from == t) ? "t" : String.valueOf(from));
      String v = (to == s) ? "s" : ((to == t) ? "t" : String.valueOf(to));
      return String.format(
        "Edge %s -> %s | flow = %3d | capacity = %3d | is residual: %s",
        u, v, flow, capacity, isResidual());
    }
  }

  private abstract static class NetworkFlowSolverBase{
    static final long INF = Long.MAX_VALUE / 2;
    final int n, s, t;
    protected boolean solved;
    protected long maxFlow;
    protected List<Edge>[] graph;

    public NetworkFlowSolverBase(int n, int s, int t){
      this.n = n;
      this.s = s;
      this.t = t;
      initializeEmptyFlowGraph();
    }

    @SuppressWarnings("unchecked")
    private void initializeEmptyFlowGraph(){
      graph = new List[n];
      for(int i = 0; i < n; ++i){
        graph[i] = new ArrayList<Edge>();
      }
    }

    public void addEdge(int from, int to, long capacity){
      Edge e1 = new Edge(from, to, capacity);
      Edge e2 = new Edge(to, from, 0);
      e1.residual = e2;
      e2.residual = e1;
      graph[from].add(e1);
      graph[to].add(e2);
    }

    public List<Edge>[] getGraph(){
      execute();
      return graph;
    }

    public long getMaxFlow(){
      execute();
      return maxFlow;
    }

    private void execute(){
      if(solved) return;
      solved = true;
      solve();
    }

    public abstract void solve();
  }

  private static class DinicsSolver extends NetworkFlowSolverBase{
    private int[] level;

    public DinicsSolver(int n, int s, int t){
      super(n, s, t);
      level = new int[n];
    }

    @Override
    public void solve(){
      int[] next = new int[n];

      while(bfs()){
        Arrays.fill(next, 0);
        for(long f = dfs(s, next, INF); f != 0; f = dfs(s, next, INF)){
          maxFlow += f;
        }
      }
    }

    private boolean bfs(){
      Arrays.fill(level, -1);
      Deque<Integer> q = new ArrayDeque<>(n);
      q.offer(s);
      level[s] = 0;
      while(!q.isEmpty()){
        int node = q.poll();
        for(Edge edge : graph[node]){
          long cap = edge.remainingCapacity();
          if(cap > 0 && level[edge.to] == -1){
            level[edge.to] = level[node] + 1;
            q.offer(edge.to);
          }
        }
      }

      return level[t] != -1;
    }

    private long dfs(int at, int[] next, long flow){
      if(at == t)
        return flow;
      final int numEdges = graph[at].size();
      for(; next[at] < numEdges; next[at]++){
        Edge edge = graph[at].get(next[at]);
        long cap = edge.remainingCapacity();
        if(cap > 0 && level[edge.to] == level[at] + 1){
          long bottleNeck = dfs(edge.to, next, Math.min(flow, cap));
          if(bottleNeck > 0){
            edge.augment(bottleNeck);
            return bottleNeck;
          }
        }
      }
      return 0;
    }
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    int n = in.nextInt(), m = in.nextInt();
    in.nextLine();
    HashMap<String, List<Integer>> map = new HashMap<>();
    for(int i = 0; i < n; ++i){
      String[] toks = in.nextLine().split(" ");
      if(Integer.parseInt(toks[1]) == 0){
        continue;
      }
      for(int j = 2; j < toks.length; ++j){
        map.put(toks[j], new ArrayList<>());
        map.get(toks[j]).add(i);
      }
    }
    for(int i = 0; i < m; ++i){
      String[] toks = in.nextLine().split(" ");
      if(Integer.parseInt(toks[1]) == 0){
        continue;
      }
      for(int j = 2; j < toks.length; ++j){
        map.get(toks[j]).add(i + n);
      }
    }
    NetworkFlowSolverBase solver = new DinicsSolver(m + n + 2, m + n, m + n + 1);
    for(int i = 0; i < n; ++i){
      solver.addEdge(m + n, i, 1);
    }
    for(int i = n; i < m + n; ++i){
      solver.addEdge(i, m + n + 1, 1);
    }
    for(String key : map.keySet()){
      List<Integer> l = map.get(key);
      solver.addEdge(l.get(0), l.get(1), 1);
    }
    System.out.println(solver.getMaxFlow());
  }
}