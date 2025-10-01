// Example 3: Multiple threads running concurrently
public class ThreadExample3 {
    public static void main(String[] args) {
        Runnable r = () -> {
            for (int i = 0; i < 3; i++) {
                System.out.println(Thread.currentThread().getName() + " running");
            }
        };
        Thread t1 = new Thread(r, "Thread-1");
        Thread t2 = new Thread(r, "Thread-2");
        t1.start();
        t2.start();
    }
}
