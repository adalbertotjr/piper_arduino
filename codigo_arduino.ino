typedef union
{
  float number;
  uint8_t bytes[4];
} 

FLOATUNION_t;

FLOATUNION_t myValue1;
FLOATUNION_t myValue2;

FLOATUNION_t send1;
FLOATUNION_t send2; 

void setup() 
{
  Serial.begin(115200);
}

void loop()
{
  myValue1.number = getFloat();
  myValue2.number = getFloat(); 

  send1.number = ((((-0.0907*myValue1.number) + 0.0905))/((myValue1.number - 1)));  
  send2.number = ((((myValue2.number) - 1))/((myValue2.number - 0.99)));  
  
  Serial.write('A'); 
  
  for (int i=0; i<4; i++)
  { 
    Serial.write(send1.bytes[i]); 
  }
 
  for (int i=0; i<4; i++)
  {
    Serial.write(send2.bytes[i]); 
  }
    
  Serial.print('\n'); 
  
  delay(50);
}

float getFloat()
{
    int cont = 0;
    FLOATUNION_t f;
    while (cont < 4 )
    {
        f.bytes[cont] = Serial.read() ;
        cont = cont +1;
    }
    return f.number;
}
