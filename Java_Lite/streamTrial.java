import java.util.Collection.*;
import java.util.stream.*;
import java.util.function.Consumer;
import java.util.*;

public class streamTrial{
    public static void main(String[] args) {
        List<Integer> values = Arrays.asList(1,2,3,4,5,6); 
        System.out.println("Test List: "+values);



        /*
            Collecting streams into collections using collect method

            The collect method is used to return the result of the intermediate operations performed on the stream.

            Description 
            Stream.collect() is one of the Java 8's Stream API‘s terminal methods. It allows us to perform mutable fold operations (repackaging elements to some data structures and applying some additional logic, concatenating them, etc.) on data elements held in a Stream instance.
            The strategy for this operation is provided via Collector interface implementation.
        */
        System.out.println("\nOutput of collect method examples:");

        // Note- Sets don't guarantee order
        Set<Integer> set = values.stream().collect(Collectors.toSet()); 
        System.out.println("Set obtained from collect: "+set); 

        // Note- Sets don't guarantee order
        Set<Integer> squareSet = values.stream().map(i -> i*i).collect(Collectors.toSet()); 
        System.out.println("Set of squares of elements obtained from collect: "+squareSet); 



        /*
            Reducing streams to values using Reduce method
            
            The reduce method is used to reduce the elements of a stream to a single value.

            Note
            The processing order is not defined here

            Description
            Performs a reduction on the elements of this stream, using the provided identity value and an associative accumulation function, and returns the reduced value.

            Prototype
            T reduce(T identity, BinaryOperator<T> accumulator)
        */
        System.out.println("\nOutput of reduce method examples:");

        // Here 0 is initial value of accumulator, c is the accumulator which goes on increasing and e is each element
        int result = (Integer)values.stream().reduce(0, (c,e) -> c+e);
        System.out.println("Sum of all values: "+result);


        // Performing operation on each element before accumulating

        // Example, finding sum of squares of each element
        result = values.stream().map(i -> i*i).reduce(0, (c,e) -> c+e);
        System.out.println("Sum of squares of all values: "+result);

        // Example, finding sum of only even numbers
        result = values.stream().filter(i -> i%2==0).reduce(0, (c,e) -> c+e);
        System.out.println("Sum of only even numbers: "+result);



        /* 
            Using ForEach method in stream
            
            The forEach method is used to iterate through every element of the stream and perform specified action for each of them.
            
            Note:
            The processing order is not defined here

            Description
            The behavior of this operation is explicitly nondeterministic. For parallel stream pipelines, this operation does not guarantee to respect the encounter order of the stream, as doing so would sacrifice the benefit of parallelism. For any given element, the action may be performed at whatever time and in whatever thread the library chooses. If the action accesses shared state, it is responsible for providing the required synchronization.

            Prototype: void forEachOrdered(Consumer<? super T> action)

            Different ways of usage:
        */
        System.out.println("\nOutput of forEach method examples:");

        // Passing Consumer object
        Consumer<Integer> cs = new Consumer<Integer>(){
            public void accept(Integer i){
                System.out.print(i+" ");
            }
        };
        values.stream().forEach(cs);
        System.out.println();

        // Using Lamda expression instead of consumer object
        values.stream().forEach(i -> System.out.print(i+" "));
        System.out.println();

        // Passing method reference
        values.stream().forEach(System.out::print);
        System.out.println();
    }
}