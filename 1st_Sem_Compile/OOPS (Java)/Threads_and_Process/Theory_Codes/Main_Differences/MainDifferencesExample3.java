// Example 3: Two processes do not share memory
public class MainDifferencesExample3 {
    public static void main(String[] args) throws Exception {
        ProcessBuilder pb = new ProcessBuilder("cmd.exe", "/c", "set MYVAR=123 && echo %MYVAR%");
        Process p = pb.start();
        java.io.InputStream is = p.getInputStream();
        int b; while((b=is.read())!=-1) System.out.print((char)b);
        is.close();
    }
}
