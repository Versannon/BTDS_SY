// Example 5: Process isolation is strong
public class MainDifferencesExample5 {
    public static void main(String[] args) throws Exception {
        ProcessBuilder pb = new ProcessBuilder("cmd.exe", "/c", "echo This is a separate process");
        Process p = pb.start();
        java.io.InputStream is = p.getInputStream();
        int b; while((b=is.read())!=-1) System.out.print((char)b);
        is.close();
    }
}
