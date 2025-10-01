public class MainThread {
    public static void main(String[]args)
    {
        System.out.println("program started");
        System.out.println("current thread name: "+Thread.currentThread().getName());
        System.out.println("program ended");
    }
}