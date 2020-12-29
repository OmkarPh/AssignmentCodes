import java.util.*;
import java.io.*;

public class csv6{
    public static void main(String[] args) {

        String dataFilePath = "ndata.csv";
        String defaultData = "200,500,25,50\n100,50,25\n70,30,40,60\n40\n60,90,150\n20,40";
        Scanner inputScanner = new Scanner(System.in);
        char opted;

        File dataFile = new File(dataFilePath);
        
        // If file doesn't exist, creating one and writing default data to the file 
        if(!dataFile.exists()){
            System.out.println("CSV file could not be found, hence creating one !\nYou can put desired data in the file manually separated by commas");
            try {
                if (dataFile.createNewFile()){
                    System.out.println("File created: " + dataFile.getAbsolutePath());
                    FileWriter defauFileWriter = new FileWriter(dataFile.getName());
                    defauFileWriter.write(defaultData);
                    defauFileWriter.close();
                }else
                    System.out.println("There was a problem creating new file, try creating one manually");

            }catch (Exception e) {
                System.out.println("An error occurred while writing default data to the file, try writing manually :)");
                e.printStackTrace();
            }
        } 
        


        // Part1. Find sum of all numbers in csv file
        double sum = 0;
        List<Double> numbers = new ArrayList<>();
        try{
            Scanner csvScanner = new Scanner(dataFile);
            Scanner dataScanner = null;
            while (csvScanner.hasNextLine()) {
                dataScanner = new Scanner(csvScanner.nextLine());
                dataScanner.useDelimiter(",");
                
                while (dataScanner.hasNext()) {
                    try{
                        String data = dataScanner.next().trim();
                        numbers.add(Double.parseDouble(data));
                        sum += Double.parseDouble(data);
                    }catch(NumberFormatException ne){
                        continue;
                    }
                }
                dataScanner.close();
            }
            csvScanner.close();
        }catch(Exception e){
            System.out.println(e);
            e.printStackTrace();
        }
        System.out.println("All numbers in CSV file:\n"+numbers.toString());
        System.out.println("Sum of all numbers in CSV file: "+sum);


        
        // Part2. Write custom numbers to csv file
        System.out.print("Do you want to write numbers to csv file? y/n: ");
        opted = inputScanner.nextLine().trim().charAt(0);
        if(opted=='y' || opted=='Y'){
            int n;
            double entity;
            System.out.println("How many decimal numbers do you wish to write to file(eg. 4 or 8): ");
            n = inputScanner.nextInt();
            System.out.println("Enter the numbers separated by spaces:");
            List<Double> newData = new ArrayList<>();
            while(n-- > 0){
                entity = inputScanner.nextDouble();
                newData.add(entity);
            }
            String data = newData.toString();
            data = data.substring(1, data.length()-1);
            System.out.println(data);
            
            try {
                FileWriter customWriter = new FileWriter(dataFile.getName());
                customWriter.write(data);
                customWriter.close();
                System.out.println("Your changes are succesfuly written to file: " + dataFile.getAbsolutePath());
            }catch (Exception e) {
                System.out.println("Some issues occurred while writing data to the file, try writing manually :)");
                e.printStackTrace();
            }

        }


        // Part3. Modify data


        inputScanner.close();
    }
}