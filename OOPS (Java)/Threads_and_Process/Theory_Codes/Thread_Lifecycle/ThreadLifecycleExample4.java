// Example 4: Terminated state
package Theory_Codes.Thread_Lifecycle;

public class ThreadLifecycleExample4 {
    public static void main(String[] args) throws InterruptedException {
        Thread t = new Thread(() -> {});
        t.start();
        t.join();
        System.out.println("Thread state: " + t.getState()); // TERMINATED
    }
}
