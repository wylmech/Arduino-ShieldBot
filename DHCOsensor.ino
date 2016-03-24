#include "Shieldbot.h"  //ヘッダファイル読み込み

Shieldbot shieldbot = Shieldbot();  //おまじない

int count = 0;//countを定義
float Vs1 = 0;//センサの印加時の値
float Vs2 = 0;
float Vs3 = 0;
      
void setup() {
  Serial.begin(9600);//シリアル通信開始
      Serial.println("Are your ready?");
        delay(2000);//2000msec待機
      Serial.println("Start");
}



void loop() {

DHCO();
}

void DHCO(){
  int i;                               //iを定義

  const float Vcc = 4.95;              //基本電圧は電圧降下考慮で4.95とする
  int sensorValue1;
  int sensorValue2;
  int sensorValue3;

/*瞬時値の表示*/
    for(i=0;i<10;i++){
// Serial.println(analogRead(A0));     //デバック用
  delay(500);//50msec待機
  sensorValue1 = analogRead(A0);       //変数sensorValue1を定義、A0をアナログ読み込みモードにして代入
  sensorValue2 = analogRead(A1);
  sensorValue3 = analogRead(A2);
  Vs1 = Vs1 + sensorValue1* Vcc / 1024;  //センサの電圧計算式
  Vs2 = Vs2 + sensorValue2* Vcc / 1024;
  Vs3 = Vs3 + sensorValue3* Vcc / 1024; 
 Serial.println(Vs1/(i+1),2);           //シリアルモニタに変数Vsの値の下5桁まで表示&改行
 Serial.println(Vs2/(i+1),2);
 Serial.println(Vs3/(i+1),2);
  delay(500);//50msec待機
    }

/*10秒間の平均の表示*/
  delay(500);//500msec待機
  Serial.print("Vs1;    ");            //「Vs;　」を表示
  Serial.println(Vs1/10,2);             //シリアルモニタに変数Vsの値の下5桁まで表示&改行
  Serial.print("Vs2;    ");
  Serial.println(Vs2/10,2);
  Serial.print("Vs3;    ");
  Serial.println(Vs3/10,2);
  delay(100);                           //100msec待機
  i = 0;
  Vs1 = 0;
  Vs2 = 0;
  Vs3 = 0;
}
