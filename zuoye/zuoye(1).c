// C++ code
//
#include <MsTimer2.h>
int pin1 = 8,
	pin2 = 9,
	pin3 = 10,
	pin4 = 11;
	
int wei1 = 6,wei2 = 7; //�����λѡ
int key = 4; //�����ӿ�
int num = 0; //����ֵ


//�жϷ�����
void Tim_Serv()
{
  if(num>=99) num=0;
  else num++;
}


//һλ�������ʾ
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


//��λ�������ʾ
void SMG_Disp2(int num)
{
  int ge  = num%10,
  	  shi = num/10;
  
  //��λ��ʾ
  digitalWrite(wei1, LOW);//�ر����棬д������
  SMG_Disp1(ge);
  digitalWrite(wei1, HIGH);//�����棬�ܾ�д������
  
  //ʮλ��ʾ
  digitalWrite(wei2, LOW);
  SMG_Disp1(shi);
  digitalWrite(wei2, HIGH);
}


//��������
void keyPro()
{
  if(digitalRead(key) == LOW){//��������
    
    delay(20); //����
    if(digitalRead(key) == LOW){//��������
      num = 0;
      
      while(!digitalRead(key));//���ּ��
    }
    
  }
}


void setup()
{
  pinMode(key,INPUT_PULLUP); //��������
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


