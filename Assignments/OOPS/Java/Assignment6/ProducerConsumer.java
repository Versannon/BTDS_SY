import java.util.*;
class Buffer {
    private final LinkedList<Integer> list = new LinkedList<>();
    private final int capacity = 5;
    public synchronized void produce(int val) throws InterruptedException {
        while (list.size() == capacity) wait();
        list.add(val);
        notifyAll();
    }
    public synchronized int consume() throws InterruptedException {
        while (list.isEmpty()) wait();
        int val = list.removeFirst();
        notifyAll();
        return val;
    }
}
public class ProducerConsumer {
    public static void main(String[] args) {
        Buffer buf = new Buffer();
        Thread p = new Thread(() -> { try { for (int i=1;i<=10;i++){ buf.produce(i); System.out.println("Produced " + i); Thread.sleep(50);} } catch(Exception e){} });
        Thread c = new Thread(() -> { try { for (int i=1;i<=10;i++){ int v = buf.consume(); System.out.println("Consumed " + v); Thread.sleep(80);} } catch(Exception e){} });
        p.start(); c.start();
        try { p.join(); c.join(); } catch(InterruptedException e) {}
    }
}
