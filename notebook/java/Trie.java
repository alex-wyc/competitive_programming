import java.util.*;
import java.io.*;

public class Trie {
    // Instance Variables
    int[] wordCount;
    int[] prefixCount;
    int[][] edges; // this set of edges only handles lower case relatively small tries
    // for more diverse cases consider using a map from (int, char) -> int
    int size;
    int maxSize;

    // Constructors
    public Trie(int _maxSize) {
        // note here maxSize is the total number of nodes, not just how many
        // strings can be stored in the trie
        size = 1; // root is ""
        maxSize = _maxSize;
        wordCount = new int[maxSize];
        prefixCount = new int[maxSize];
        edges = new int[26][maxSize];
        for (int i = 0 ; i < 26 ; i++) {
            for (int j = 0 ; j < maxSize ; j++) {
                edges[i][j] = -1;
            }
        }
    }

    int getIndex(char c) {
        return (c - 'a');
    }

    // Functions

    void insert(String s) {
        if (size == maxSize) {
            return;
        }

        int currentNode = 0; // start from empty
        for (char c : s.toCharArray()) {
            prefixCount[currentNode]++;

            if (edges[getIndex(c)][currentNode] == -1) {
                edges[getIndex(c)][currentNode] = size;
                size++;
            }

            currentNode = edges[getIndex(c)][currentNode];
        }

        wordCount[currentNode]++;
    }

    boolean contains(String s) {
        int currentNode = 0;

        for (char c : s.toCharArray()) {
            if (edges[getIndex(c)][currentNode] == -1) {
                return false;
            }

            currentNode = edges[getIndex(c)][currentNode];
        }

        return wordCount[currentNode] > 0;
    }

    int countPrefix(String p) {
        int currentNode = 0;

        for (char c : p.toCharArray()) {
            if (edges[getIndex(c)][currentNode] == -1) {
                return 0;
            }

            currentNode = edges[getIndex(c)][currentNode];
        }

        return prefixCount[currentNode];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        Trie test = new Trie(10000);

        for (int i = 0 ; i < N ; i++) {
            test.insert(br.readLine());
        }

        int M = Integer.parseInt(br.readLine());

        for (int i = 0 ; i < M ; i++) {
            if (test.contains(br.readLine())) {
                System.out.println("True");
            }
            else {
                System.out.println("False");
            }
        }
    }
}
