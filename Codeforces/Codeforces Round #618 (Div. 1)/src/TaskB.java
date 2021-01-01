import java.util.*;
import java.io.*;


public class TaskB {
    public static InputReader in;
    public static PrintWriter out;

    public static void main(String[] args) {
        in = new InputReader(System.in);
        out = new PrintWriter(System.out);
        int n = in.nextInt();
        long[] a = new long[n];
        long[] b = new long[n];
        long Gx = 0, Gy = 0;
        HashMap<Point, Boolean> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            a[i] = in.nextLong();
            a[i] *= 2 * n;
            Gx += a[i];
            b[i] = in.nextLong();
            b[i] *= 2 * n;
            Gy += b[i];
            Point p = new Point(a[i], b[i]);
            mp.put(p, true);
        }
        Gx /= n;
        Gy /= n;
        boolean flag = true;
        for (int i = 0; i < n; i++) {
            Point opposite = new Point(2 * Gx - a[i], 2 * Gy - b[i]);
            //out.println(opposite.toString());
            if (!mp.containsKey(opposite)) {
                //out.println("dsa");
                flag = false;
            }
        }
        if (flag) out.println("YES");
        else out.println("NO");
        out.close();
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

class Point implements Comparable<Point>{
    final int MOD = 1000000000 + 7;

    long x;
    long y;

    Point(long a, long b) {
        this.x = a;
        this.y = b;
    }

    @Override
    public int compareTo(Point o) {
        if (o.x == this.x) return (int)((this.y - o.y) % 2);
        else return (int)((this.x - o.x) % 2);
    }

    @Override
    public int hashCode() {
        return (int)(this.x * 29 % MOD + this.y * 29*29 % MOD) % MOD;
    }

    @Override
    public String toString() {
        return String.valueOf(x) + ", " + String.valueOf(y);
    }

    @Override
    public boolean equals(Object obj) {
        if (obj.getClass() != this.getClass())
            return false;
        Point o = (Point)obj;
        long xx = o.x;
        if (xx != this.x) return false;
        long yy = o.y;
        if (yy != this.y) return false;
        return true;
    }
}

