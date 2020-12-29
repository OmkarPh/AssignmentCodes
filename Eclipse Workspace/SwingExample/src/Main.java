import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.*; 
import java.awt.event.*; 

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		JFrame frame = new JFrame("MouseEvent listener JFrame");
        frame.setSize(550, 200);  
        frame.setLocationRelativeTo(null);  
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        final JLabel descLable = new JLabel("Mouse clicked at following coordinates in JFrame:");
        descLable.setFont(new Font("Comic Sans MS", Font.BOLD, 20));  
        
        final JLabel mouseCordinateLabel = new JLabel("x: 0.0, y:0.0");  
        mouseCordinateLabel.setFont(new Font("Serif", Font.PLAIN, 25));  
        
        frame.setLayout(new FlowLayout()); 
		frame.add(descLable);  
        frame.add(mouseCordinateLabel);  
	    frame.addMouseListener(new MouseAdapter(){
	          public void mouseClicked(MouseEvent e) {
	        	  mouseCordinateLabel.setText("x: " + e.getX() + ",   y:" + e.getY());
	          }                
	       }); 
        frame.setVisible(true);
	}

}
