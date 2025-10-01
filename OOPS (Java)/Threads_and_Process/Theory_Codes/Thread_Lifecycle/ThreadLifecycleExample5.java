// Example 5: Daemon thread lifecycle
package Theory_Codes.Thread_Lifecycle;

public class ThreadLifecycleExample5 {
    public static void main(String[] args) throws InterruptedException {
        Thread t = new Thread(() -> {
            while(true) {}
        });
        t.setDaemon(true);
        t.start();
        System.out.println("Daemon thread started. Main will exit, daemon will die.");
    }
}
