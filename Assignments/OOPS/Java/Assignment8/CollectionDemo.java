import java.util.*;
public class CollectionDemo {
    public static void main(String[] args) {
        List<String> names = new ArrayList<>(Arrays.asList("Anna","Bob","Anna","Charlie"));
        System.out.println("ArrayList: " + names);
        Set<String> set = new HashSet<>(names);
        System.out.println("HashSet (duplicates removed): " + set);
        Map<Integer,String> map = new HashMap<>();
        map.put(1,"Anna"); map.put(2,"Bob"); map.put(3,"Charlie");
        System.out.println("HashMap: " + map);
        Collections.sort(names); // sorts list (may include duplicates)
        System.out.println("Sorted list: " + names);
        System.out.println("Iterating using for-each:");
        for (String n : names) System.out.println(n);
    }
}
