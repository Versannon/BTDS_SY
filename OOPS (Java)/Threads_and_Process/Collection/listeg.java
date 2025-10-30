import java util.*
public class listeg 
{
    public static void main(String[]args)
    {
        ArrayList<String> Students = new ArrayList<String>();
        Students.add("Soham");
        Students.add("Anik");
        Students.add("Ritik");
        Students.add("Aman");

        //display the list
        System.out.println("First Student: " + Students.get(0));
        //remove element
        Student.remove("Aman");
        //loop through list
        System.out.println("List of Students:");
        for(String Student: Students)
        {
            System.out.println(Student);
        }
    }
}
