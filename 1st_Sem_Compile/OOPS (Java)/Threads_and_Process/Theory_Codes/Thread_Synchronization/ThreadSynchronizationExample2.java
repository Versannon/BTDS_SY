// Example 2: Synchronized block
public class ThreadSynchronizationExample2 {
    private int count = 0;
    private final Object lock = new Object();
    public void increment() {
        synchronized(lock) { count++; }
    }
    public static void main(String[] args) throws InterruptedException {
        ThreadSynchronizationExample2 obj = new ThreadSynchronizationExample2();
        Thread t1 = new Thread(() -> { for(int i=0;i<1000;i++) obj.increment(); });
        Thread t2 = new Thread(() -> { for(int i=0;i<1000;i++) obj.increment(); });
        t1.start(); t2.start(); t1.join(); t2.join();
        System.out.println("Count: " + obj.count);
    }
}
