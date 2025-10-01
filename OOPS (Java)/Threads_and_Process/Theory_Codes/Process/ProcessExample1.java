// Example 1: Launching two separate processes using Runtime.exec()
public class ProcessExample1 {
    public static void main(String[] args) throws Exception {
        Process p1 = Runtime.getRuntime().exec("notepad");
        Process p2 = Runtime.getRuntime().exec("calc");
        System.out.println("Launched Notepad and Calculator as separate processes.");
    }
}
