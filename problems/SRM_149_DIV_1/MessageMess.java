// BEGIN CUT HERE

// END CUT HERE
import java.util.*;
public class MessageMess {
    int n;
    long[] dp;
    String message;
    Set<String> set = new HashSet<>();
    public String restore(String[] dictionary, String message) {
        n = message.length();
        dp = new long[n];
        Arrays.fill(dp,-1);
        this.message = message;
        Arrays.stream(dictionary).forEach(set::add);
        long cnt = find(0);
        if(cnt==0) return "IMPOSSIBLE!";
        if(cnt > 1) return "AMBIGUOUS!";
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; ++i){
            if(dp[i]==1){
                int j = i+1;
                while(j<n&&dp[j]!=1) j++;
                sb.append(message.substring(i, j) + " ");
                i=j-1;
            }
        }

        sb.setLength(sb.length()-1);
        return sb.toString();
    }

    public long find(int i){
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];
        long cnt = 0;
        for(int j = i+1; j <= n; ++j){
            if(set.contains(message.substring(i, j))){
                cnt+=find(j);
            }
        }
        return dp[i]=cnt;
    }
}
