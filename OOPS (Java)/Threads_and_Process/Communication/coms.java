class ShareData
{
    private boolean ready = false;
    synchronized void waitForSignal() {
        System.out.println("Thread waiting....");
        try {
            while (!ready) {
                wait();
            }
        } catch (InterruptedException e) {
            System.out.println(e);
        }
        System.out.println("Thread got signal....");
    }

    synchronized void SendSignal() {
        System.out.println("Signal send by another thread....");
        ready = true;
        notify();
    }
}

public class coms {
    public static void main(String[] args) {
        ShareData data = new ShareData();
        Thread t1 = new Thread(() -> data.waitForSignal());
        Thread t2 = new Thread(() -> {
            try {
                Thread.sleep(5000);
            } catch (Exception e) {}
            data.SendSignal();
        });
        t1.start();
        t2.start();
    }
}