import java.io.*;
import java.util.*;

public class SegTree {
    long[] tree;
    int n;
    public SegTree(int[] nums) {
        if (nums.length > 0) {
            n = nums.length;
            tree = new long[n * 4];
            //buildTree(nums);
        }
    }
    private void buildTree(int[] nums) {
        for (int i = n, j = 0;  i < 2 * n; i++,  j++)
            tree[i] = (long)nums[j];
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }


    void update(int pos, long val) {
        pos += n;
        tree[pos] = val;
        while (pos > 0) {
            int left = pos;
            int right = pos;
            if (pos % 2 == 0) {
                right = pos + 1;
            } else {
                left = pos - 1;
            }
            // parent is updated after child is updated
            tree[pos / 2] = tree[left] + tree[right];
            pos /= 2;
        }
    }
    public long sumRange(int l, int r) {
        // get leaf with value 'l'
        l += n;
        // get leaf with value 'r'
        r += n;
        long sum = 0;
        while (l <= r) {
            if ((l % 2) == 1) {
               sum += tree[l];
               l++;
            }
            if ((r % 2) == 0) {
               sum += tree[r];
               r--;
            }
            l /= 2;
            r /= 2;
        }
        return sum;
    }
    
    public void print(){
        for(int i = 0; i < n * 4; ++i){
            System.out.print(tree[i]+",");
        }
        System.out.println();
    }
}