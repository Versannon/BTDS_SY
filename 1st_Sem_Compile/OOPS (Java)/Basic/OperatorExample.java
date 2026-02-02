public class OperatorExample {
    public static void main(String[] args) {
        int a = 10, b = 5;

        System.out.println("Addition: " + (a + b));
        System.out.println("Subtraction: " + (a - b));
        System.out.println("Multiplication: " + (a * b));
        System.out.println("Division: " + (a / b));
        System.out.println("Remainder: " + (a % b));

        System.out.println("Is a > b? " + (a > b));
        System.out.println("Logical AND: " + (a > 0 && b > 0));
    }
}