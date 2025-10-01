class car1 extends Thread 
{
    public void run()
    {
        for(int i=0; i<=5; i++)
        {
            System.out.println(i);
        }
    }    
}
class Car_extends
{
    public static void main(String args[])
    {
        car1 t = new car1();
        t.start();
    }
}