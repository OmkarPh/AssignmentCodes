// Program for demonstration of Constructor 
import java.util.*;

class Car{
    int seats, price;
    String name;

    public Car(){
        this.name = "Family car";
        this.price = 200000;
        this.seats = 4;
        System.out.println("Default car created succesfuly !");
    }
    public Car(String name, int price){
        this(name, price, 4);
    }
    public Car(String name, int price, int seats){
        this.name = name;
        this.price = price;
        this.seats = seats;
        System.out.println("Car "+name+" created succesfuly !");
    }

    public String toString(){
        return this.name + ", price: "+  this.price + " with " + seats +  " seats";
    }
}

public class Practical{
    public void print(){
        System.out.println("HI");
    }
    public static void main(String[] args) {
        Practical sd = new Practical();
        sd.print();
        Car car1 = new Car();
        Car swift = new Car("Maruti suzuki Swift", 700000);
        Car xuv = new Car("Mahindra XUV", 950000, 7);

        System.out.println("\nCars:");

        System.out.println(car1);
        System.out.println(swift);
        System.out.println(xuv);
    }
}