// Example 4: Thread isolation is weak
public class MainDifferencesExample4 {
    static int counter = 0;
    public static void main(String[] args) throws InterruptedException {
        Runnable r = () -> counter++;
        Thread t1 = new Thread(r);
        Thread t2 = new Thread(r);
        t1.start(); t2.start();
        t1.join(); t2.join();
        System.out.println("Counter: " + counter);
    }
}
