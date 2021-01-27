import java.nio.file.*;
import java.nio.file.Paths;
import java.io.*;
public class exp6_2 {

    public static void main(String[] args) {
        try{
            Path source = Paths.get("E:\\test");
            Path target = Paths.get("E:\\test\\subtest");

            String fn1=source+"\\";
            String fn2=target+"\\";

            FileWriter myWriter = new FileWriter(fn1+"filename.txt");
            myWriter.write("Files in Java might be tricky, but it is fun enough!");
            myWriter.close();


            //copy
            InputStream is = null;
            OutputStream os = null;
            File s=new File(fn1+"filename.txt");
            File d=new File(fn2+"filename.txt");
            is = new FileInputStream(s);
            os = new FileOutputStream(d);
            byte[] buffer = new byte[1024];
            int length;
            while ((length = is.read(buffer)) > 0) {
                os.write(buffer, 0, length);
            }
            is.close();
            os.close();

            //move
            d.delete();
            Path temp = Files.move(Paths.get(fn1+"filename.txt"),  Paths.get(fn2+"filename.txt")); 

            //delete
            s.delete();

            //retrieve
            System.out.println(source+"");
            System.out.println(target+"");
            System.out.println(source.getParent()+"");
            System.out.println(target.getParent()+"");
            System.out.println(source.getRoot()+"");
            System.out.println(target.getRoot()+"");
        }catch(Exception ex){
            System.out.println(ex+"");
        }
    }
}