// Example 3: Using ReentrantLock
import java.util.concurrent.locks.*;
public class ThreadSynchronizationExample3 {
    private int count = 0;
    private final Lock lock = new ReentrantLock();
    public void increment() {
        lock.lock();
        try { count++; } finally { lock.unlock(); }
    }
    public static void main(String[] args) throws InterruptedException {
        ThreadSynchronizationExample3 obj = new ThreadSynchronizationExample3();
        Thread t1 = new Thread(() -> { for(int i=0;i<1000;i++) obj.increment(); });
        Thread t2 = new Thread(() -> { for(int i=0;i<1000;i++) obj.increment(); });
        t1.start(); t2.start(); t1.join(); t2.join();
        System.out.println("Count: " + obj.count);
    }
}
