public class ExceptionHandlingJava {
    public static int safeDivide(String aStr, String bStr) {
        try {
            int a = Integer.parseInt(aStr); // may throw NumberFormatException
            int b = Integer.parseInt(bStr);
            return a / b; // may throw ArithmeticException
        } finally {
            System.out.println("Finally block executed");
        }
    }
    public static void main(String[] args) {
        try {
            int r = safeDivide("10", "0"); // change "0" to "a" to see invalid input
            System.out.println("Result: " + r);
        } catch (ArithmeticException e) {
            System.out.println("Division by zero");
        } catch (NumberFormatException e) {
            System.out.println("Invalid input format");
        } catch (Exception e) {
            System.out.println("Other error: " + e.getMessage());
        }
    }
}
