 // ВОРОТА //
// Входа и выхода 
#define in_ready 36  // 1=готовность. Горит зелёный свтодиод, взведено в ожидание пилота.
#define in_set   34  // 1=сработка. Включается желтый светодиод. Сработка продолжает висеть, пока спустя 5 секунд не сбросишь out_rst.
#define out_rst  35  // 1=нормальное состояние выхода, 0=взвести триггер в готовность, в ожидание сработки.





/* // **** Дисплей ****
  u8g.firstPage();
  do {
    draw_OUT();
    draw_SET();
    draw_RDy();
    draw_RUN();
    draw_tablo();
  } while ( u8g.nextPage() );

*/




// **** ПОДПРОГРАММЫ *************************************************************************************

/*
void draw_tablo(void) {
  // Секундомер на обычном фоне.
  u8g.setColorIndex(1);
  u8g.drawHLine(0, 12, 128); // линия 110
  // Секундомерное табло
  u8g.setFont(u8g_font_helvR24);  //Шрифт w=17 h=24
  u8g.setPrintPos(0, 62);
  u8g.print( int(m), 10);
  u8g.drawStr( 35, 62, ":");
  u8g.setPrintPos(45, 62);
  u8g.print( int(s), 10);
  u8g.drawStr( 81, 62, ",");
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(93, 62);
  u8g.print( int(ms), 10);
}


void draw_OUT(void) {
  // Рисует OUT выход с LM567  белый фон =светит, чёрный фон =перекрыто
  u8g.setFont(u8g_font_unifont);
  if (digitalRead(in_gate) == 1) {
    u8g.setColorIndex(1);
    u8g.drawBox(0, 0, 26, 12); // X Y левого верхнего угла, ширина, высота вниз
    u8g.setColorIndex(0);
    u8g.drawStr( 0, 11, "G"); // x и y – координаты левого нижнего угла первого символа строки, потом текст
  } else {
    u8g.setColorIndex(1);
    u8g.drawStr( 0, 11, "G");
  }
}


void draw_SET(void) {
  // SET белый фон =пилот пролетел, состояние обратное RST
  u8g.setFont(u8g_font_unifont);
  if (digitalRead(in_set) == 1) {
    u8g.setColorIndex(1);
    u8g.drawBox(56, 0, 26, 12);
    u8g.setColorIndex(0);
    u8g.drawStr( 56, 11, "SET");
  } else {
    u8g.setColorIndex(1);
    u8g.drawStr( 56, 11, "SET");
  }
}


void draw_RDy(void) {
  // RD белый фон =ввзведено в ожидание пилота. Готовность
  u8g.setFont(u8g_font_unifont);
  if (digitalRead(in_ready) == 1) {
    u8g.setColorIndex(1);
    u8g.drawBox(28, 0, 26, 12);
    u8g.setColorIndex(0);
    u8g.drawStr( 28, 11, "RD");
  } else {
    u8g.setColorIndex(1);
    u8g.drawStr( 28, 11, "RD");
  }
}


void draw_RUN(void) {
  //RUN таймер ведёт отсчёт времени, белый фон =считает, чёрный фон=секундомер остановлен
  u8g.setFont(u8g_font_unifont);
  if (start_flag == 1) {
    u8g.setColorIndex(1);
    u8g.drawBox(84, 0, 26, 12);  // белая подложка под RUN
    u8g.drawStr( 0, 30, "vremya idet");
    u8g.setColorIndex(0);
    u8g.drawStr( 84, 11, "TMR");
    u8g.drawBox(0, 62, 24, 24);  // черная заглушка времени
  } else {
    u8g.setColorIndex(1);
    u8g.drawStr( 84, 11, "TMR");
    u8g.drawStr( 0, 30, "fly time");
  }
  */
