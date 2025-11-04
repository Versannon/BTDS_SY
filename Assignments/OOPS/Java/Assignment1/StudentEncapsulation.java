public class StudentEncapsulation {
    private String name;
    private int rollNo;
    private int marks;

    public StudentEncapsulation(String name, int rollNo, int marks) {
        this.name = name;
        this.rollNo = rollNo;
        this.marks = marks;
    }
    public String getName() { return name; }
    public void setName(String name) { this.name = name; }
    public int getRollNo() { return rollNo; }
    public void setRollNo(int rollNo) { this.rollNo = rollNo; }
    public int getMarks() { return marks; }
    public void setMarks(int marks) { this.marks = marks; }
    public void display() {
        System.out.println("Name: " + name + " Roll: " + rollNo + " Marks: " + marks);
    }

    public static void main(String[] args) {
        StudentEncapsulation s = new StudentEncapsulation("Eve", 101, 90);
        s.display();
        s.setMarks(95);
        s.display();
    }
}
