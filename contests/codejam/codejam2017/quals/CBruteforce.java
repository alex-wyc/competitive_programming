import java.util.*;
import java.io.*;

public class CBruteforce {
    // Instance Variables
    static class Stall implements Comparable<Stall> {
        public int i, L, R;
        public boolean occupied;

        public Stall(int _i, int _l, int _r) {
            i = _i;
            L = _l;
            R = _r;
            occupied = false;
        }
        
        public int compareTo(Stall o) {
            if (occupied) {
                return -1;
            }
            if (o.occupied) {
                return 1;
            }
            if (Math.min(L, R) > Math.min(o.L, o.R)) {
                return 1;
            }
            else if (Math.min(L, R) < Math.min(o.L, o.R)) {
                return -1;
            }
            else { // tie
                if (Math.max(L, R) > Math.max(o.L, o.R)) {
                    return 1;
                }
                else if (Math.max(L, R) < Math.max(o.L, o.R)) {
                    return -1;
                }
                else { // tie again
                    return o.i - i;
                }
            }
        }
    }

    static class TestCase {
        int N; // number of stalls
        Stall[] stalls;

        public TestCase(int n) {
            N = n;
            stalls = new Stall[N];
            for (int i = 0 ; i < N ; i++) {
                stalls[i] = new Stall(i, i, (N - 1 - i));
            }
        }

        public int bestStall() {
            int bestIndex = 0;
            for (int i = 1 ; i < N ; i++) {
                if (stalls[i].compareTo(stalls[bestIndex]) > 0) {
                    bestIndex = i;
                }
            }
            return bestIndex;
        }

        public int[] solve(int K) {
            for (int i = 0 ; i < K - 1 ; i++) {
                int bIndex = this.bestStall();
                stalls[bIndex].occupied = true;
                int j = 0;

                while (bIndex - j - 1 >= 0 && !stalls[bIndex - j - 1].occupied) {
                    stalls[bIndex - j - 1].R = j;
                    j++;
                }

                j = 0;

                while (bIndex + j + 1 < N && !stalls[bIndex + j + 1].occupied) {
                    stalls[bIndex + j + 1].L = j;
                    j++;
                }
            }

            int rIndex = this.bestStall();
            int max = Math.max(stalls[rIndex].L, stalls[rIndex].R);
            int min = Math.min(stalls[rIndex].L, stalls[rIndex].R);
            return new int[]{max, min};
        }
    }

    // Functions
    
    public static void main(String[] args) {
        Scanner sin = new Scanner(System.in);
        int T = sin.nextInt();

        for (int i = 0 ; i < T ; i++) {
            TestCase t = new TestCase(sin.nextInt());
            int[] solution = t.solve(sin.nextInt());
            System.out.println("Case #" + (i + 1) + ": " + solution[0] + " " + solution[1]);
        }
    }
}
