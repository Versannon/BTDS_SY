// Example 2: Creating a thread by implementing Runnable
public class ThreadExample2 implements Runnable {
    public void run() {
        System.out.println("Thread running via implements Runnable");
    }
    public static void main(String[] args) {
        Thread t = new Thread(new ThreadExample2());
        t.start();
    }
}
