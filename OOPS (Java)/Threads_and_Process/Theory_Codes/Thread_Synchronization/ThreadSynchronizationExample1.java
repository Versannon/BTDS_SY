// Example 1: Synchronized method
public class ThreadSynchronizationExample1 {
    private int count = 0;
    public synchronized void increment() { count++; }
    public static void main(String[] args) throws InterruptedException {
        ThreadSynchronizationExample1 obj = new ThreadSynchronizationExample1();
        Thread t1 = new Thread(() -> { for(int i=0;i<1000;i++) obj.increment(); });
        Thread t2 = new Thread(() -> { for(int i=0;i<1000;i++) obj.increment(); });
        t1.start(); t2.start(); t1.join(); t2.join();
        System.out.println("Count: " + obj.count);
    }
}
