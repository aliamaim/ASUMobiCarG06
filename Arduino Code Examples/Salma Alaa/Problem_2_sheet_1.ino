int i =0;
void setup() 
{ 
pinMode ( 4,OUTPUT);
pinMode ( 5,OUTPUT);
pinMode ( 6,OUTPUT);
pinMode ( 7,OUTPUT);
}

void loop()
{
  if (i==0)
  { 
  digitalWrite(4, HIGH);  
  delay(1000);                      
  digitalWrite(4, LOW);  
  delay(1000); 
  
  digitalWrite(5, HIGH);   
  delay(1000);                      
  digitalWrite(5, LOW);    
  delay(1000);  
  
   digitalWrite(6, HIGH);   
  delay(1000);                     
  digitalWrite(6, LOW);   
  delay(1000); 
   
   digitalWrite(7, HIGH);   
  delay(1000);                      
  digitalWrite(7, LOW);    
  delay(1000);
    digitalWrite(7, HIGH);  
  delay(1000);                      
  digitalWrite(7, LOW);  
  delay(1000); 
  
  digitalWrite(6, HIGH);   
  delay(1000);                      
  digitalWrite(6, LOW);    
  delay(1000);
  
  digitalWrite(5, HIGH);   
  delay(1000);                     
  digitalWrite(5, LOW);   
  delay(1000);  
  
  digitalWrite(4, HIGH);   
  delay(1000);                      
  digitalWrite(4, LOW);    
  delay(1000); 
  }
 
  
}
