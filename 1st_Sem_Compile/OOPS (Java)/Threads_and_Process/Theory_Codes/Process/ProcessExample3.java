// Example 3: Checking process exit value
public class ProcessExample3 {
    public static void main(String[] args) throws Exception {
        ProcessBuilder pb = new ProcessBuilder("cmd.exe", "/c", "exit 0");
        Process process = pb.start();
        int exitCode = process.waitFor();
        System.out.println("Process exited with code: " + exitCode);
    }
}
