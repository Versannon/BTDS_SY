class Vehicle {
    class MyTask extends Vehicle implements Runnable{
        public void run()
        {
            System.out.println("Thread is running");
        }
    }
}
class Single implements Runnable{
    public void run()
    {
        for(int i=0; i<=5; i++)
        {
            System.out.println(i);
        }
    }
}
class Car{
    public static void main(String args[])
    {
        Single s=new Single();
        Thread t = new Thread (s);
        t.start();
    }
}