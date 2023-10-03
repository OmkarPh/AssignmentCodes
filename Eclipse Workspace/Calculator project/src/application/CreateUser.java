package application;

import java.io.IOException;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.stage.Stage;

public class CreateUser {
	@FXML
	Label awb;
	public void logininstead() throws IOException {
		Stage primaryStage =new Stage();
		Parent loginparent=FXMLLoader.load(getClass().getClassLoader().getResource("application/Login.fxml"));
		Scene loginscene = new Scene(loginparent,660,547);
		loginscene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
		primaryStage.setScene(loginscene);
		primaryStage.setTitle("Login Screen");
		primaryStage.show();
		awb.getScene().getWindow().hide();
	}
	public void create() {
		
	}
	public void checkpass() {
		
	}
	public void anonymous() {
		
	}
	public void checkuser() {
		
	}
}
