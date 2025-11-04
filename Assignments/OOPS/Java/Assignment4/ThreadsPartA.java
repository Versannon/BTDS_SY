class MyThread extends Thread {
    public void run() {
        System.out.println("Thread (extends) running");
    }
}
class MyRunnable implements Runnable {
    public void run() {
        System.out.println("Thread (runnable) running");
    }
}
public class ThreadsPartA {
    public static void main(String[] args) throws InterruptedException {
        MyThread t1 = new MyThread();
        Thread t2 = new Thread(new MyRunnable());
        t1.start();
        t2.start();
        t1.join();
        t2.join();
        System.out.println("Main finished");
    }
}
