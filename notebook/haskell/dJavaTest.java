import java.util.*;
import java.io.*;

public class dJavaTest {
    // Functions
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Set<Integer> treeee = new TreeSet<Integer>();
        boolean results[] = new boolean[2 * n];
        for (int i = 0 ; i < n ; i++) {
            treeee.add(i);
        }
        for (int i = 0 ; i < 2 * n ; i++) {
            results[i] = treeee.contains(i);
        }
        System.out.println(Arrays.toString(results));
    }
}
