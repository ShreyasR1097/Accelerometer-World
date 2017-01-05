//connect 3.3v to AREF
//x to A5
//y to A4
//z to A3
//pin8 to the right LED
//pin9 to the top LED
//pin10 to the bottom LED
//pin12 to the left LED

const int ap1 = A5; 
const int ap2 = A4;
const int ap3 = A3;

int sv1 = 0;        
int ov1 = 0;    
int sv2 = 0;      
int ov2= 0;      
int sv3 = 0;       
int ov3= 0;      

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(12,OUTPUT);
}

void loop() {
  analogReference(EXTERNAL);    //connect 3.3v to AREF
  
  sv1 = analogRead(ap1);   // read the analog in value:         
  ov1 = map(sv1, 0, 1023, 0, 255);  // map it to the range of the analog out:
  delay(2);                     
  
  sv2 = analogRead(ap2);            
  ov2 = map(sv2, 0, 1023, 0, 255); 
  delay(2);                 
  
  sv3 = analogRead(ap3);            
  ov3 = map(sv3, 0, 1023, 0, 255);  
  
                      
//This part is if you hook up 4 LEDs to represent the 4 cardinal
// direcions and to have the corresponding LED light up according
// to how you tilt the accelerometer (depends only on x and y)
/*  
  if(ov1>130){ //left LED,x, left and right
    digitalWrite(12,HIGH); digitalWrite(8,LOW);}
  else if(ov1<120){ //right LED
    digitalWrite(8,HIGH); digitalWrite(12,LOW);}
  else{
    digitalWrite(12,LOW);digitalWrite(8,LOW);}
    
  if(ov2>130){ //Bottom LED ,y
    digitalWrite(10,HIGH); digitalWrite(9,LOW);}
  else if(ov2<120){ //top LED
    digitalWrite(9,HIGH); digitalWrite(10,LOW);}
  else{
    digitalWrite(9,LOW);digitalWrite(10,LOW);}*/

//Sending the values to serial, seperated by commas
  Serial.print(ov1);  //x
  Serial.print(",");     
  Serial.print(ov2);  //y
  Serial.print(",");  
  Serial.println(ov3);   //z
  delay(500);                     
  
}
