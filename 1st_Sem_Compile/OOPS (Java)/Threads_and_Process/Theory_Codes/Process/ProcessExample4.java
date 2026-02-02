// Example 4: Reading error stream from a process
public class ProcessExample4 {
    public static void main(String[] args) throws Exception {
        ProcessBuilder pb = new ProcessBuilder("cmd.exe", "/c", "dir non_existing_file");
        Process process = pb.start();
        java.io.InputStream es = process.getErrorStream();
        int b;
        while ((b = es.read()) != -1) {
            System.out.print((char) b);
        }
        es.close();
    }
}
