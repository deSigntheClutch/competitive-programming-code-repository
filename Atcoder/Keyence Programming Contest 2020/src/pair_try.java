import java.util.*;

public class pair_try {
    public static void main(String[] args) {
        //System.out.print(num1.toString());

        List<Pair<Long, String>> a = new ArrayList<Pair<Long, String>>();
        Pair<Long, String> ad = new Pair<Long, String>(12L, "das");
        Pair<Long, String> lbj = new Pair<Long, String>(23L, "das");
        Pair<Long, String> dg = new Pair<Long, String>(2L, "d32as");
        Pair<Long, String> mc = new Pair<Long, String>(2L, "1das");
        a.add(ad);
        a.add(lbj);
        a.add(dg);
        a.add(mc);
        Collections.sort(a);
        for (Pair<Long, String> x : a) {
            System.out.print(x.toString() + " ");
        }
        System.out.print("\n");
    }



}
class Pair<U extends Comparable, V extends Comparable> implements Comparable{
    U first;
    V second;
    {
        System.out.println("----new pair");
    }
    Pair(U x, V y) {
        first = x;
        second = y;
    }

    @Override
    public int hashCode() {
        return 29 * first.hashCode() + second.hashCode();
    }

    public int compareTo(Object obj) {
        Pair<U, V> p = (Pair<U, V>) obj;
        if (first != ((Pair<U, V>) obj).first) {
            return first.compareTo(p.first);
        }
        return second.compareTo(p.second);
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || obj.getClass() != getClass()) return false;
        Pair<U, V> p = (Pair<U, V>) obj;
        return p.first == this.first && p.second == this.second;
    }
    public String toString() {
        return "(" + first + ", " + second + ")";
    }

}