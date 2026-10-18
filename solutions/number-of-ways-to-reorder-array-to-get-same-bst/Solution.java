import java.util.ArrayList;
import java.util.List;
class Solution {
    long MOD = 1_000_000_007;
    long[][] combinations;
    public int numOfWays(int[] nums) {
        int n = nums.length;
        combinations = new long[n + 1][n + 1];
        precomputeCombinations(n);
        List<Integer> list = new ArrayList<>();
        for (int num : nums) {
            list.add(num);
        }
        return (int) (solve(list) - 1);
    }
    private long solve(List<Integer> nodes) {
        if (nodes.size() <= 2) {
            return 1;
        }
        int rootVal = nodes.get(0);
        List<Integer> leftSubtree = new ArrayList<>();
        List<Integer> rightSubtree = new ArrayList<>();
        for (int i = 1; i < nodes.size(); ++i) {
            if (nodes.get(i) < rootVal) {
                leftSubtree.add(nodes.get(i));
            } else {
                rightSubtree.add(nodes.get(i));
            }
        }
        long leftWays = solve(leftSubtree);
        long rightWays = solve(rightSubtree);
        long waysToCombine = combinations[nodes.size() - 1][leftSubtree.size()];
        long totalWays = (waysToCombine * leftWays) % MOD;
        totalWays = (totalWays * rightWays) % MOD;
        return totalWays;
    }
    private void precomputeCombinations(int n) {
        for (int i = 0; i <= n; ++i) {
            combinations[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                combinations[i][j] = (combinations[i - 1][j - 1] + combinations[i - 1][j]) % MOD;
            }
        }
    }
}