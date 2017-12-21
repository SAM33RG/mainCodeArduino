


#define R1 8
#define ON 1
#define OFF 0
#define R2 10




void relay ( int mode , int pin)
{
  switch(mode)
  {
    case OFF:
      digitalWrite(pin,HIGH);
      break;
    case ON:
    digitalWrite(pin,LOW);
      break;   
  }
}

char command; 

void setup() 
{       
  Serial.begin(9600);  
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);

}

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 

    Serial.println(command);
    
    switch(command){
    case '1':  
      relay(ON,R1);
      break;
    case '2':  
      relay(OFF,R1);
      break;
    case '3':  
      relay(ON,R2);
      break;
    case '4':  
      relay(OFF,R2);
      break;
    }
  } 
}

