/*5.2 Write a method which takes a list of words as an argument,
 groups the words by their lengths and returns the groupings in the form of Map<Integer, List<String>>. 
 (The keys in the map are the lengths and the values are the lists of words of that length.)*/
 
// Grouping string by length
// with the help of Collectors.groupingBy() method 

import java.util.*; 
import java.util.stream.Collectors;
import java.util.stream.Stream; 
   
// main class and method 
public class exp5_2{ 
  
    // main Driver 
    private static Stream<String> stream;

    public static void main(String[] args) 
    { 
  
        // create a list 

List<String> strings = Arrays.asList("this", "is", "a", "long", "list", "of",
        "strings", "to", "use", "as", "a", "trial");

stream = strings.stream();
Map<Integer, List<String>> lengthMap = stream.collect(Collectors.groupingBy(String::length)); 

lengthMap.forEach((k,v) -> System.out.printf("%d: %s%n", k, v));
    }
}