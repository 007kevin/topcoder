import java.util.*;
public class MergersDivTwo {
    int k,n;
    double[] revs, sum, dp;
    public double findMaximum(int[] revenues, int k) {
        this.n=revenues.length;
        this.k=k;
        this.revs = Arrays.stream(revenues)
                .asDoubleStream()
                .toArray();
        this.sum = new double[n+1];
        this.dp = new double[n+1];
        Arrays.sort(revs);
        for(int i = 1; i <= n; ++i){
            sum[i]=revs[i-1]+sum[i-1];
        }
        return get(n);
    }

    public double get(int i){
        if(i==k) return sum[i]/(double) k;
        if(dp[i]!=0) return dp[i];
        double best = sum[i]/(double) i;
        for(int j = k; j <= i-k+1; ++j){
            best = Math.max(best,
                    (get(j) + (sum[i] - sum[j]))/(double) (i-j+1));
        }
        return dp[i]=best;

    }

    // BEGIN CUT HERE
    public static void main(String[] args){
        MergersDivTwo test = new MergersDivTwo();
        double ans = test.findMaximum(new int[]{5,-7,3}, 3);
        System.out.println(ans);
    }
    // END CUT HERE
}
