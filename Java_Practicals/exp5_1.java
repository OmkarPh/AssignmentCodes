import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

public class  exp5_1 {

    static class Student {
        String name = "";
        public int roll = 0;
        public int marks = 0;
        public Student(String name, int roll, int marks) {
            this.name = name;
            this.roll = roll;
            this.marks = marks;
        }
    }

    public static <T extends  Number> long  evenNumbers(List<T> list) {
        Stream<T> stream = list.stream();
        return stream.filter(number -> number.doubleValue() % 2 != 0).count();
    }

    public static <T extends Student> long  numberOfPassedStudents(List<? extends Student> list) {
        Stream<T> stream = (Stream<T>) list.stream();
        return stream.filter(student -> student.marks >= 35).count();

    }

    public static void main(String[] args) {

        Student s1 = new Student("Roy", 43, 60);
        Student s2 = new Student("Niel", 44, 49);
        Student s3 = new Student("Leo", 30, 75);
        Student s4 = new Student("lisa", 35, 30);
        Student s5 = new Student("Russ", 40, 28);

        List<Integer> list = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        List<Student> list1 = Arrays.asList(s1, s2, s3, s4, s5);

        long evenNumbers = evenNumbers(list) ;
        long numberOfPassedStudents = numberOfPassedStudents(list1) ;

        System.out.println("There are "+ evenNumbers +" even numbers.");
        System.out.println(numberOfPassedStudents+" students have passed the exam.");
    }
}