package Theory_Codes.Creating_Threads;

public class CreatingThreadsExample2 implements Runnable {
    public void run() {
        System.out.println("Thread via implements Runnable");
    }
    public static void main(String[] args) {
        new Thread(new CreatingThreadsExample2()).start();
    }
}
