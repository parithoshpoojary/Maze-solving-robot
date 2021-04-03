//dfws
const int irpin1 = 8;
const int irpin2 = 9;
const int trigPin = 10; 
const int echoPin = 11;
uint32_t period = 0.04 * 80000L;

int irRead1 = HIGH;
int irRead2 = HIGH;

const int mtr_R1 = 2;
const int mtr_R2 = 3;
const int mtr_L1 = 4;
const int mtr_L2 = 5;

String initial = String("");
String solved = String("");
//dfws_end
 
boolean black_flag = true;
boolean end_flag = false;
boolean sbflag = false;
int nblack = -1;
 
void setup() 
  {
    pinMode(irpin1, INPUT);
    pinMode(irpin2, INPUT);
    pinMode(mtr_R1, OUTPUT);
    pinMode(mtr_R2, OUTPUT);
    pinMode(mtr_L1, OUTPUT);
    pinMode(mtr_L2, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
  }

//dfws
void right() 
  {
    digitalWrite(mtr_L1, LOW);
    digitalWrite(mtr_L2, HIGH);
    digitalWrite(mtr_R1, LOW);
    digitalWrite(mtr_R2, LOW);
  }

void left() 
  {
    digitalWrite(mtr_R1, HIGH);
    digitalWrite(mtr_R2, LOW);
    digitalWrite(mtr_L1, LOW);
    digitalWrite(mtr_L2, LOW);
  }

void forward() 
  {
    digitalWrite(mtr_R1, HIGH);
    digitalWrite(mtr_R2, LOW);
    digitalWrite(mtr_L1, LOW);
    digitalWrite(mtr_L2, HIGH);
  }

void reverse() 
  {
    digitalWrite(mtr_R1, HIGH);
    digitalWrite(mtr_R2, LOW);
    digitalWrite(mtr_L1, HIGH);
    digitalWrite(mtr_L2, LOW);
  }

void halt() 
  {
    digitalWrite(mtr_R1, LOW);
    digitalWrite(mtr_R2, LOW);
    digitalWrite(mtr_L1, LOW);
    digitalWrite(mtr_L2, LOW);
  }
//dfws_end

void loop() 
  {
    Serial.println(initial);
    Serial.println(solved);
    
    //ultrasonic segment
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    //ultrasonic end
    
    irRead1 = digitalRead(irpin1);
    irRead2 = digitalRead(irpin2);
    
    //solved segment begin
    if(end_flag) 
    {
      //Algorithm begin
      String temp = String("");
      int right_lnum=0;
      int left_lnum=0;
      temp = initial.substring(0,initial.length()-1);
      for(int i = temp.length()-1; i>=0; i--)       //LLBLBLL
      {       
        if(right_lnum=0) 
        {
          if(temp.charAt(i)=='B') 
          {
            right_lnum = temp.length()-1-i;
          }
        }
        if(left_lnum!=right_lnum) 
        {
          i--;
          if(temp.charAt(i)=='L') 
          {
            left_lnum+=1;
          }
          if(temp.charAt(i)=='B') 
          {
            left_lnum=0;
          }
        }
        else 
        {
          solved.concat("R");
          right_lnum=0;
        }
      }
      //Algorithm end

      if (irRead1==HIGH && irRead2==HIGH) 
      {
        if(distance<15) 
        {
          halt();
          delay(2000);
          for(int i = 0; i<4; i++) 
          {
            for (uint32_t tStart = millis(); (millis()-tStart)<period; ) 
            {
              reverse();
            }
          }
          while(true) 
          {
            halt();
          }
        }
        if(solved.substring(nblack,nblack+1)=="R")
          {
              right();
          }
        else 
          {
              left();
          }
        if(sbflag) 
          {
            nblack+=1;
            sbflag = false; 
          }
      }
        if (irRead1==LOW && irRead2==HIGH) 
        {
          left();
        }
        if (irRead1==HIGH && irRead2==LOW) 
        {
          right();
        }
        if (irRead1==LOW && irRead2==LOW) 
        {
          forward();
          sbflag = true;
        }
    }
    //solved segment end

    //unsolved segment begin
    if(!end_flag) 
    {
      if (irRead1==LOW && irRead2==LOW) 
      {
        black_flag = true;
        if(distance>=15) 
        {
          forward();
        }
        else 
        {
          initial.concat("B");
          for (uint32_t tStart = millis(); (millis()-tStart)<period; ) 
          {
            reverse();
          }
        }
      }
      if (irRead1==LOW && irRead2==HIGH) 
      {
        left();
      }
      if (irRead1==HIGH && irRead2==LOW) 
      {
        right();
      }
      if (irRead1==HIGH && irRead2==HIGH) 
      {
        if(distance<15) 
        {
          end_flag = true;
          halt();
          delay(10000);
        }
        else 
        {
          if(black_flag) 
          {
            initial.concat("L");
            black_flag = false;
          }
          left();
        }
      }
    }
    //unsolved segment end
  }
