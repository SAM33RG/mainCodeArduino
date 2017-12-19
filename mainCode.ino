


#define R1 8
#define ON 1
#define OFF 0
#define R2 9




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

}

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 

    Serial.println(command);
    
    switch(command){
    case 'F':  
      relay(ON,R1);
      break;
    case 'B':  
      relay(OFF,R1);
      break;
    }
  } 
}

