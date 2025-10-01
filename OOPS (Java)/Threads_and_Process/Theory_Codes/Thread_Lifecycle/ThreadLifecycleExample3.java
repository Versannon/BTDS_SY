// Example 3: Waiting state (wait/notify)
package Theory_Codes.Thread_Lifecycle;

public class ThreadLifecycleExample3 {
    public static void main(String[] args) throws InterruptedException {
        final Object lock = new Object();
        Thread t = new Thread(() -> {
            synchronized(lock) {
                try {
                    lock.wait();
                } catch (InterruptedException e) {}
                System.out.println("Thread notified");
            }
        });
        t.start();
        Thread.sleep(500);
        synchronized(lock) {
            lock.notify();
        }
        t.join();
    }
}
