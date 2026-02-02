// Example 3: join()
public class ThreadMethodsExample3 {
    public static void main(String[] args) throws InterruptedException {
        Thread t = new Thread(() -> {
            for(int i=0;i<3;i++) System.out.println("Thread: " + i);
        });
        t.start();
        t.join();
        System.out.println("Main after join");
    }
}
