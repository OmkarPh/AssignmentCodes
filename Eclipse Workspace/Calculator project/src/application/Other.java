package application;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TreeItem;
import javafx.scene.control.TreeView;

public class Other implements Initializable {
	
	@FXML
	TreeView<String> Friend;
	
	
	@Override
	public void initialize(URL arg0, ResourceBundle arg1) {
		TreeItem <String> root= new TreeItem<>("Friends");
		
		TreeItem <String> ankush= new TreeItem<>("ankush");
		TreeItem <String> devesh= new TreeItem<>("devesh");
		TreeItem <String> vinayak= new TreeItem<>("vinayak");
		TreeItem <String> omkar= new TreeItem<>("omkar");
		
		root.getChildren().addAll(ankush,devesh,vinayak,omkar);
		
		Friend.setRoot(root);
	}

}
