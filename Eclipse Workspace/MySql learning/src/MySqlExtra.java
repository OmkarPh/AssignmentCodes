import java.sql.*;

public class MySqlExtra {
	
	private Connection con;
	private Statement st;
	private ResultSet rst;
	
	public  MySqlExtra() {
		try {
		//	Class.forName("com.mysql.jdbc.Driver");
		//	DriverManager.registerDriver(new com.mysql.jdbc.Driver());
				System.out.println("In the middle");
			con= DriverManager.getConnection("jdbc:mysql//localhost:3306/test","root","");
		
			st= con.createStatement();
			System.out.println("After creation");
		} catch(Exception e) {
			System.out.println("Error is " + e);
		}
			}
	public void getdata(){
		try {
			String query = "select * from persons";
			rst= st.executeQuery(query);
			System.out.println("Records from database");
			while(rst.next()) {
				String name = rst.getString("name");
				String age = rst.getString("age");
				System.out.println("Name: "+name+" & Age: "+age);
			}
		} catch(Exception e) {
			System.out.println("Error is " + e);
		}
	}
		
	
	
}
