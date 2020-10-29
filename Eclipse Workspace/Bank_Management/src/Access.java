import java.util.*;
import java.lang.reflect.*;
import java.sql.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.File;
import java.fx.*;
public class Access
{
	public static void main(String[] args)
	{

		try{
			File file = new File("All");
			if(!file.exists()){
				file.createNewFile();
			}
			PrintWriter pw= new PrintWriter(file);
			pw.println("hfjdj");
			pw.println("isoshdh");
			pw.println("akdnbdhfh");
			pw.close();
			System.out.println("There isn't any error");
		}catch(IOException a){	}
		System.out.println("There isn't any error");
		}




	int employee_no(){
		return 0;
	}
	int customer_no(){


		return 0;
	}

}
