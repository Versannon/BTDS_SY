import java util.*
public class seteg
{
    public static void main(String[]args)
    {
        HashSet<Integer> numbers = new HashSet<>();
        numbers.add(10);
        numbers.add(20);
        numbers.add(30);
        System.out.println("Set elements: " + numbers);
        numbers.remove(20);
        System.out.println("After removing 20: " + numbers);
    }
}