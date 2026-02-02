// Example 2: ProcessBuilder to run a command and get output
public class ProcessExample2 {
    public static void main(String[] args) throws Exception {
        ProcessBuilder pb = new ProcessBuilder("cmd.exe", "/c", "echo Hello from process");
        Process process = pb.start();
        java.io.InputStream is = process.getInputStream();
        int b;
        while ((b = is.read()) != -1) {
            System.out.print((char) b);
        }
        is.close();
    }
}
