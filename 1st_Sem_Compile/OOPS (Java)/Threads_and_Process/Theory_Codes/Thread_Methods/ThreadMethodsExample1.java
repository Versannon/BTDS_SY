// Example 1: start() and run()
public class ThreadMethodsExample1 extends Thread {
    public void run() {
        System.out.println("run() called");
    }
    public static void main(String[] args) {
        new ThreadMethodsExample1().start();
    }
}
