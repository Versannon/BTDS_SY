// Example 4: Thread with sleep
public class ThreadExample4 {
    public static void main(String[] args) throws InterruptedException {
        Thread t = new Thread(() -> {
            try {
                Thread.sleep(500);
                System.out.println("Thread woke up after 500ms");
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted");
            }
        });
        t.start();
        t.join();
    }
}
