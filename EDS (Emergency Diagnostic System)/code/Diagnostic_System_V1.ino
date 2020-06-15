#include <LiquidCrystal.h>

LiquidCrystal lcd(3, 4, 16, 15, 14, 13);

//set buzzer pin
const int buzzer = 18; //buzzer to arduino pin 9

//startup music
double StartupNotes[] = { 329.63, 329.63, 329.63, 261.63, 329.63, 392.00, 196.00};

//alarm noises
double ERR_0[] = {239.00, 466.16};
int ERR_0_Count = 2;
double ERR_1 = 329.96;
int ERR_1_Count = 1;
double ERR_2[] = {659.25, 622.25};
int ERR_2_Count = 2;

//music control
int QuarterNote = 150;
int SixteenthNote = QuarterNote * .5;
int HalfNote = QuarterNote * 2;
double StartupNotesTime[] = { QuarterNote, SixteenthNote, QuarterNote, SixteenthNote, QuarterNote, HalfNote, HalfNote};
int NoteCount = 7;

//Do once to make sure LCD's print once
int DoOnce_NoIssues = 0;

int DoOnce_MasterSwitch = 0;

int DoOnce_BrakeOverTravel = 0;

int DoOnce_InertiaSwitch = 0;

int DoOnce_IMD = 0;

int DoOnce_BPD = 0;

//Setup Shutdown Buttons

//Master Switch Check
int MasterSwitch = A7;
int MasterSwitch_Value = 0;

//Brake Over Travel
int BrakeOverTravel = A6;
int BrakeOverTravel_Value = 0;

//Inertia Switch

//IMD

//BPD

int ErrSit = 0; //This code changes to 1-5 depending on errors
void setup()
{
  lcd.setCursor(0, 1);


  lcd.begin(16, 2);


  lcd.write("Booting systems...");

  //Setup Shutdown Buttons

  //Master Switch Check
  pinMode(MasterSwitch, INPUT);

  //Brake Over Travel
  pinMode(BrakeOverTravel, INPUT);
  //Inertia Switch

  //IMD

  //BPD


  //Startup Noise
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  delay(1000);
  for (int CurrentNote = 0; CurrentNote < NoteCount; CurrentNote++)
  {
    tone(buzzer, StartupNotes[CurrentNote]);
    delay(StartupNotesTime[CurrentNote]);
    noTone(buzzer);
    delay(StartupNotesTime[CurrentNote]);
  }
  lcd.clear();
  lcd.write("Done!");
  lcd.setCursor(0, 1);
  lcd.write("Trust the Thrust!");
  delay(500);
  lcd.clear();
}


void loop()
{
  //reading voltmeter states

  //Master Switch Check
  MasterSwitch_Value = analogRead(MasterSwitch);

  //Brake Over Travel Switch Check
  BrakeOverTravel_Value = analogRead(BrakeOverTravel);
  Serial.println(BrakeOverTravel_Value);


  //checking Voltmeter Values if over tolerance
  if (MasterSwitch_Value > 200)
  {
    ErrSit = 1;

  }
  else
  {
    if (BrakeOverTravel_Value > 200)
    {
      ErrSit = 3;
    }
    else
    {
      ErrSit = 0;
    }
  }


  //Sounding Alarms
  //-----------------------------------------------
  if (ErrSit == 0) // No Errors
  {
    if (DoOnce_NoIssues ==0)
    {  
      lcd.clear();
      lcd.print("  [No Issues] ");      
      DoOnce_NoIssues =1;
    }
  }
  else
  {
    DoOnce_NoIssues=0;  
  }
  //-----------------------------------------------
  if (ErrSit == 1) // Master Switch Fail
  {
    if (DoOnce_MasterSwitch ==0)
    {    
      lcd.clear();
      lcd.write("-----M:S OFF-----");
      //no noise
      DoOnce_MasterSwitch=1;
    }
    else
    {
      DoOnce_MasterSwitch=0;   
    }
  }

  //-----------------------------------------------
  if (ErrSit == 2)// Brake Over Travel
  {
    if (DoOnce_BrakeOverTravel ==0)
    {     
      //alarm ERR_1
      tone(buzzer, ERR_1);
      delay(SixteenthNote);
      noTone(buzzer);
      delay(SixteenthNote);
  
      lcd.clear();
      lcd.write("-----Brake Fail-----");

      DoOnce_BrakeOverTravel=1;
    }
    else
    {
      DoOnce_BrakeOverTravel=0;   
    }      
  }
  //-----------------------------------------------
  if (ErrSit == 3)// Inertia Switch
  {
    
    //alarm ERR_2
    for (int CurrentNote = 0; CurrentNote < ERR_2_Count; CurrentNote++)
    {
      tone(buzzer, ERR_2[CurrentNote]);
      delay(SixteenthNote);
      noTone(buzzer);
      delay(SixteenthNote);

      lcd.clear();
      lcd.write("-----Inert Trig-----");
    }
  }
  //-----------------------------------------------
  if (ErrSit == 4)//IMD
  {
  
    //alarm ERR_0
    for (int CurrentNote = 0; CurrentNote < ERR_0_Count; CurrentNote++)
    {
      tone(buzzer, ERR_0[CurrentNote]);
      delay(HalfNote);
      noTone(buzzer);
      delay(HalfNote);
  
      lcd.clear();
      lcd.write("-----IMD Fail-----");
  
    }
  }
  //-----------------------------------------------
  if (ErrSit == 4)//BPD
  {
  
    //alarm ERR_1
    tone(buzzer, ERR_1);
    delay(SixteenthNote);
    noTone(buzzer);
    delay(SixteenthNote);
  
  
      lcd.clear();
      lcd.write("-----Brake PD Off-----");
  
  }
}
