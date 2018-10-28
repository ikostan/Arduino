//Source:  https://www.youtube.com/watch?v=VIa_QZWIonQ&index=12&list=PLGs0VKk2DiYx6CMdOQR_hmJ2NbB4mZQn-

const String lessonName = "LESSON 12: \nSimple and Easy Way to Read Strings Floats and Ints over Arduino Serial Port";
const int baudSpeed = 9600;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(baudSpeed);
  Serial.println(lessonName);
}

void loop() {
  // put your main code here, to run repeatedly:

}
