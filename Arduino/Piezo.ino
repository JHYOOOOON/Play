int speaker = 9;
// 다장조
//int low_sol = 392;
//int low_si = 494;
//int high_do = 523;
//int high_le = 587;
//int high_mi = 659;
//int high_sol = 784;
//int high_si = 988;

// 하나 올림
int low_sol = 415;
int low_si = 523;
int high_do = 554;
int high_le = 622;
int high_mi = 698;
int high_sol = 831;
int high_si = 1047;

// 4분음표, 8분음표, 점4분음표 ...
int four = 490;
int eight = 190;
int four_half = 510;
int eight_half = 360;
int eight_dhalf = 260;
int two = 1000;
int two_half = 1200;

// 음계
int scale[44] = {
  high_mi, high_mi, high_mi,
  high_mi, high_mi, high_sol, high_si, high_mi, high_mi,
  high_mi, high_sol, high_si, high_mi, high_mi, high_le, high_le, high_do,
  low_si, high_le, low_si, low_sol, low_sol,
  
  high_mi, high_mi, high_mi,
  high_mi, high_sol, high_si, high_mi, high_mi,
  high_mi, high_mi, high_sol, high_si, high_mi, high_mi, high_le, high_le, high_do, low_si,
  high_le, low_si, low_sol, low_sol
};

// 음 길이
int note[] = {
  eight, eight_half, eight_half, eight_dhalf, //3
  four_half, eight, four_half, eight, two, //8
  four_half, eight, four_half, eight, four_half, eight, four_half, eight,
  four_half, eight, four_half, eight, two_half, //21
  
  eight_half, eight_half, eight_dhalf, //24
  four_half, eight, four_half, eight, two, //29
  eight, four_half, eight, four_half, eight, four_half, eight, four_half, eight, four_half,
  eight, four_half, eight, two_half //43
};

// 도레미파솔라시x2
int scale_x[16] = {262, 294, 339, 349, 392, 440, 494, 523, 587, 659, 698, 784, 880, 988, 1047};

void setup(){
  pinMode(speaker, OUTPUT);
}

void loop(){
  for(int i=0; i<44; i++){
    tone(speaker, scale[i], note[i]);
    if(i == 8 || i == 29)
      delay(1500);
    else if(i == 21 || i == 43)
      delay(3200);
    else delay(note[i]*1.1);
     
  }
  delay(4000);
}
