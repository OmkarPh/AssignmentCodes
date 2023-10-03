package application;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.stage.Stage;

public class Login implements Initializable{
	
	@FXML
	public ComboBox<String> username;
	@FXML
	Label status;
	ObservableList<String> list = FXCollections.observableArrayList("Ankush","Omkar","Devesh","Vinayak");
	@FXML
	private PasswordField pass;
	Button submit;
	
	@Override
	public void initialize(URL arg0, ResourceBundle arg1) {
		
		System.out.println(list);
		username.setItems(list);
		
		
			
	}

public void validate() throws Exception{
	try{
	//System.out.println(username.getValue());
	
	//String passwordtxt=password.getText();
	//System.out.println(usernametxt+passwordtxt);
	switch (username.getValue()) {
	case  "Omkar":
	if(pass.getText().equals("omkar")){
		System.out.println("correct");
		Stage primaryStage =new Stage();
		Parent root = FXMLLoader.load(getClass().getResource("/application/St.fxml"));
		Scene scene = new Scene(root,660,547);
		primaryStage.setTitle("Welcome to Calculator Omkar");
		primaryStage.setScene(scene);
		primaryStage.show();
		status.getScene().getWindow().hide();
		}
	else {
		status.setText("The password is incorrect");
		System.out.println("Incorrect");
	}
	//passstatus.setText("The password is incorrect");
	break;
	case  "Ankush":
		if(pass.getText().equals("ankush")){
			System.out.println("correct");
			Stage primaryStage =new Stage();
			Parent root = FXMLLoader.load(getClass().getResource("/application/St.fxml"));
			Scene scene = new Scene(root,660,547);
			primaryStage.setTitle("Welcome to Calculator Ankush");
			primaryStage.setScene(scene);
			primaryStage.show();
			status.getScene().getWindow().hide();
			}
		else {
			status.setText("The password is incorrect");
			System.out.println("Incorrect");
		}
	break;
	case  "Devesh":
		if(pass.getText().equals("pratiksha")){  //<--- This is the password
			System.out.println("correct");
			Stage primaryStage =new Stage();
			Parent root = FXMLLoader.load(getClass().getResource("/application/St.fxml"));
			Scene scene = new Scene(root,660,547);
			primaryStage.setTitle("Welcome to Calculator Devesh");
			primaryStage.setScene(scene);
			primaryStage.show();
			status.getScene().getWindow().hide();
			}
		else {
			status.setText("The password is incorrect");
			System.out.println("Incorrect");
		}
	break;	
	case  "Vinayak":
		if(pass.getText().equals("pol")){    //<--- This is the password
			System.out.println("correct");
			Stage primaryStage =new Stage();
			Parent root = FXMLLoader.load(getClass().getResource("/application/St.fxml"));
			Scene scene = new Scene(root,660,547);
			primaryStage.setTitle("Welcome to Calculator Vinayak");
			primaryStage.setScene(scene);
			primaryStage.show();
			status.getScene().getWindow().hide();
			}
		else {
			status.setText("The password is incorrect");
			System.out.println("Incorrect");
		}
	break;
	}
	} catch(AssertionError e){
	 } catch(Exception e){
	 
	 }
}
public void newuser() throws IOException {
	Stage primaryStage =new Stage();
	Parent root = FXMLLoader.load(getClass().getResource("/application/new_user.fxml"));
	Scene scene = new Scene(root,660,547);
	scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
	primaryStage.setTitle("Create account");
	primaryStage.setScene(scene);
	primaryStage.show();
	status.getScene().getWindow().hide();
}
public void guest() throws IOException {
	Stage primaryStage =new Stage();
	Parent root = FXMLLoader.load(getClass().getResource("/application/St.fxml"));
	Scene scene = new Scene(root,660,547);
	primaryStage.setTitle("Welcome to Calculator");
	primaryStage.setScene(scene);
	primaryStage.show();
	status.getScene().getWindow().hide();
}
}
