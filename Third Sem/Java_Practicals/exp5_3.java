import java.util.*;
import java.util.stream.*;

class exp5_3 {
    public static void main(String[] args) {

        ArrayList<String> list1 = new ArrayList();        
        list1.add("Government");
        list1.add("Polytechnic");
        list1.add("Mumbai");

        ArrayList<String> list2 = new ArrayList();
        list2.add("A.Y. Jung Marg");
        list2.add("Kherwadi");
        list2.add("Bandra (E)");
        
        ArrayList<ArrayList<String>> listOflist = new ArrayList();
        listOflist.add(list1);
        listOflist.add(list2);

        System.out.println("LIST1 : " + list1);
        System.out.println("LIST2 : " + list2);
        System.out.println("LIST<LIST<String>> :" + listOflist);

        ArrayList<String> result = new ArrayList();
        listOflist.forEach(result::addAll);

        System.out.println("RESULT : " + result);
    }
}
