package Theory_Codes.Creating_Threads;

public class CreatingThreadsExample1 extends Thread {
    public void run() {
        System.out.println("Thread via extends Thread");
    }
    public static void main(String[] args) {
        new CreatingThreadsExample1().start();
    }
}

