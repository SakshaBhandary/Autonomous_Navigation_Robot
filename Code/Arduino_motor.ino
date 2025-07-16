int LM1 = 2; //Left Motor
int LM2 = 3;
int RM1 = 4; //Right Motor
int RM2 = 5;

int Left_Speed = 9; //EnA
int Right_Speed = 10; ////EnB

void SetSpeed(int Speed)
{
  analogWrite(Left_Speed, Speed);
  analogWrite(Right_Speed, Speed);
}

void Stop()
{
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}
void  Forward()
{
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
}
void  Backward()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}
void  SpotRight()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
}
void  SpotLeft()
{
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

void setup() 
{
  // start serial port at 9600 bps:
  Serial.begin(9600);
  // initialize digital Motor pins for control inputs & Enable pins for setting the speed.
  pinMode(LM1, OUTPUT); //Left 1
  pinMode(LM2, OUTPUT); //Left 2
  pinMode(RM1, OUTPUT); //Right 1
  pinMode(RM2, OUTPUT); //Right 2
  pinMode(Left_Speed, OUTPUT); //Enable A
  pinMode(Right_Speed, OUTPUT); //Enable B
  while (!Serial) {
    ; // wait for the serial port to connect.
  }
}

void loop() 
{
  char buffer[16];
  // if we get a command, turn the motor in specific direction
  if (Serial.available() > 0) {
    int size = Serial.readBytesUntil('\n', buffer, 12);
    if (buffer[0] == 'F') {
      Forward();
      SetSpeed(50);
    }
    if (buffer[0] == 'B') {
      Backward();
      SetSpeed(50);
    }
    if (buffer[0] == 'R') {
      SpotRight();
      SetSpeed(50);
    }
    if (buffer[0] == 'L') {
      SpotLeft();
      SetSpeed(50);
    }
    if (buffer[0] == 'S') {
      Stop();
      SetSpeed(50);
    }
  }
}