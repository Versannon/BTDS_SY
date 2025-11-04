class Counter {
    private int count = 0;
    public void incrementUnsync() { count++; }
    public synchronized void incrementSync() { count++; }
    public int get() { return count; }
}
public class ThreadsSync {
    public static void main(String[] args) throws InterruptedException {
        final Counter c = new Counter();
        // Without synchronization
        Thread t1 = new Thread(() -> { for (int i=0;i<10000;i++) c.incrementUnsync(); });
        Thread t2 = new Thread(() -> { for (int i=0;i<10000;i++) c.incrementUnsync(); });
        t1.start(); t2.start(); t1.join(); t2.join();
        System.out.println("Unsync count (likely <20000): " + c.get());

        // With synchronization
        final Counter c2 = new Counter();
        Thread t3 = new Thread(() -> { for (int i=0;i<10000;i++) c2.incrementSync(); });
        Thread t4 = new Thread(() -> { for (int i=0;i<10000;i++) c2.incrementSync(); });
        t3.start(); t4.start(); t3.join(); t4.join();
        System.out.println("Sync count (should be 20000): " + c2.get());

        // Simple deadlock demonstration (do NOT run in production)
        final Object A = new Object(), B = new Object();
        Thread da = new Thread(() -> { synchronized(A) { try{Thread.sleep(50);}catch(Exception e){} synchronized(B){} }});
        Thread db = new Thread(() -> { synchronized(B) { try{Thread.sleep(50);}catch(Exception e){} synchronized(A){} }});
        da.start(); db.start();
        // may deadlock; we don't join to avoid blocking main indefinitely
        System.out.println("Started two threads that may deadlock (demo).");
    }
}
