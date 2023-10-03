package application;
//import java.sql.*;
//import java.io.File;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.stage.Stage;
import javafx.scene.Parent;
import javafx.scene.Scene;

public class Main extends Application {
	@Override
	public void start(Stage primaryStage) {
		try {
			/*File userpass=new File ("Userpass");
			if(!userpass.exists()) {
				userpass.createNewFile();
				System.out.println("Hicreate");
			}else if (userpass.exists()) {
				System.out.println("Hi");
			}
			Parent	oth=FXMLLoader.load(getClass().getClassLoader().getResource("application/resource/Other.fxml"));
			Scene othsc = new Scene(oth,660,547);
			othsc.getStylesheets().add(getClass().getResource("/application2.css").toExternalForm());
			primaryStage.setScene(othsc);
			primaryStage.setTitle("Login Screen");
			primaryStage.show();
			*/
			
			Parent loginparent=FXMLLoader.load(getClass().getClassLoader().getResource("application/Login.fxml"));
			Scene loginscene = new Scene(loginparent,660,547);
			//loginscene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
			primaryStage.setScene(loginscene);
			primaryStage.setTitle("Login Screen");
			primaryStage.show();

		
			/*	Calc screen
			Parent root = FXMLLoader.load(getClass().getResource("/application/St.fxml"));
			Scene scene = new Scene(root,660,547);
			scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
			primaryStage.setTitle("Calculator");
			primaryStage.setScene(scene);
			primaryStage.show();*/
		/*	Create User screen
			Parent root = FXMLLoader.load(getClass().getResource("/application/new_user.fxml"));
			Scene scene = new Scene(root,660,547);
			scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
			primaryStage.setTitle("Calculator");
			primaryStage.setScene(scene);
			primaryStage.show();*/
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		/*
		try {
			Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
			
			String msAccessDBName = "C:\\Users\\Owner\\Documents\\UsernameAndPassword.accdb";
			String dbURL = "jdbc:ucanaccess://"
                    + msAccessDBName;
			Connection con=DriverManager.getConnection(dbURL);
			Statement st=con.createStatement();
			ResultSet rs=st.executeQuery("select * from Login");
	while(rs.next()) {
	String id=rs.getString("ID");
	String user=rs.getString("Username");
	String pass=rs.getString("Alternative Password");
	System.out.println(id+user+pass);	
}
	con.close();
	}catch(Exception e) {
	System.out.println(e.getMessage());
}
		*/
		launch(args);
	}
}
