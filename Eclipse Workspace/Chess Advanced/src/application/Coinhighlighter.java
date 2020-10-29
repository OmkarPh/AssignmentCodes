package application;

import java.lang.reflect.Array;
import java.util.ArrayList;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;

public class Coinhighlighter {
boolean first=true;
//boolean second = false;

	@FXML
	Label a1,b1;
	ImageView j1,j2,j3,j4,j5,j6,j7,j8,j9,j10,j11,j12,j13,j14,j15,j16,j17,j18,j19,j20,j21,j22,j23,j24,j25,j26,j27,j28,j29,j30,j31,j32;
	ImageView j33,j34,j35,j36,j37,j38,j39,j40,j41,j42,j43,j44,j45,j46,j47,j48,j49,j50,j51,j52,j53,j54,j55,j56,j57,j58,j59,j60,j61,j62,j63,j64;
	String k2="knight";
	String k1="hook";
	String k3="bishop"
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
Image emp=new Image(getClass().getResourceAsStream(""));

public void highlight(MouseEvent event){
	event.consume();
	try {
if(first) {
	
	String pos=((Label)event.getSource()).getText(); // 1 or 2
	System.out.println(pos);
	((Label)event.getSource()).setStyle("-fx-border-color: red ; -fx-border-width: 2px ; ");
	availablePos(pos);
	first=false;
	
	}else if(!first) {
	
	String pos=((Label)event.getSource()).getText(); // 1 or 2
	System.out.println(pos);
	((Label)event.getSource()).setStyle("-fx-border-color: red ; -fx-border-width: 2px ; ");
	
	first=true;
}
	} catch (Exception e) {
        System.out.println("Error");
        e.printStackTrace();
    } 
}
public ImageView availablePos(String ps) {
	int pos=Integer.parseInt(ps);
	switch(ps) {
	case "1":
		pos(k1,pos);	
		break;
	case "2":
		pos(k2,pos);	
	break;
	}
return j1;
}
	

public void giveDef() {

}
public void pos(String type,int num) {
	System.out.println(type);
	int[] s;
	switch (type) {
	case "pawnW":
		s= knight(num);
		break;
	case "pawnB":
		
		break;
	case "knight":
		//int[] post= knight(num);
		s= knight(num);
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

//@SuppressWarnings("null")
public int[] knight(int num) {
	boolean more=true;
	 int[] res=new int[8];
		res[0]=num-10;
		res[1]=num+10;
		res[2]=num+6;
		res[3]=num-6;
		res[4]=num-17;
		res[5]=num+17;
		res[6]=num-15;
		res[7]=num+15;
		//System.out.println(res);
	return res;
}


public void change(String ps){
	
	
}
public void postm(int[] trg) {
	//Id i = Id.valueOf(trg[1]);
}
}
public void retImageLoc() {
	
}
public void temp() {

}
