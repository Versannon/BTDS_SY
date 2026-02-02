
public class ExceptionExmaple {
    public static void main(String[]args)
    {
        int a = 10;
        int b = 20;

        int result;

        try{
            result = a/b;
            System.out.println("Result :" + result);
        }
        catch(ArithmeticException e)
        {
            System.out.println("Error :");
        }
        finally{
            System.out.println("Program Executed Successfully");
        }
    }
}
