
#include <iostream>
#include <fstream>
using namespace std;
#include "shape.h"

//Default constructor for Shape makes it a square
Shape::Shape(){ 
	shape_type=SQUARE;
}

//Overloaded constructor for Shape makes it based on what shape type is passed through
Shape::Shape(Shape_Type x){
	
	shape_type= x;
}

//Prompts user to enter a positive number for the size of the square
void Shape::defineSize(){
	cout<<"Please enter a positive number between 0 and 20 \n";
	
	cin>>shape_size;
}

//Prompts user to enter whether the shape will be filled or have a hollow fill
void Shape::defineFill(){
	
	cout<<"Enter 1 for a solid fill, otherwise enter 0 for a hollow fill\n";
	cin>>isFilled;

}

//Accessor function to get provate shape_size variable of class Shape
int Shape::getSize(){
	return shape_size;

}

//Mutator function assigns user entered size of any shape type to shape_size private variable
int Shape::setSize(int x){
	shape_size= x;
}

//Uses nested for loop to print filled square
void Shape::printFilledShape(ofstream& out_stream){
	
	//Nested for loop to output * 
	for (int i=0; i< shape_size;i++){
		out_stream<<endl;
		for (int j=0; j< shape_size;j++){
			
			out_stream<<"*";
		}
	}
}	

void Shape::printHollowShape(ofstream& out_stream){
	//Checks for left and right ends off square 
	int left=0;
	int right=shape_size;
	
	for (int i=0; i< shape_size;i++){
		out_stream<<endl;
		for (int j=0; j< shape_size;j++){
			//Prints lie of astericks based on shape for top and bottom of square
			if(i==0||i== shape_size-1){
				out_stream<<"*";
			}
			//Based on left and right boundary prints the astericks on each side for hollow creation
			else if(i>0 && i<shape_size){
				if (j==0|| j==shape_size-1){
					out_stream<<"*";
				}
				else{
					out_stream<<" ";
				}
			}
			
		}
	}
}	

//Returns boolean value specifying whether shape is filled or not
bool Shape::getIsFilled(){
	return isFilled;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Prompts user to enter a positive number for the size of the square
void Square::defineSize(){
	int size=0;
	do{
		cout<<"Square \nPlease enter any number between 1 and 20\n";
		cin>>size;
		if (size>20 || size <0){
			cout<<"Invalid Value! Please enter another number\n";
		}
	}while(size>20||size<0);
	setSize(size);
}


//Uses nested for loop to print filled square
void Square::printFilledShape(ofstream& out_stream){
	int size=getSize();
	for (int i=0; i< size;i++){
		out_stream<<endl;
		for (int j=0; j< size;j++){
			
			out_stream<<"*";
		}
	}
}	

void Square::printHollowShape(ofstream& out_stream){
	//Checks for left and right ends off square 
	int left=0;
	int right=getSize();
	
	for (int i=0; i< right;i++){
		out_stream<<endl;
		for (int j=0; j< right;j++){
			//Prints lie of astericks based on shape for top and bottom of square
			if(i==0||i== right-1){
				out_stream<<"*";
			}
			//Based on left and right boundary prints the astericks on each side for hollow creation
			else if(i>0 && i<right){
				if (j==0|| j==right-1){
					out_stream<<"*";
				}
				else{
					out_stream<<" ";
				}
			}
			
		}
	}
}	


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Prompts user to enter size of Diamond shape 
void Diamond::defineSize(){
	int size=0;
	do{
		cout<<"Diamond\nPlease enter an odd value between 3 and 19\n";
		cin>>size;
		if(size%2==0 || size>19 || size <3){
			cout<<"Invalid number! Please enter another odd value";
		}
	}while(size%2==0);
	setSize(size); //Calls setSize to set private variable shape_size to temporary variabe size
	
}

void Diamond::printFilledShape(ofstream& out_stream){
	int counter=getSize(); //Counter for number of rows
	int End=0; //Last number of inputted counter
	int AsterickStart=0; //Boundary for the start of Asterick boundary
	int AsterickEnd=0; //Boundary for the end of Asterick boundary
	bool increase= true; //Boolean value for spaces 

	
	End= counter-1; //End is the largest number of astericks in the middle row
	AsterickStart=(End/2); //AsterickStart begins at the middle of the row
	AsterickEnd= (End/2); //AsterickEnd begins at the middle of the row
	
	//Nested for loop for calculating the amount of astericks outputted each row
	for (int i=1; i<counter+1;i++){
		out_stream<<endl;
		for (int j=0; j<counter;j++){
	
	    	if (j>=AsterickStart && j<=AsterickEnd ){ //If j value is in between Asterick boundaries, then output *
	    		out_stream<<"*";
			}	
			else{ //Otherwise a space is outputted
				out_stream<<" ";
			}
		}
		if(AsterickStart==0){ //Once the asterick start boundary equals 0, the boolean increase changes for spaces to decrease
			increase=false;
		}
		if (increase==true){ //If increase is true, the asterick boundaries will grow
			AsterickStart--;
			AsterickEnd ++;
		}
		else if(increase==false){ //If increase is false, the asterick boundaries will decrease
			AsterickStart++;
			AsterickEnd--;
		}
	}	
	
}

void Diamond::printHollowShape(ofstream& out_stream){
	int counter=getSize(); //Counter for number of rows
	int End=0; //Last number of inputted counter
	int AsterickStart=0; //Boundary for the start of Asterick boundary
	int AsterickEnd=0; //Boundary for the end of Asterick boundary
	bool increase= true; //Boolean value for spaces 

	
	End= counter-1; //End is the largest number of astericks in the middle row
	AsterickStart=(End/2); //AsterickStart begins at the middle of the row
	AsterickEnd= (End/2); //AsterickEnd begins at the middle of the row
	
	//Nested for loop for calculating the amount of astericks outputted each row
	for (int i=1; i<counter+1;i++){
		out_stream<<endl;
		for (int j=0; j<counter;j++){
	
	    	if (j==AsterickStart || j==AsterickEnd ){ //If j value is in equal to Asterick boundaries, then output *
	    		out_stream<<"*";
			}	
			else{ //Otherwise a space is outputted
				out_stream<<" ";
			}
		}
		if(AsterickStart==0){ //Once the asterick start boundary equals 0, the boolean increase changes for spaces to decrease
			increase=false;
		}
		if (increase==true){ //If increase is true, the asterick boundaries will grow
			AsterickStart--;
			AsterickEnd ++;
		}
		else if(increase==false){ //If increase is false, the asterick boundaries will decrease
			AsterickStart++;
			AsterickEnd--;
		}
	}	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Prompts user to enter odd value for Pyramid creation
void Pyramid::defineSize(){
	int size=0;
	do{
		cout<<"Pyramid\nPlease enter an odd value between 3 and 19\n";
		cin>>size;
		if(size%2==0 || size>19 || size <3){
			cout<<"Invalid number! Please enter another odd value";
		}
	}while(size%2==0);
	setSize(size);
	
}

//Uses previous logic for diamond except for loop only goes to half of diamond
void Pyramid::printFilledShape(ofstream& out_stream){
	int counter=getSize(); //Counter for number of rows
	int End=0; //Last number of inputted counter
	int AsterickStart=0; //Boundary for the start of Asterick boundary
	int AsterickEnd=0; //Boundary for the end of Asterick boundary
	bool increase= true; //Boolean value for spaces 

	
	End= counter-1; //End is the largest number of astericks in the middle row
	AsterickStart=(End/2); //AsterickStart begins at the middle of the row
	AsterickEnd= (End/2); //AsterickEnd begins at the middle of the row
	
	//Nested for loop for calculating the amount of astericks outputted each row
	for (int i=1; i<((counter+1)/2)+1;i++){
		out_stream<<endl;
		for (int j=0; j<counter;j++){
	
	    	if (j>=AsterickStart && j<=AsterickEnd ){ //If j value is in between Asterick boundaries, then output *
	    		out_stream<<"*";
			}	
			else{ //Otherwise a space is outputted
				out_stream<<" ";
			}
		}
			AsterickStart--;
			AsterickEnd ++;			
	}			
}

void Pyramid::printHollowShape(ofstream& out_stream){
	int counter=getSize(); //Counter for number of rows
	int End=0; //Last number of inputted counter
	int AsterickStart=0; //Boundary for the start of Asterick boundary
	int AsterickEnd=0; //Boundary for the end of Asterick boundary
	bool increase= true; //Boolean value for spaces 

	
	End= counter-1; //End is the largest number of astericks in the middle row
	AsterickStart=(End/2); //AsterickStart begins at the middle of the row
	AsterickEnd= (End/2); //AsterickEnd begins at the middle of the row
	
	//Nested for loop for calculating the amount of astericks outputted each row
	for (int i=1; i<((counter+1)/2)+1;i++){
		out_stream<<endl;
		for (int j=0; j<counter;j++){
			if (i==(counter+1)/2){
				out_stream<<"*";
			}
	    	else if (j==AsterickStart || j==AsterickEnd ){ //If j value is equal to asterick boundaries, then an asterick is outputted
	    		out_stream<<"*";
			}	
			else{ //Otherwise a space is outputted
				out_stream<<" ";
			}
		}
			AsterickStart--;
			AsterickEnd ++;			
	}	
		
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Prompts user to enter size of the Triangle for creation
void Triangle::defineSize(){
	int size=0;
	do{
		cout<<"Triange \nPlease enter any number between 1 and 20\n";
		cin>>size;
		if (size>20 || size <0){
			cout<<"Invalid Value! Please enter another number\n";
		}
	}while(size>20||size<0);
	
	setSize(size);
	
}

//Uses previous logic with modifications to create filled triangle
void Triangle::printFilledShape(ofstream& out_stream){
	int counter=getSize(); //Counter for number of rows
	int End=0; //Last number of inputted counter
	int AsterickStart=0; //Boundary for the start of Asterick boundary
	int AsterickEnd=0; //Boundary for the end of Asterick boundary
	bool increase= true; //Boolean value for spaces 

	
	End= counter-1; //End is the largest number of astericks in the middle row
	AsterickStart=End; //AsterickStart begins at the middle of the row
	AsterickEnd= End; //AsterickEnd begins at the middle of the row 
	
	//Nested for loop for calculating the amount of astericks outputted each row
	for (int i=1; i<counter+1;i++){
		out_stream<<endl;
		for (int j=0; j<counter;j++){
	
	    	if (j>=AsterickStart && j<=AsterickEnd ){ //If j value is in between Asterick boundaries, then output *
	    		out_stream<<"*";
			}	
			else{ //Otherwise a space is outputted
				out_stream<<" ";
			}
		}
			AsterickStart--; //AsterickStart boundary is decreasing to increase the amount of astericks printed each row
					
	}
}

//Uses previous logic with modifications to create hollowed triangle
void Triangle::printHollowShape(ofstream& out_stream){
	int counter=getSize(); //Counter for number of rows
	int AsterickStart=0; //Boundary for the start of Asterick boundary
	int AsterickEnd=0; //Boundary for the end of Asterick boundary
	bool increase= true; //Boolean value for spaces 
	int End=0; //Last number of inputted counter

	
	End= counter-1; //End is the largest number of astericks in the middle row
	AsterickStart=End; //AsterickStart begins at the middle of the row
	AsterickEnd= End; //AsterickEnd begins at the middle of the row
	
	//Nested for loop for calculating the amount of astericks outputted each row
	for (int i=1; i<counter+1;i++){
		out_stream<<endl;
		for (int j=0; j<counter;j++){
			if(i==counter){//If triangle is on the last row, output all astericks
				out_stream<<"*";
			}
			
	    	if ((j==AsterickStart || j==AsterickEnd) && i!=counter){ //If j value is in between Asterick boundaries, then output *
	    		out_stream<<"*";
			}
				
			else if (i!=counter){ //Otherwise a space is outputted
				out_stream<<" ";
			}
		}
			AsterickStart--;
					
	}
}
