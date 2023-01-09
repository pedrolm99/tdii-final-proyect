#include <stdio.h>
#include <wiringPi.h>

int LEDS [7] = {5,6,26,27,28,29,25};
int SW [4] = {21,22,23,24};
int puls = 0;
int main(void)
{
while(!digitalRead(puls)){
//printf("Raspberry Pi Encendido de Led\n");

wiringPiSetup ();
for(int i = 0; i < 7 ; i++)
{
	pinMode(LEDS[i],OUTPUT);
}
for(int i = 0; i < 4; i++)
{
	pinMode(SW[i],INPUT);
}

if(digitalRead(SW[0]) == HIGH && digitalRead(SW[1]) == LOW && digitalRead(SW[2]) == LOW && digitalRead(SW[3]) == LOW)//1
{
	printf(" sucuencia 1 activa \n");
	for(int i=0; i < 7;i++)
	{
	digitalWrite(LEDS[i],HIGH);
	delay(250);
	digitalWrite(LEDS[i],LOW);
	}
}
if(digitalRead(SW[0]) == LOW && digitalRead(SW[1]) == HIGH && digitalRead(SW[2]) == LOW && digitalRead(SW[3]) == LOW)//2
{
	printf(" sucuencia 2 activa \n");
	for(int i=7; i > -1;i--)
	{
	digitalWrite(LEDS[i],HIGH);
	delay(250);
	digitalWrite(LEDS[i],LOW);
	}
}
if(digitalRead(SW[0]) == HIGH && digitalRead(SW[1]) == HIGH && digitalRead(SW[2]) == LOW && digitalRead(SW[3]) == LOW)//3
{
	printf(" sucuencia 3 activa \n");
	int j=7;
	for(int i=0; i < 4;i++)
	{
	digitalWrite(LEDS[i],HIGH);
	digitalWrite(LEDS[j],HIGH);
	delay(100);
	digitalWrite(LEDS[i],LOW);
	digitalWrite(LEDS[j--],LOW);
	}
	j=5;
	for(int i=2;i>0;i--){
	digitalWrite(LEDS[i],HIGH);
	digitalWrite(LEDS[j],HIGH);
	delay(100);
	digitalWrite(LEDS[i],LOW);
	digitalWrite(LEDS[j++],LOW);	
	}
}
if(digitalRead(SW[0]) == LOW && digitalRead(SW[1]) == LOW && digitalRead(SW[2]) == HIGH && digitalRead(SW[3]) == LOW)//4
{
	printf(" sucuencia 4 auto fantastico \n");
	for(int i=0; i < 7;i++)
	{
	digitalWrite(LEDS[i],HIGH);
	delay(50);
	digitalWrite(LEDS[i],LOW);
	}
	for(int i=7; i > -1;i--)
	{
	digitalWrite(LEDS[i],HIGH);
	delay(50);
	digitalWrite(LEDS[i],LOW);
	}
	
}
if(digitalRead(SW[0]) == HIGH && digitalRead(SW[1]) == LOW && digitalRead(SW[2]) == HIGH && digitalRead(SW[3]) == LOW)//5
{
	printf("secuencia 5 choque\n");
	int count=0;
	for(int j = 7; j > -1 ; j--)
	{
		for(int i = 0;i<7; i++)
		{
			digitalWrite(LEDS[i],HIGH);
			delay(250);
			
			if(i>j)
			{
				printf("deja prendidos %i leds\n",7-i);
				break;
			}
			else
			{
				digitalWrite(LEDS[i],LOW);
				delay(125);
			}
		
	}
	digitalWrite(LEDS[j],HIGH);
	count++;
	delay(250);
}
}	
		
}	
return 0;
}
