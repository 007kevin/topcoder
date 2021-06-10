// BEGIN CUT HERE

// END CUT HERE
import java.util.*;
import java.util.stream.Collectors;
public class TurntableService {
    int n,h;
    int[] t, e;
    List<Set<Integer>> favs;

    public int calculateTime(String[] favorites) {
        n = favorites.length;
        t = new int[n];
        e = new int[n];
        h = gen(n);
        favs = Arrays.stream(favorites)
                .map(this::parse)
                .collect(Collectors.toList());
        return find(0);
    }

    public int find(int i){
        if(h==e.hashCode()) return 0;
        int t = Integer.MAX_VALUE;
        for(int r = 1; r <= n/2; ++r){
            int next = (i+r)%n;
            if(any(next)){
                int[] prev = e.clone();
                fill(next);
                int time = r+1 + 15 + find(next);
                t=Math.min(t,time);
                e=prev;
            }
        }
        for(int r = 1; r <= n/2 - (n%2==0?1:0); ++r){
            int next = (i-r) < 0 ? n-(i-r) : (i-r);
            if(any(next)){
                int[] prev = e.clone();
                fill(next);
                int time = r+1 + 15 + find(next);
                t=Math.min(t,time);
                e=prev;
            }
        }
        dp.put(e.clone(), t);
        return t;
    }

    public int gen(int n){
        int[] a = new int[n];
        Arrays.fill(a, 1);
        return a.hashCode();
    }


    public Set<Integer> parse(String fav){
        Set<Integer> set = new HashSet<>();
        StringTokenizer token = new StringTokenizer(fav);
        while(token.hasMoreTokens())
            set.add(Integer.parseInt(token.nextToken()));
        return set;
    }

}
