// Example 1: Creating a thread by extending Thread
public class ThreadExample1 extends Thread {
    public void run() {
        System.out.println("Thread running via extends Thread");
    }
    public static void main(String[] args) {
        ThreadExample1 t = new ThreadExample1();
        t.start();
    }
}
