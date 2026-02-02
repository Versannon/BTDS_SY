// Take input from user of marks using 'Scanner'. If less than 0 or greater than 100, throw an exception. Must use 'finally' block.

public class std_marks
{
    public static void main(String[]args)
    {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        int marks = 0;
        try {
            System.out.print("Enter marks (0-100): ");
            marks = sc.nextInt();
            if(marks < 0 || marks > 100) {
                throw new Exception("Marks must be between 0 and 100.");
            }
            System.out.println("Marks entered: " + marks);
        } catch(Exception e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            sc.close();
            System.out.println("Scanner closed.");
        }
    }
}

/*
Detailed Explanation:
---------------------
1. The program defines a class called std_marks with a main method.
2. Inside main, a Scanner object is created to take input from the user.
3. The user is prompted to enter marks between 0 and 100.
4. The input is read using sc.nextInt().
5. If the entered marks are less than 0 or greater than 100, an Exception is thrown with a message.
6. If the input is valid, the marks are printed.
7. If any exception occurs (invalid input or out-of-range marks), the error message is printed in the catch block.
8. The finally block always executes, closing the Scanner and printing a message that the Scanner is closed.
9. This ensures resources are freed and the program handles errors gracefully.
*/
