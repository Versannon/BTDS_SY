public class ThreadMethodsDemo {
    public static void main(String[] args) {
        // Create thread object
        MyThread t1 = new MyThread();

        // Demonstrating setName() and setPriority()
        t1.setName("Worker-1");
        t1.setPriority(Thread.MAX_PRIORITY); // 10

        // Showing getName(), getId(), getPriority()
        System.out.println("Thread Name: " + t1.getName());
        System.out.println("Thread ID: " + t1.threadId());
        System.out.println("Thread Priority: " + t1.getPriority());

        // isAlive() before start
        System.out.println("Is thread alive before start? " + t1.isAlive());

        // start() calls run() internally in a new thread
        t1.start();

        // isAlive() after start
        System.out.println("Is thread alive after start? " + t1.isAlive());

        // join() — main thread waits for t1 to finish
        try {
            t1.join();
        } catch (InterruptedException e) {
            System.out.println("Main thread interrupted!");
        }

        // After completion
        System.out.println("Is thread alive after join? " + t1.isAlive());
        System.out.println("Main thread finished.");
    }
}
// Demonstration of common Thread methods
class MyThread extends Thread {
    public void run() {
        System.out.println("Running thread: " + getName());
        for (int i = 1; i <= 3; i++) {
            System.out.println(getName() + " → Count: " + i);
            try {
                Thread.sleep(1000); // Demonstrates sleep()
            } catch (InterruptedException e) {
                System.out.println(getName() + " interrupted!");
            }
        }
        System.out.println(getName() + " finished.");
    }
}