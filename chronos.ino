void setup() {

    int i=0;
    for(i=0;i<=51;i+=1)
       pinMode(i,OUTPUT);
    Serial.begin(115200);
    TCCR1B=0;
    TCCR1A=0;
    TCCR1B = bit(CS12);
} 

//fuction to show number'dig' on k'th seven segment display 
      void digit(int dig,int k)
  {


    if (dig == 0)
      out(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW,k);
    if (dig == 1)
      out(LOW, HIGH, HIGH, LOW, LOW, LOW, LOW,k);
    if (dig == 2)
      out(HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH,k);
    if (dig == 3)
      out(HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH,k);
    if (dig == 4)
      out(LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH,k);
    if (dig == 5)
      out(HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH,k);
    if (dig == 6)
      out(HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH,k);
    if (dig == 7)
      out(HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW,k);
    if (dig == 8)
      out(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH,k);
    if (dig == 9)
      out(HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH,k);
    // else
    //   out(LOW, LOW,LOW,LOW,LOW,LOW,LOW,k);

  }
  //
void out(boolean aout,boolean bout,boolean cout,boolean dout,boolean eout,boolean fout,boolean gout,int k)
{
  switch(k){
    case 0:
  digitalWrite(22,aout);
  digitalWrite(24,bout);
  digitalWrite(26,cout);
  digitalWrite(28,dout);
  digitalWrite(30,eout);
  digitalWrite(32,fout);
  digitalWrite(34,gout);
    case 1:
  digitalWrite(50,aout);
  digitalWrite(48,bout);
  digitalWrite(40,cout);
  digitalWrite(44,dout);
  digitalWrite(42,eout);
  digitalWrite(46,fout);
  digitalWrite(38,gout);
    case 2:
  digitalWrite(51,aout);
  digitalWrite(49,bout);
  digitalWrite(47,cout);
  digitalWrite(45,dout);
  digitalWrite(43,eout);
  digitalWrite(41,fout);
  digitalWrite(39,gout);
    case 3:
  digitalWrite(35,aout);
  digitalWrite(33,bout);
  digitalWrite(31,cout);
  digitalWrite(29,dout);
  digitalWrite(27,eout);
  digitalWrite(23,fout);
  digitalWrite(25,gout);
    case 4:
  digitalWrite(1,aout);
  digitalWrite(2,bout);
  digitalWrite(3,cout);
  digitalWrite(6,dout);
  digitalWrite(4,eout);
  digitalWrite(5,fout);
  digitalWrite(7,gout);
    case 5:
  digitalWrite(21,aout);
  digitalWrite(20,bout);
  digitalWrite(19,cout);
  digitalWrite(18,dout);
  digitalWrite(17,eout);
  digitalWrite(16,fout);
  digitalWrite(15,gout);
  }
}

void loop() {
  // number of hours or mins to start countdown from
   unsigned long engihr=25,engimin,engisec;

  
   long i;
   unsigned long mins=0,hr=0,day=0,min1=0,min2=0,hr1=0,hr2=0,secs,sec1,sec2;
   engimin=engihr*60;
   engisec=engimin*60;

   Serial.println(engisec);
   //for loop to end when engimin=0 i,e engineer starts
   for(i=engisec-1;i>=0;i-=1)
   {

  TCNT1 = 0;
  // i is number of minutes left

  //finding mins,hrs,secs to show in display from total minutes i
   hr=i/3600;
   mins=(i-hr*3600)/60;
   secs=i%60;

  //1st and 2nd digit of min and hour
   min1=mins/10;
   min2=mins%10;
   hr1=hr/10;
   hr2=hr%10;
   sec1=secs/10;
   sec2=secs%10;
  //showing digits on seven segment display
   digit(sec2,0);
   digit(sec1,1);
   digit(min2,2);
   digit(min1,3);
   digit(hr2,4);
   digit(hr1,5);
 //update i(minutes) after 60 seconds
unsigned int cycles;
while (true){
  cycles =TCNT1;
  if (cycles>=62500)
  break;
}
 
   }

   //clock starts counting from 0 after start of engi
i=0;
   for(i=0;true;i+=1)
   {
  // i is number of minutes over since start of engi
  TCNT1 = 0;
  // i is number of minutes left

  //finding mins,hrs,secs to show in display from total minutes i
   hr=i/3600;
   mins=(i-hr*3600)/60;
   secs=i%60;


   min1=mins/10;
   min2=mins%10;
   hr1=hr/10;
   hr2=hr%10;
   sec1=secs/10;
   sec2=secs%10;
  //showing digits on seven segment display
   digit(sec2,0);
   digit(sec1,1);
   digit(min2,2);
   digit(min1,3);
   digit(hr2,4);
   digit(hr1,5);
 //update i(minutes) after 60 seconds
unsigned int cycles;
while (true){
  cycles =TCNT1;
  if (cycles==62500)
  break;
   }
}
}
