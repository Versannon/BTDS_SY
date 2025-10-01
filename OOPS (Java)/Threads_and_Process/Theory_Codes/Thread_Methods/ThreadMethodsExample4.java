// Example 4: getId(), getName(), setName(), getPriority()
public class ThreadMethodsExample4 {
    public static void main(String[] args) {
        Thread t = new Thread(() -> {
            System.out.println("ID: " + Thread.currentThread().getId());
            System.out.println("Name: " + Thread.currentThread().getName());
            System.out.println("Priority: " + Thread.currentThread().getPriority());
        });
        t.setName("CustomName");
        t.setPriority(Thread.MAX_PRIORITY);
        t.start();
    }
}
