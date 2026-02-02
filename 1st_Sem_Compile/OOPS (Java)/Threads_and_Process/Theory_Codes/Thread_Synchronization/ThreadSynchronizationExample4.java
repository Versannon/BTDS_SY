// Example 4: Using Semaphore
import java.util.concurrent.*;
public class ThreadSynchronizationExample4 {
    private int count = 0;
    private final Semaphore sem = new Semaphore(1);
    public void increment() throws InterruptedException {
        sem.acquire();
        try { count++; } finally { sem.release(); }
    }
    public static void main(String[] args) throws InterruptedException {
        ThreadSynchronizationExample4 obj = new ThreadSynchronizationExample4();
        Thread t1 = new Thread(() -> { try { for(int i=0;i<1000;i++) obj.increment(); } catch(Exception e){} });
        Thread t2 = new Thread(() -> { try { for(int i=0;i<1000;i++) obj.increment(); } catch(Exception e){} });
        t1.start(); t2.start(); t1.join(); t2.join();
        System.out.println("Count: " + obj.count);
    }
}
