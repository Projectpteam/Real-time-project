
#include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const byte degreeSymbol = "B11011111" ; 


int input_1 =A1;
int input_4=A4;
int reading_1;
int reading_4;
float tem_1 ;
float tem_4 ;

float max_tem =0 ;

void setup() {
  lcd.begin(16,2);
 pinMode (input_1 , INPUT);
 
 pinMode (input_4 , INPUT);
 

}

void loop() {
  reading_1 = analogRead(input_1);
  reading_4 = analogRead(input_4); 
  tem_1=(reading_1 *(5.0/1024)*100) -2.5 ; 
  tem_4=(reading_4 *(5.0/1024)*100) -2.5 ;
  if (tem_1 > tem_4)
  { max_tem = tem_1 ; }
  else
  { max_tem= tem_4 ; }
  
  
   
   
   
   lcd.setCursor(0,0);
   lcd.print("Max temp =");
   lcd.setCursor(0,1);
   lcd.print(max_tem,DEC);
   lcd.print(degreeSymbol);
   lcd.print("c");
   delay(1000);
  
  

}
