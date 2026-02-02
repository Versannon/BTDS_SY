// Example 1: Thread states - New, Runnable, Running, Blocked, Terminated
package Theory_Codes.Thread_Lifecycle;

public class ThreadLifecycleExample1 {
    public static void main(String[] args) throws InterruptedException {
        Thread t = new Thread(() -> {
            System.out.println("Thread running");
        });
        System.out.println("State after creation: " + t.getState()); // NEW
        t.start();
        System.out.println("State after start: " + t.getState()); // RUNNABLE
        t.join();
        System.out.println("State after join: " + t.getState()); // TERMINATED
    }
}
