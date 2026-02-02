package Theory_Codes.Thread;


public class ThreadExample5 {
    public static void main(String[] args) {
        Thread t = new Thread(() -> {
            System.out.println("Thread name: " + Thread.currentThread().getName());
            System.out.println("Thread priority: " + Thread.currentThread().getPriority());
        });
        t.setName("CustomThread");
        t.setPriority(Thread.MAX_PRIORITY);
        t.start();
    }
}