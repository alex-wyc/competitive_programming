import java.util.*;
import java.io.*;

public class C {
    // Instance Variables
    static class Tree {
        public boolean pkg;
        public int[] contents;
        public Tree left, right;

        public Tree(int size) {
            if (size == 1) {
                pkg = false;
                contents = new int[1];
                contents[0] = -1; // first insert
                left = right = null;
            }
            else if (size == 2) {
                pkg = true;
                contents = new int[2];
                contents[0] = contents[1] = -1;
                left = right = null;
            }
            else if (size % 2 == 1) {
                pkg = false;
                contents = new int[1];
                contents[0] = -1; // first insert
                left = new Tree(size / 2);
                right = new Tree(size / 2);
            }
            else {
                pkg = true;
                contents = new int[2];
                contents[0] = contents[1] = -1;
                left = new Tree((size - 2) / 2);
                right = new Tree((size - 2) / 2);
            }
        }

        public String toString() {
            String result = "";
            String leftString = "";
            String rightString = "";

            if (left != null) {
                leftString = left.toString();
            }
            if (right != null) {
                rightString = right.toString();
            }

            String self = (this.pkg) ? "[o,o]" : "[o]";

            return "(" + leftString + "-" + self + "-" + rightString + ")";
        }

        public void getIthLayer(List<Tree> l, int i) { // return the ith layer of the tree as a list
            if (i == 0) {
                l.add(this);
            }
            else {
                left.getIthLayer(l, i - 1);
                right.getIthLayer(l, i - 1);
            }
        }

        public int[] kthInsert(int k) {
            int lv = 0;
            Tree currentParent = null;
            Tree current = this;
            System.out.println(current);
            k--; // change to 0 index
            while (k >= 0) {
                if (current.pkg) {
                    // a row of packages, 2^(lv + 1)
                    k = k - (int) Math.pow(2, lv + 1);
                }
                else {
                    k = k - (int) Math.pow(2, lv);
                }
                currentParent = current;
                current = current.left;
                lv++;
            }
            lv--;
            current = currentParent;
            System.out.println(current);
            if (current.pkg) {
                k = k + (int) Math.pow(2, lv + 1);
            }
            else {
                k = k + (int) Math.pow(2, lv);
            }
            System.out.println(lv);
            System.out.println(k);
            // now it's kth element in he current level
            List<Tree> currentLv = new ArrayList<Tree>();
            this.getIthLayer(currentLv, lv);

            // get the kth element of currentLv
            // three cases, lv is a pkg level, k > lv size, k < lv size or lv is
            // straight level
            
            if (current.pkg) {
                if (k < currentLv.size()) {
                    // first tier
                    return new int[]{Tree.count(currentLv.get(k).left),
                                     Tree.count(currentLv.get(k).right) + 1};
                }
                else {
                    k = k - currentLv.size();
                    return new int[]{0, Tree.count(currentLv.get(k).right)};
                }
            }
            else {
                // current is a regular node
                return new int[]{Tree.count(currentLv.get(k).left),
                                 Tree.count(currentLv.get(k).right)};
            }
        }

        public static int count(Tree root) {
            if (root == null) {
                return 0;
            }
            if (root.pkg) {
                return 2 + count(root.left) + count(root.right);
            }
            return 1 + count(root.left) + count(root.right);
        }

        public int[] insert(int K) {
            // insert K elements into the tree, returns the L,R range of the
            // last insert
            if (pkg) {
                if (contents[0] == -1) {
                    contents[0] = 1;
                }
                else if (contents[1] == -1) {
                    contents[1] = 1;
                }
            }

            return null;
        }
    }

    // Functions
    public static void main(String[] args) {
        Scanner sin = new Scanner(System.in);
        int T = sin.nextInt();

        for (int i = 0 ; i < T ; i++) {
            int N = sin.nextInt();
            int K = sin.nextInt();

            Tree stalls = new Tree(N);
            int[] result = stalls.kthInsert(K);
            System.out.println("Case #" + (i + 1) + ": " + result[0] + " " + result[1]);
        }
    }
}
