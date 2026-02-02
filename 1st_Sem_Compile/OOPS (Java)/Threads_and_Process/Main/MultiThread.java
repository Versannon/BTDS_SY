class MyThread extends Thread {
    public void run() {
        System.out.println("MyThread is running: " + Thread.currentThread().getName());
    }
}
public class MultiThread {
    public static void main(String[]args)
    {
        System.out.println("Main Thread : " + Thread.currentThread().getName());
        MyThread t1 = new MyThread();
        t1.start();
        MyThread t2 = new MyThread();
        t2.start();
    }
}