package Theory_Codes.Creating_Threads;

import java.util.concurrent.*;
public class CreatingThreadsExample3 {
    public static void main(String[] args) throws Exception {
        Callable<String> c = () -> "Result from Callable";
        ExecutorService es = Executors.newSingleThreadExecutor();
        Future<String> f = es.submit(c);
        System.out.println(f.get());
        es.shutdown();
    }
}
