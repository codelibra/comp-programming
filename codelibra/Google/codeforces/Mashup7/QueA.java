package Mashup7;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class QueA {
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

class Pair<A, B> implements Comparable<Pair> {
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
            Pair otherPair = (Pair) other;
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
    public int compareTo(Pair o) {
        if ((Integer) o.first < (Integer) this.first)
            return 1;
        else
            return -1;
    }
}

class Task {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int N, M, K, p = 0;
        N = in.nextInt();
        M = in.nextInt();
        K = in.nextInt();
        Pair<Integer, Integer> array[] = new Pair[M];
        Pair<Integer, Integer> ansPair[] = new Pair[M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < array.length; j++) {
                array[j] = new Pair(in.nextInt(), j);
            }
        }
        int ans = (M * (M - 1)) / 2;
        System.out.println(ans);
        for (int i = 1; i <= M; i++) {
            for (int j = i + 1; j <= array.length; j++) {
                if (K == 0)
                    System.out.println(i + " " + j);
                else {
                    System.out.println(j + " " + i);
                }
            }
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

/**
 * i reached the conclusion that m m-1/2 is the maximum number of swaps that can
 * be performed but even then i did not do the simplest thing to swap all of
 * them. all the pairs can be swapped. so the simple take away is that if we can
 * swap all the elements, or the ways asked is actually equal to the maximum
 * which is possible then we can go for printing all the possible ways for
 * performing the solution. This was a very easy question and i cud have done
 * it. I cud have jumped to the conclusion that, m m-1/2 is the maximum possible
 * then why worry about all the logic, just swap everything and get it done!!!
 */
