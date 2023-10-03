package application;

public class Coin {
	int pos;
	Coin(int position) {
		pos=position;
	}
	
	boolean alive=true;
	public boolean isAlive() {
		return alive;
	}
	public void setAlive(boolean alive) {
		this.alive = alive;
	}
	
	boolean occupied=true;
	
}
