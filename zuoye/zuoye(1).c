// C++ code
//
#include <MsTimer2.h>
int pin1 = 8,
	pin2 = 9,
	pin3 = 10,
	pin4 = 11;
	
int wei1 = 6,wei2 = 7; //数码管位选
int key = 4; //按键接口
int num = 0; //计数值


//中断服务函数
void Tim_Serv()
{
  if(num>=99) num=0;
  else num++;
}


//一位数码管显示
void SMG_Disp1(int n)
{
  if(n<0||n>9) return;
  
  switch(n){
    case 0:
    	digitalWrite(pin1, LOW);
    	digitalWrite(pin2, LOW);
    	digitalWrite(pin3, LOW);
    	digitalWrite(pin4, LOW);
    	break;
    case 1:
    	digitalWrite(pin1, HIGH);
    	digitalWrite(pin2, LOW);
    	digitalWrite(pin3, LOW);
    	digitalWrite(pin4, LOW);
    	break;    	
    case 2:
    	digitalWrite(pin1, LOW);
    	digitalWrite(pin2, HIGH);
    	digitalWrite(pin3, LOW);
    	digitalWrite(pin4, LOW);
    	break;    
    case 3:
    	digitalWrite(pin1, HIGH);
    	digitalWrite(pin2, HIGH);
    	digitalWrite(pin3, LOW);
    	digitalWrite(pin4, LOW);
    	break;  
    case 4:
    	digitalWrite(pin1, LOW);
    	digitalWrite(pin2, LOW);
    	digitalWrite(pin3, HIGH);
    	digitalWrite(pin4, LOW);
    	break;
    case 5:
    	digitalWrite(pin1, HIGH);
    	digitalWrite(pin2, LOW);
    	digitalWrite(pin3, HIGH);
    	digitalWrite(pin4, LOW);
    	break;    
    case 6:
    	digitalWrite(pin1, LOW);
    	digitalWrite(pin2, HIGH);
    	digitalWrite(pin3, HIGH);
    	digitalWrite(pin4, LOW);
    	break;    
    case 7:
    	digitalWrite(pin1, HIGH);
    	digitalWrite(pin2, HIGH);
    	digitalWrite(pin3, HIGH);
    	digitalWrite(pin4, LOW);
    	break;    
    case 8:
    	digitalWrite(pin1, LOW);
    	digitalWrite(pin2, LOW);
    	digitalWrite(pin3, LOW);
    	digitalWrite(pin4, HIGH);
    	break;  
    case 9:
    	digitalWrite(pin1, HIGH);
    	digitalWrite(pin2, LOW);
    	digitalWrite(pin3, LOW);
    	digitalWrite(pin4, HIGH);
    	break;    
  }
}


//两位数码管显示
void SMG_Disp2(int num)
{
  int ge  = num%10,
  	  shi = num/10;
  
  //个位显示
  digitalWrite(wei1, LOW);//关闭锁存，写入数据
  SMG_Disp1(ge);
  digitalWrite(wei1, HIGH);//打开锁存，拒绝写入数据
  
  //十位显示
  digitalWrite(wei2, LOW);
  SMG_Disp1(shi);
  digitalWrite(wei2, HIGH);
}


//按键处理
void keyPro()
{
  if(digitalRead(key) == LOW){//按键按下
    
    delay(20); //消抖
    if(digitalRead(key) == LOW){//按键按下
      num = 0;
      
      while(!digitalRead(key));//松手检测
    }
    
  }
}


void setup()
{
  pinMode(key,INPUT_PULLUP); //上拉输入
  MsTimer2::set(1000,Tim_Serv);
  MsTimer2::start();
}

void loop()
{
  SMG_Disp2(num);
  delay(10);
  keyPro();
  delay(10);
  
}


