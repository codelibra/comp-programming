// iHaala Madrid - A Gunner
#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

class Board public Square{
	private:
	int dimension;
	Square BoardMatrix[dimension][dimension];
	
	public:
	//Returns if the current configuration is a Checkmate 
	bool IsCheckmate();
	
	//Returns if the current configuration is a Check
	bool IsCheck(int player);
	
	//Returns if the current configuration is a Stalemate 
	bool IsStalemate();
	
	//Will contain similar board confiration methods
	//...
};

class Piece(){
	private:
	bool isWhite;
	bool isBlack;
	int pieceType;
	
	public:
	
	Piece(int type,bool iswhite){
		pieceType=type;
		isWhite=iswhite;
		isBlack=!iswhite;
	}
	
	bool isValidMove(int cur_x,int cur_y,int final_x,int final_y);
	
	bool makeMove(int cur_x,int cur_y,int final_x,int final_y);
	
	
};

class Square public Piece{
	private:
	int x_coord;
	int y_coord;
	Piece contains;
	
	public:
	
	Square(Piece type){
		contains = type;
	}
	
	bool isOccupied();
	
	Piece occupiedBy();
};

class Player public Board{
	private:
	bool whitePlayer;
	bool blackPlayer;
	
	public:
	
	Player(bool type){
		whitePlayer=type;
		blackPlayer=!type;
	}
	
	void MakeMove(Square current,Square Final);
	
};


int main(){
	
	return 0;	
}