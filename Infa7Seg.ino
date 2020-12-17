int port_segment[] = {2,3,4,5,6,7,8,9}; // Port ABCDEFG. 
int port_transistor[] = {A2,A3,A4,A5}; // Port Digit Selector Transistor

int NUMBER0[] = {1, 1, 1, 1, 1, 1, 0};
int NUMBER1[] = {0, 1, 1, 0, 0, 0, 0};
int NUMBER2[] = {1, 1, 0, 1, 1, 0, 1};
int NUMBER3[] = {1, 1, 1, 1, 0, 0, 1};
int NUMBER4[] = {0, 1, 1, 0, 0, 1, 1};
int NUMBER5[] = {1, 0, 1, 1, 0, 1, 1};
int NUMBER6[] = {1, 0, 1, 1, 1, 1, 1};
int NUMBER7[] = {1, 1, 1, 0, 0, 1, 0};
int NUMBER8[] = {1, 1, 1, 1, 1, 1, 1};
int NUMBER9[] = {1, 1, 1, 1, 0, 1, 1};

void segment_draw(int);
void segment_aim(int);
void segment_display(int);

void setup()
{
  Serial.begin(9600);

  pinMode(port_segment[0],OUTPUT);
  pinMode(port_segment[1],OUTPUT);
  pinMode(port_segment[2],OUTPUT);
  pinMode(port_segment[3],OUTPUT);
  pinMode(port_segment[4],OUTPUT);
  pinMode(port_segment[5],OUTPUT);
  pinMode(port_segment[6],OUTPUT);
  pinMode(port_segment[7],OUTPUT);

  pinMode(port_transistor[0],OUTPUT);
  pinMode(port_transistor[1],OUTPUT);
  pinMode(port_transistor[2],OUTPUT);
  pinMode(port_transistor[3],OUTPUT);

  pinMode(A0,INPUT);
}

bool closer;
int counter = 0;
void loop()
{
  

  segment_display(counter);
  
  if(!closer && analogRead(A0) < 500)
  {
    counter++;
    Serial.println(counter);
    closer = true;
  }
  else if(closer && analogRead(A0) > 500)
  {
    closer = false;
  }
}

void segment_display(int num)
{
  int a,b,c,d;
  int T = 5;
  a = (num/1000)%10;
  b = (num/100)%10;
  c = (num/10)%10;
  d = (num/1)%10;
  if(num < 10) //0 - 9
  {
    a = -1; b = -1 ; c = -1;
  }
  if(num < 100 && num >= 10) // 10 - 99
  {
    a = -1; b = -1 ;
  }
  if(num < 1000 && num >= 100) // 100 - 999
  {
    a = -1;
  }
  //Serial.println(a);
  //Serial.println(b);
  //Serial.println(c);
  //Serial.println(d);

  segment_aim(1);
  segment_draw(a);
  delay(T);
  segment_aim(2);
  segment_draw(b);
  delay(T);
  segment_aim(3);
  segment_draw(c);
  delay(T);
  segment_aim(4);
  segment_draw(d);
  delay(T);
  
}

void segment_aim(int num)
{
  switch(num)
  {
    case 99 : // Aim for all digit
    {
      for(int i = 0 ; i < 4 ; i++)
      {
        digitalWrite(port_transistor[i],HIGH);
      }
      break;
    }
    case 1 :
    {
      for(int i = 0 ;i < 4 ; i++)
      {
        digitalWrite(port_transistor[i],LOW);
      }
      digitalWrite(port_transistor[0],HIGH); 
      break;
    }
    case 2 :
    {
      for(int i = 0 ;i < 4 ; i++)
      {
        digitalWrite(port_transistor[i],LOW);
      }
      digitalWrite(port_transistor[1],HIGH); 
      break;
    }
    case 3 :
    {
      for(int i = 0 ;i < 4 ; i++)
      {
        digitalWrite(port_transistor[i],LOW);
      }
      digitalWrite(port_transistor[2],HIGH); 
      break;
    }
    case 4 :
    {
      for(int i = 0 ;i < 4 ; i++)
      {
        digitalWrite(port_transistor[i],LOW);
      }
      digitalWrite(port_transistor[3],HIGH); 
      break;
    }
  }
}

void segment_draw(int num)
{
  switch (num)
  {
    case -1 :
    {
      for(int i = 0 ; i < 7 ; i++)
      {
        digitalWrite(port_segment[i],LOW);
      }
      break;
    }
    case 0:
    {
      for(int i = 0; i< 7; i++)
      {
        digitalWrite(port_segment[i],NUMBER0[i]);
      }
    break;
    }

    case 1:
    {
      for(int i = 0; i< 7; i++)
      {
        digitalWrite(port_segment[i],NUMBER1[i]);
      }
    break;
    }

    case 2:
    {
      for(int i = 0; i< 7; i++)
      {
        digitalWrite(port_segment[i],NUMBER2[i]);
      }
    break;
    }

    case 3:
    {
      for(int i = 0; i< 7; i++)
      {
        digitalWrite(port_segment[i],NUMBER3[i]);
      }
    break;
    }

    case 4:
    {
      for(int i = 0; i< 7; i++)
      {
        digitalWrite(port_segment[i],NUMBER4[i]);
      }
    break;
    }

    case 5:
    {
      for(int i = 0; i< 7; i++)
      {
        digitalWrite(port_segment[i],NUMBER5[i]);
      }
    break;
    }

    case 6:
    {
      for(int i = 0; i< 7; i++)
      {
        digitalWrite(port_segment[i],NUMBER6[i]);
      }
    break;
    }

    case 7:
    {
      for(int i = 0; i< 7; i++)
      {
        digitalWrite(port_segment[i],NUMBER7[i]);
      }
    break;
    }

    case 8:
    {
      for(int i = 0; i< 7; i++)
      {
        digitalWrite(port_segment[i],NUMBER8[i]);
      }
    break;
    }

    case 9:
    {
      for(int i = 0; i< 7; i++)
      {
        digitalWrite(port_segment[i],NUMBER9[i]);
      }
    break;
    }
  }
}
    
