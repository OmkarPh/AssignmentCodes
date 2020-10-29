package application;
import javafx.scene.control.Label;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
public class Controller {
	@FXML
	Label display;
	double result,num1,num2;
	String num1s="";
	String num2s="";
	boolean num1p=true;
	boolean recur=false;
	boolean repeat=false;
	String opr;
	double dis;
	String dispre;
	
	
	
	public void numentered(ActionEvent eventdonetome) {
		
		if (num1p) {
		num1s=num1s+((Button)eventdonetome.getSource()).getText();
		display.setText(num1s);
		}else if(!num1p) {
			display.setText(display.getText()+((Button)eventdonetome.getSource()).getText());
			num2s=num2s+((Button)eventdonetome.getSource()).getText();
		}
		
	
	}
	@FXML
	public void oprentered(ActionEvent eventdonetoop) {
		if (repeat) {
			if(recur) {
			}else if(!recur) {
				num1=dis;
				num1p=false;
				display.setText(num1+((Button)eventdonetoop.getSource()).getText());
				num2s=num1s="";
				opr=((Button)eventdonetoop.getSource()).getText();
			}
		}else {
			if(display.getText()!= "") {
			num1=Double.parseDouble(num1s);
			display.setText(num1s+((Button)eventdonetoop.getSource()).getText());
			num1p=false;
			opr=((Button)eventdonetoop.getSource()).getText();
			}
		}
		
	}
	
	public void equals(ActionEvent eventdonetome7) {
		num2=Double.parseDouble(num2s);
		double num2o = num2;
		if(num2o != 0) {
	    num2=Double.parseDouble(num2s);
		dis=calculate(num1,num2,opr);
		display.setText(String.valueOf(dis));
		repeat=true;
		}
		
	}
	public void clearlast() {
		dispre=display.getText();
		display.setText(dispre.substring(0,dispre.length()-1));
	}
	public double calculate(double number1,double number2, String opr) {
		switch(opr) {
		case "+":
			result = number1+number2;
			break;
		case "-":
			result = number1-number2;
			break;
		case "/":
			result = number1/number2;
			break;
		case "*":
			result=number1*number2;
			break;
		}
		return result;
	}
	@FXML
	public void clear() {
		display.setText("");
		double result=0,num1=0,num2=0,dis=0;
		num1s="";
		num2s="";
		num1p=true;
		repeat=false;
		recur=false;
		opr="";
		dispre="";
	}
	public void pos(String type,int num) {
		switch (type) {
		case "pawnA":
			break;
		case "pawnB":
			break;
		case "knight":
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
			
			break;
		}
	}
}
