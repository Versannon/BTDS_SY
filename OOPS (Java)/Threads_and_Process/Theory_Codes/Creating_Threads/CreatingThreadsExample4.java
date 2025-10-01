package Theory_Codes.Creating_Threads;

public class CreatingThreadsExample4 {
    public static void main(String[] args) {
        Thread t = new Thread(new Runnable() {
            public void run() {
                System.out.println("Anonymous Runnable thread");
            }
        });
        t.start();
    }
}
