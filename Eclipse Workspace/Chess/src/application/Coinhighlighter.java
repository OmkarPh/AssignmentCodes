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
BlackHook bh1=new BlackHook(64);
BlackHook bh2=new BlackHook(56);
Coin board[] =  new Coin[65];
int i=1;

public void highlight(MouseEvent event){
	event.consume();
	try {
if(first) {
	String abc=((Label)event.getSource()).getId();
	Object def=abc;
	System.out.println(def);
	
	
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
		break;
	case "2":
	break;
	}
return null;
}
	

public void giveDef() {

}
public void pos(String type,int num) {
	System.out.println(type);
	
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
}}