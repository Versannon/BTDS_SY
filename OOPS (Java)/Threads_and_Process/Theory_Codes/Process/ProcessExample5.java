// Example 5: Running a process and writing to its input stream
public class ProcessExample5 {
    public static void main(String[] args) throws Exception {
        ProcessBuilder pb = new ProcessBuilder("cmd.exe");
        Process process = pb.start();
        java.io.OutputStream os = process.getOutputStream();
        os.write("echo Hello from input stream\r\n".getBytes());
        os.flush();
        os.close();
        java.io.InputStream is = process.getInputStream();
        int b;
        while ((b = is.read()) != -1) {
            System.out.print((char) b);
        }
        is.close();
        process.destroy();
    }
}
