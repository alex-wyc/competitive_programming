import java.util.*;
import java.io.*;

public class CSmart {
    // Instance Variables
    
    public long max, min;

    // Constructors
    public CSmart(long n, long k) {
        PriorityQueue<Long> queue = new PriorityQueue<Long>(10, Collections.reverseOrder());
        queue.offer(n);

        for (long i = 0 ; i < k - 1 ; i++) {
            long a = queue.poll();

            if (a % 2 == 1) {
                queue.offer(a / 2);
                queue.offer(a / 2);
            }
            else {
                queue.offer(a / 2);
                queue.offer(a / 2 - 1);
            }
        }

        long a = queue.poll();

        if (a % 2 == 1) {
            max = min = a / 2;
        }
        else {
            max = a / 2;
            min = a / 2 - 1;
        }
    }

    // Functions
    public static void main(String[] args) {
        Scanner sin = new Scanner(System.in);
        long T = sin.nextLong();

        for (long i = 0 ; i < T ; i++) {
            CSmart s = new CSmart(sin.nextLong(), sin.nextLong());
            System.out.println("Case #" + (i + 1) + ": " + s.max + " " + s.min);
        }

    }
}
