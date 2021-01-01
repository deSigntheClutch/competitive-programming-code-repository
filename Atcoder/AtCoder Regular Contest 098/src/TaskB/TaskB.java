package TaskB;

import java.util.*;
import java.io.*;

public class TaskB {
    public static InputReader in;
    public static PrintWriter out;
    public static void main(String[] args) {
        in = new InputReader(System.in);
        out = new PrintWriter(System.out);
        int n = in.nextInt();
        int[] a = new int[n];
        int[] sum = new int[n];
        int[][] bitsum = new int[n][22];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            sum[i] = a[i];
            for (int j = 0; j < 21; j++) {
                int bit = ((a[i] >> j) & 1);
                bitsum[i][j] = bit;
            }
            if (i > 0) {
                sum[i] += sum[i - 1];
                for (int j = 0; j < 21; j++) {
                    bitsum[i][j] += bitsum[i - 1][j];
                }
            }
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans += 1;
                continue;
            }
            int l = -1, r = i, md;
            while (l < r) {
                md = (l + r) >> 1;
                int[] val = new int[22];
                for (int j = 0; j < 21; j++) {
                    val[j] = bitsum[i][j];
                }
                if (md >= 0) {
                    for (int j = 0; j < 21; j++) {
                        val[j] -= bitsum[md][j];
                    }
                }
                boolean flag = true;
                for (int j = 0; j < 21; j++) {
                    if (val[j] > 1) flag = false;
                }
                if (flag == false) l = md + 1;
                else r = md;
            }
            ans += (i - l);
        }
        out.println(ans);
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

