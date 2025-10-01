// Example 2: sleep()
public class ThreadMethodsExample2 {
    public static void main(String[] args) throws InterruptedException {
        Thread t = new Thread(() -> {
            try {
                Thread.sleep(500);
                System.out.println("Woke up after 500ms");
            } catch (InterruptedException e) {}
        });
        t.start();
        t.join();
    }
}
