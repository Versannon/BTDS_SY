// Example 2: Two threads sharing a variable
public class MainDifferencesExample2 {
    static int shared = 0;
    public static void main(String[] args) throws InterruptedException {
        Runnable r = () -> { for(int i=0;i<1000;i++) shared++; };
        Thread t1 = new Thread(r);
        Thread t2 = new Thread(r);
        t1.start(); t2.start();
        t1.join(); t2.join();
        System.out.println("Shared value: " + shared);
    }
}
