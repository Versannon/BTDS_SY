package Theory_Codes.Creating_Threads;

public class CreatingThreadsExample5 {
    public static void main(String[] args) {
        Thread t = new Thread(() -> System.out.println("Lambda Runnable thread"));
        t.start();
    }
}
