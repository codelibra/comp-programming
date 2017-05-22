package Mashup12;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class QueB {
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

class Task {
    public void solve(int testNumber, InputReader in, PrintWriter out) {

        int N = in.nextInt(), sum = 0;
        int arr[] = new int[N];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = in.nextInt();
            sum = sum + arr[i];
        }
        sum = sum / N;

        Arrays.sort(arr);
        int i = 0, j = N - 1;
        while (i < j) {

            while (j >= 0 && arr[j] == sum)
                --j;
            int diff = arr[j] - sum;
            arr[j] = sum;

            while (i < N && arr[i] == sum)
                ++i;
            while (diff > 0) {
                if (sum - arr[i] >= 0)
                    diff = diff - (sum - arr[i]);
                ++i;
            }
        }

        int ans = 0;
        for (int j2 = 0; j2 < arr.length; j2++) {
            if (arr[j2] == sum)
                ans++;
        }
        out.print(ans);
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
