import java.util.*;
import java.io.*;

public class TaskC {
    public static InputReader in;
    public static PrintWriter out;
    static int[][] G;
    static int[] color;
    public static void main(String[] args) {
        in = new InputReader(System.in);
        out = new PrintWriter(System.out);
        int n = in.nextInt();
        int[] a = new int[n - 1];
        int[] b = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            a[i] = u;
            b[i] = v;
        }
        G = buildGraph(n, a, b);
        color = new int[n];
        dfs(0, -1, 0);
        int sum1 = 0;
        for (int i = 0; i < n; i++) {
            sum1 += color[i];
        }
        int sum0 = n - sum1;
        if (sum0 > sum1) {
            int tmp = sum0;
            sum0 = sum1;
            sum1 = tmp;
            for (int i = 0; i < n; i++) {
                color[i] ^= 1;
            }
        }
        int numOfMultiple3 = n / 3;
        int[] p = new int[n];
        if (numOfMultiple3 >= sum0) {
            HashMap<Integer, Boolean> map = new HashMap<>();
            int ptr = 3;
            for (int i = 0; i < n; i++) {
                if (color[i] == 0) {
                    p[i] = ptr;
                    map.put(ptr, true);
                    ptr += 3;
                }
            }
            ptr = 1;
            for (int i = 0; i < n; i++) {
                if (p[i] == 0) {
                    p[i] = ptr++;
                    while (map.get(ptr) != null) ptr++;
                }
            }
        }  else {
            int ptr = 1;
            for (int i = 0; i < n; i++) {
                if (color[i] == 1) {
                    p[i] = ptr;
                    ptr += 3;
                    if (ptr > n) break;
                }
            }
            ptr = 2;
            for (int i = 0; i < n; i++) {
                if (color[i] == 0) {
                    p[i] = ptr;
                    ptr += 3;
                    if (ptr > n) break;
                }
            }
            ptr = 3;
            for (int i = 0; i < n; i++) {
                if (p[i] == 0) {
                    p[i] = ptr;
                    ptr += 3;
                }
            }
        }
        for (int x : p) {
            out.print(x + " ");
        }
        out.println();
        out.close();
    }
    static void dfs(int u, int f, int c) {
        color[u] = c;
        for (int v : G[u]) {
            if (v == f) continue;
            dfs(v, u, c ^ 1);
        }
    }
    static int[][] buildGraph(int n, int[] a, int[] b) {
        int[] cnt = new int[n];
        for (int i = 0; i < n - 1; i++) {
            cnt[a[i]] += 1;
            cnt[b[i]] += 1;
        }
        int[][] G = new int[n][];
        for (int i = 0; i < n; i++) {
            G[i] = new int[cnt[i]];
        }
        for (int i = 0; i < n - 1; i++) {
            G[a[i]][--cnt[a[i]]] = b[i];
            G[b[i]][--cnt[b[i]]] = a[i];
        }
        return G;
    }
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public Long nextLong() {
            return Long.parseLong(next());
        }
        public Double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}