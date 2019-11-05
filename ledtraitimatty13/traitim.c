/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.0 Professional
Automatic Program Generator
© Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 10/5/2019
Author  : NeVaDa
Company : 
Comments: 


Chip type               : ATtiny13A
AVR Core Clock frequency: 9.600000 MHz
Memory model            : Tiny
External RAM size       : 0
Data Stack size         : 16
*****************************************************/
#include <stdlib.h>
#include <tiny13a.h>
#include <delay.h>


void sang(char loai);
void nhapNhayTatCa();
void chayMotCaiMotXepHinh(char direction);
void huychDen(char direction, char coChayLen);

void addOne();
void sang(char loai);
void addOne() {
     PORTB = 7;
     PORTB = 1;
}

void addZero();
void addZero() {
     PORTB = 6;
     PORTB = 0;
}

void addOneMulti(char time) {
    time++;
    while (time --) {
        addOne();
    }
}

void addZeroMulti(char time) {
    time++;
    while (time --) {
           addZero();
    }
}





//
//  Hien thi 8 den tu mang truyen vao  ..can delay
char den[8] = {0,0,0,0, 0,0,0,0};
void hienThiDen() {
    char i = 0;
    for (i=0; i<9; i++) {
        if (den[i] == 1) {
            addOne();
        } else {
            addZero();
        }
    }
}

void chayVaoGiuaXepHinh() {
    char i = 0;
    for (;i<8;i++) {  
        char i2 = 0;
        for (i2 = 0;i2<4-i;i2++) {
            if (i2>0) {
                den[i2-1] = 0;
                den[7-i2+1]= 0;
            }
            den[7-i2] = 1;
            den[i2] = 1;
            hienThiDen();
            delay_ms(250);
        }
        delay_ms(250);
    } 
}

void chayThatNhanhTuCuHuynh(char viTriHuych, char direction) {
    char i = viTriHuych;
    for (; i<8; i ++) {
        if (i>0) {
            if (direction == 1) {
                den[i-1] = 0;
            } else {
                den[7 - (i-1)] = 0;                    
            }
                
        }
        if (direction == 1) {
            den[i] = 1;
        } else {
            den[7 - i] = 1;
        } 
        hienThiDen();
        delay_ms(250);
    }              
    
    for (i = 7; i >= viTriHuych + 1; i --) {
        if (i<7) {
            if (direction == 1) {
                den[i+1] = 0;
            } else {
                den[7 - (i+1)] = 0;                    
            }
                
        }
        if (direction == 1) {
            den[i] = 1;
        } else {
            den[7 - i] = 1;
        } 
        hienThiDen();
        delay_ms(400);
    }
}
// không dùng
void chayVaoGiua(char time) {
    while (--time) {
       char i = 0;
       for (;i<4;i++) {
            if (i>0) {
                den[i-1] = 0;
                den[7-i+1]= 0;
            }
            den[7-i] = 1;
            den[i] = 1;
            hienThiDen();
            delay_ms(250);
            if (i == 3) {
                den[3] = 0;
                den[4] = 0;
                hienThiDen();
                delay_ms(250);
            }
        }
    }
}


void sang(char loai);

void main(void)
{
    char i = 0;
#pragma optsize-
CLKPR=0x80;CLKPR=0x00;
#ifdef _OPTIMIZE_SIZE_
#pragma optsize+
#endif
PORTB=0x30;DDRB=0x07;TCCR0A=0x00;TCCR0B=0x00;TCNT0=0x00;OCR0A=0x00;OCR0B=0x00;GIMSK=0x00;MCUCR=0x00;
TIMSK0=0x00;ACSR=0x80;ADCSRB=0x00;DIDR0=0x00;ADCSRA=0x00;
 



while (1)
{
      if(PINB.4==0) {
        ++i;
        if(i==1){         
             chayMotCaiMotXepHinh(1);
        } else if(i==2) {
            huychDen(-1, -1);
        } else if (i==4) {
            huychDen(1, -1);
        } else if (i==6) {
            huychDen(-1, 1);      
        } else if (i==11) {
            huychDen(1,1);  
        } else if (i==10) {
            chayMotCaiMotXepHinh(-1);
        } else if (i==5) {
            chayMotCaiMotXepHinh(1);  
        } else if (i==7) {
            chayVaoGiuaXepHinh();
        } else if (i==9) {
            sang(1);  
        } else if (i==3) {
            sang(2);    
        } else if (i==8) {
            sang(3);   
        } else if (i==12) {
            i = 0;
        } 
         sang(3); 
      }
}
}



// so 1: sáng sen ke. 2 sáng d?n .. 3 t?t dàn
void sang(char loai) {
    char i = 0;
    
    while(i<9){  
        if (loai == 1) {
            addOne();
            delay_ms(250);   
            addZero();
            delay_ms(250);
        } else if (loai == 2) {
            addOne();
            delay_ms(250);  
        } else {
            addZero();
            delay_ms(250);
        }        
        i++;
    }
}
// so 4 : ko dùng
void nhapNhayTatCa() {
    char i = 0;
    while(i<8){
        addOneMulti(8);
        delay_ms(250);
        addZeroMulti(8);
        delay_ms(250);    
        ++i;
    }
}

// so 5
void chayMotCaiMotXepHinh(char direction) {
    char i = 0;
    for (;i<8;++i) {  
        char i2 = 0;
        for (i2 = 0;i2<8-i;++i2) {
            if (i2>0) {
                if (direction == 1) {
                    den[i2-1] = 0;
                } else {
                    den[7 - (i2-1)] = 0;                    
                }
                
            }
            if (direction == 1) {
                den[i2] = 1;
            } else {
                den[7 - i2] = 1;
            }
            
            hienThiDen();
            delay_ms(250);
        }
        delay_ms(250);
    }    
}

// so 6

void huychDen(char direction, char coChayLen) {
    char i = 7;    
    for (;i>0;i--) {  
        char i2 = 0;
        for (i2 = 0;i2<10-i;i2++) {
            if (i2>0) {
                 if (direction == 1) {
                    den[i2-1] = 0;
                } else {
                    den[7 - (i2-1)] = 0;                    
                }
            }
            if (direction == 1) {
                den[i2] = 1;
            } else {
                den[7 - i2] = 1;
            }
            hienThiDen();
            delay_ms(250);
        }                
        if (coChayLen == 1) {
            chayThatNhanhTuCuHuynh(7 - i, direction);
        }
        //delay_ms(250);
    } 
}
//srand((unsigned) time(&t)); 
///* in 5 so ngau nhien trong day tu 0 toi 49 */ 
//for( i = 0 ; i < n ; i++ ) 
//{ printf("%d\n", rand() % 50); } return(0); }