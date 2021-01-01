import java.util.*;
import java.io.*;

public class E {
    static InputReader in;
    static PrintWriter out;

    public static void main(String[] args) {
        in = new InputReader(System.in);
        out = new PrintWriter(System.out);
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n + 1];
        int[] u = new int[m + 1];
        int[] v = new int[m + 1];
        int[] id = new int[m + 1];

        for (int i = 1; i <= n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < m; i++) {
            u[i] = in.nextInt();
            v[i] = in.nextInt();
            id[i] = i;
        }
        int[][][] g = make_graph(u, v, id, n, m);


    }

    static int[][][] make_graph(int[] u, int[] v, int[] id, int n, int m) {
        int[][][] g = new int[n + 1][][];
        int[] deg = new int[n + 1];
        for (int i = 1; i <= m; i++) {
            deg[u[i]] += 1;
            deg[v[i]] += 1;
        }
        for (int i = 1; i <= n; i++) {
            g[i] = new int[deg[i]][2];
        }
        for (int i = 1; i <= m; i++) {
            g[u[i]][deg[u[i] - 1]][0] = v[i];
            g[u[i]][deg[u[i] - 1]][1] = id[i];
            deg[u[i]] -= 1;
            g[v[i]][deg[v[i] - 1]][0] = u[i];
            g[v[i]][deg[v[i] - 1]][1] = id[i];
            deg[v[i]] -= 1;
        }
        return g;
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
