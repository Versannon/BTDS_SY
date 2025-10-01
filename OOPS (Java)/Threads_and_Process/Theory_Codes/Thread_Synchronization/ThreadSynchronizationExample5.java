// Example 5: Using CountDownLatch
import java.util.concurrent.*;
public class ThreadSynchronizationExample5 {
    public static void main(String[] args) throws InterruptedException {
        CountDownLatch latch = new CountDownLatch(2);
        Runnable r = () -> { System.out.println(Thread.currentThread().getName()); latch.countDown(); };
        new Thread(r).start();
        new Thread(r).start();
        latch.await();
        System.out.println("Both threads finished");
    }
}
