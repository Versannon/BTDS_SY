class Account
{
    int balance = 1000;
    synchronized void withdraw(int amount)
    {
        if(balance >= amount)
        {
            balance -= amount;
            System.out.println("WithDraw: " + amount +" \n Balance: " + balance);
        }
        else{
            System.out.println("Insufficient Balance! ");
        }
    }
}
class MyThread extends Thread{
    Account acc;
    int amount;
    MyThread(Account acc, int amount)
    {
        this.acc = acc;
        this.amount = amount;
    }
    public void run()
    {
        acc.withdraw(amount);
    }
}

public class Test
{
    public static void main(String[] args) {
        Account acc = new Account();
        MyThread t1 = new MyThread(acc, 800);
        MyThread t2 = new MyThread(acc, 600);
        t1.start();
        t2.start();
    }
}