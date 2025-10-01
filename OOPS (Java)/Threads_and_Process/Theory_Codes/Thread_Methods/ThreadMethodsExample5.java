// Example 5: isAlive()
public class ThreadMethodsExample5 {
    public static void main(String[] args) throws InterruptedException {
        Thread t = new Thread(() -> {});
        System.out.println("Before start: " + t.isAlive());
        t.start();
        t.join();
        System.out.println("After join: " + t.isAlive());
    }
}
