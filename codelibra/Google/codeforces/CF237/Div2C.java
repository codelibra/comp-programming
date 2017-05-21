package CF237;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Div2C {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }
}

class Pair<A, B> implements Comparable<Pair<Integer, Integer>> {
    private A first;
    private B second;

    public Pair(A first, B second) {
        super();
        this.first = first;
        this.second = second;
    }

    @Override
    public int hashCode() {
        int hashFirst = first != null ? first.hashCode() : 0;
        int hashSecond = second != null ? second.hashCode() : 0;

        return (hashFirst + hashSecond) * hashSecond + hashFirst;
    }

    @Override
    public boolean equals(Object other) {
        if (other instanceof Pair) {
            Pair<?, ?> otherPair = (Pair<?, ?>) other;
            return ((this.first == otherPair.first || (this.first != null && otherPair.first != null && this.first
                    .equals(otherPair.first))) && (this.second == otherPair.second || (this.second != null
                    && otherPair.second != null && this.second.equals(otherPair.second))));
        }

        return false;
    }

    @Override
    public String toString() {
        return "(" + first + ", " + second + ")";
    }

    public A getFirst() {
        return first;
    }

    public void setFirst(A first) {
        this.first = first;
    }

    public B getSecond() {
        return second;
    }

    public void setSecond(B second) {
        this.second = second;
    }

    @Override
    public int compareTo(Pair<Integer, Integer> o) {
        if (o.first < (Integer) this.first)
            return 1;
        else
            return -1;
    }
}

class Task {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n, k;
        n = in.nextInt();
        k = in.nextInt();
        @SuppressWarnings("unchecked")
        Pair<Integer, Integer> dist[] = new Pair[n];
        @SuppressWarnings("unchecked")
        Pair<Integer, Integer> ans[] = new Pair[n];
        int count[] = new int[n];
        int maxDistance = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            dist[i] = new Pair<Integer, Integer>(in.nextInt(), i + 1);
            maxDistance = Math.max(maxDistance, dist[i].getFirst());
        }

        Arrays.sort(dist);
        for (int i = 0; i < dist.length; i++) {
            count[dist[i].getFirst()] = count[dist[i].getFirst()] + 1;
        }

        int connections = k;
        for (int i = 1; i < maxDistance; ++i) {
            if (count[i] > connections || count[i] == 0) {
                System.out.println("-1");
                System.exit(0);
            }
            connections = count[i] * (k - 1);
        }
        if (count[0] != 1) {
            System.out.println("-1");
            System.exit(0);
        }

        int i = 0, j = 0, nextindex, temp = k, m = 0;
        while (j < dist.length && dist[j].getFirst() == 0)
            ++j;

        nextindex = j;

        while (j < dist.length) {
            while (j < dist.length && temp > 0 && dist[j].getFirst() == dist[i].getFirst() + 1) {
                ans[m] = new Pair<Integer, Integer>(dist[i].getSecond(), dist[j].getSecond());
                ++j;
                --temp;
                ++m;
            }
            if (j >= dist.length)
                break;
            if (dist[j].getFirst() > dist[i].getFirst() + 1) {
                i = nextindex;
                nextindex = j;
            } else {
                i = i + 1;
            }
            temp = k - 1;
        }

        System.out.println(ans.length - 1);
        for (int l = 0; l < ans.length - 1; l++) {
            System.out.println(ans[l].getFirst() + " " + ans[l].getSecond());
        }
    }
}

class InputReader {
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

}
