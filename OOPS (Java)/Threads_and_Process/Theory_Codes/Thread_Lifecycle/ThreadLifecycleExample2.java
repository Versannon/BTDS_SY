// Example 2: Blocked state (waiting for lock)
package Theory_Codes.Thread_Lifecycle;

public class ThreadLifecycleExample2 {
    static final Object lock = new Object();
    public static void main(String[] args) throws InterruptedException {
        Thread t1 = new Thread(() -> {
            synchronized(lock) {
                try { Thread.sleep(1000); } catch (Exception e) {}
            }
        });
        Thread t2 = new Thread(() -> {
            synchronized(lock) {
                System.out.println("t2 acquired lock");
            }
        });
        t1.start();
        Thread.sleep(100); // Ensure t1 gets lock first
        t2.start();
        t1.join(); t2.join();
    }
}
