package application;
import javafx.scene.control.Label;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
public class Controller {
	@FXML
	ImageView j1,j2,j3,j4,j5,j6,j7,j8,j9,j10,j11,j12,j13,j14,j15,j16,j17,j18,j19,j20,j21,j22,j23,j24,j25,j26,j27,j28,j29,j30,j31,j32;
	ImageView j33,j34,j35,j36,j37,j38,j39,j40,j41,j42,j43,j44,j45,j46,j47,j48,j49,j50,j51,j52,j53,j54,j55,j56,j57,j58,j59,j60,j61,j62,j63,j64;
Image hookW= new Image(getClass().getResourceAsStream("/application/hookW.png"));
Image hookB = new Image(getClass().getResourceAsStream("/application/hookB.png"));
Image pawnW= new Image(getClass().getResourceAsStream("/application/pawnW.png"));
Image pawnB= new Image(getClass().getResourceAsStream("/application/pawnB.png"));
Image kingB= new Image(getClass().getResourceAsStream("/application/kingB.png"));
Image kingW= new Image(getClass().getResourceAsStream("/application/kingW.png"));
Image bishopW= new Image(getClass().getResourceAsStream("/application/bishopW.png"));
Image bishopB= new Image(getClass().getResourceAsStream("/application/bishopB.png"));
Image queenW= new Image(getClass().getResourceAsStream("/application/queenW.png"));
Image queenB= new Image(getClass().getResourceAsStream("/application/queenB.png"));
Image knightW= new Image(getClass().getResourceAsStream("/application/knightW.png"));
Image knightB =new Image(getClass().getResourceAsStream("/application/knightB.png"));


public void highlight(ActionEvent eventdonetome){
	j1.setImage(hookW);
}
public void availablePos() {

}
	

public void giveDef(Label lb) {

}
public void pos(String type,int num) {
	switch (type) {
	case "pawnW":
		
		break;
	case "pawnB":
		
		break;
	case "knight":
		knight(num);
		break;
	case "king":
		
		break;
	case "bishop":
		
		break;
	case "hook":
		
		break;
	case "queen":
		
		break;
	case "":
		System.out.println("error");
		break;
	}
}

public int[] knight(int num) {
	int[]res = null;
	
	return res;
}
}




