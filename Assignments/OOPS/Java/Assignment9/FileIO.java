import java.io.*;
public class FileIO {
    public static void main(String[] args) {
        String filename = "data.txt";
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filename))) {
            bw.write("George,78\n");
            bw.write("Hannah,85\n");
        } catch (IOException e) {
            System.out.println("Write error: " + e.getMessage());
        }
        System.out.println("File contents:");
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = br.readLine()) != null) System.out.println(line);
        } catch (IOException e) {
            System.out.println("Read error: " + e.getMessage());
        }
    }
}
