#include "display.h"
#include "common.h"

void DrawSineWave(int16_t x, int16_t y){

	lcdFilledRectangle(x,y-10,x+35,y+12,decodeRgbValue(0, 0, 0));

	lcdCircle(x+8, y, 8, decodeRgbValue(255, 255, 255));
	lcdCircle(x+24, y, 8, decodeRgbValue(255, 255, 255));
	lcdFilledRectangle(x,y,x+15,y+10,decodeRgbValue(0, 0, 0));
	lcdFilledRectangle(x+17,y-10,x+34,y,decodeRgbValue(0, 0, 0));

	lcdLine(x-2, y, x+34, y, decodeRgbValue(0, 255, 0));
}

void DrawSquare(int16_t x, int16_t y)
{
	lcdFilledRectangle(x,y-10,x+35,y+12,decodeRgbValue(0, 0, 0));

	lcdLine(x, y-8, x, y, decodeRgbValue(255, 255, 255));
	lcdLine(x, y-8, x+16, y-8, decodeRgbValue(255, 255, 255));
	lcdLine(x+16, y-8, x+16, y+8, decodeRgbValue(255, 255, 255));
	lcdLine(x+16, y+8, x+32, y+8, decodeRgbValue(255, 255, 255));
	lcdLine(x+32, y+8, x+32, y, decodeRgbValue(255, 255, 255));

	lcdLine(x-2, y, x+34, y, decodeRgbValue(0, 255, 0));
}

void DrawSawtooth(int16_t x, int16_t y){

	lcdFilledRectangle(x,y-10,x+35,y+12,decodeRgbValue(0, 0, 0));

	lcdLine(x, y+8, x+16, y-8, decodeRgbValue(255, 255, 255));
	lcdLine(x+16, y-8, x+16, y+8, decodeRgbValue(255, 255, 255));
	lcdLine(x+16, y+8, x+32, y-8, decodeRgbValue(255, 255, 255));
	lcdLine(x+32, y-8, x+32, y+8, decodeRgbValue(255, 255, 255));

	lcdLine(x-2, y, x+34, y, decodeRgbValue(0, 255, 0));
}
/*
void drawAxis(int16_t x,int16_t y){
	lcdLine(x-2, y, x+34, y, decodeRgbValue(0, 255, 0));
}*/
void WriteFreqLFO1(int number)
{
	// tento clear pouzit potom aby nebol fuck up s 3 a 4 miestnymi cislami
	lcdPutS("       ", lcdTextX(11), lcdTextY(13), decodeRgbValue(255, 0, 0), decodeRgbValue(0, 0, 0));
	itoa(number,message_buffer,10);
	lcdPutS(message_buffer, lcdTextX(1), lcdTextY(14), decodeRgbValue(255, 0, 0), decodeRgbValue(0, 0, 0));
}

void WriteFreqLFO2(int number)
{
	// tento clear pouzit potom aby nebol fuck up s 3 a 4 miestnymi cislami
	lcdPutS("       ", lcdTextX(11), lcdTextY(13), decodeRgbValue(255, 0, 0), decodeRgbValue(0, 0, 0));
	itoa(number,message_buffer,10);
	lcdPutS(message_buffer, lcdTextX(11), lcdTextY(14), decodeRgbValue(255, 0, 0), decodeRgbValue(0, 0, 0));
}

void WriteFreqOSC1(int number)
{
	// tento clear pouzit potom aby nebol fuck up s 3 a 4 miestnymi cislami
	lcdPutS("      ", lcdTextX(1), lcdTextY(6), decodeRgbValue(255, 0, 0), decodeRgbValue(0, 0, 0));
	itoa(number,message_buffer,10);
	lcdPutS(message_buffer, lcdTextX(1), lcdTextY(6), decodeRgbValue(255, 0, 0), decodeRgbValue(0, 0, 0));
}

void WriteFreqOSC2(int number)
{
	// tento clear pouzit potom aby nebol fuck up s 3 a 4 miestnymi cislami
	lcdPutS("      ", lcdTextX(11), lcdTextY(6), decodeRgbValue(255, 0, 0), decodeRgbValue(0, 0, 0));
	itoa(number,message_buffer,10);
	lcdPutS(message_buffer, lcdTextX(11), lcdTextY(6), decodeRgbValue(255, 0, 0), decodeRgbValue(0, 0, 0));
}

void InitDisplay()
{
	initSPI2();
	initCD_Pin();
	initCS_Pin();
	initRES_Pin();
	lcdInitialise(LCD_ORIENTATION2);
	lcdClearDisplay(decodeRgbValue(0, 0, 0));
}

void DisplayScreen1()
{
		lcdClearDisplay(decodeRgbValue(0, 0, 0));
		// obvod displeja
		lcdLine(0, 0, 128, 0, decodeRgbValue(255, 255, 255));
		lcdLine(0, 128, 128, 128, decodeRgbValue(255, 255, 255));
		lcdLine(0, 0, 0, 128, decodeRgbValue(255, 255, 255));
		lcdLine(64, 0, 64, 128, decodeRgbValue(255, 255, 255));
		lcdLine(128, 0, 128, 128, decodeRgbValue(255, 255, 255));
		lcdLine(0, 64, 128, 64, decodeRgbValue(255, 255, 255));

		//texty
		//lcdPutS("SYNTHESIZER", lcdTextX(4), lcdTextY(1), decodeRgbValue(255, 0, 0), decodeRgbValue(0, 0, 0));
		lcdPutS("OSC1", lcdTextX(4), lcdTextY(1), decodeRgbValue(255, 0, 0), decodeRgbValue(0, 0, 0));
		lcdPutS("OSC2", lcdTextX(14), lcdTextY(1), decodeRgbValue(255, 0, 0), decodeRgbValue(0, 0, 0));
		lcdPutS("LFO1", lcdTextX(4), lcdTextY(9), decodeRgbValue(255, 0, 0), decodeRgbValue(0, 0, 0));
		lcdPutS("LFO2", lcdTextX(14), lcdTextY(9), decodeRgbValue(255, 0, 0), decodeRgbValue(0, 0, 0));
		lcdPutS("Freq.(Hz)", lcdTextX(1), lcdTextY(5), decodeRgbValue(255, 0, 0), decodeRgbValue(0, 0, 0));
		lcdPutS("Freq.(Hz)", lcdTextX(11), lcdTextY(5), decodeRgbValue(255, 0, 0), decodeRgbValue(0, 0, 0));
		lcdPutS("Freq.(Hz)", lcdTextX(1), lcdTextY(13), decodeRgbValue(255, 0, 0), decodeRgbValue(0, 0, 0));
		lcdPutS("Freq.(Hz)", lcdTextX(11), lcdTextY(13), decodeRgbValue(255, 0, 0), decodeRgbValue(0, 0, 0));
}

void DisplayScreen2()
{
	lcdClearDisplay(decodeRgbValue(0, 0, 0));
	lcdLine(0, 0, 128, 0, decodeRgbValue(255, 255, 255));
	lcdLine(0, 128, 128, 128, decodeRgbValue(255, 255, 255));
	lcdLine(0, 0, 0, 128, decodeRgbValue(255, 255, 255));
	lcdLine(128, 0, 128, 128, decodeRgbValue(255, 255, 255));
	lcdPutS("SYNTHESIZER", lcdTextX(5), lcdTextY(1), decodeRgbValue(255, 0, 0), decodeRgbValue(0, 0, 0));
	lcdPutS("ADRS", lcdTextX(13), lcdTextY(3), decodeRgbValue(255, 255, 255), decodeRgbValue(0, 0, 0));
	lcdLine(0, 17, 128, 17, decodeRgbValue(255, 255, 255));

	//A
	lcdLine(10, 85, 37, 25, decodeRgbValue(255, 111, 10));
	lcdCircle(37, 25, 1, decodeRgbValue(255, 255, 255));
	lcdCircle(37, 25, 2, decodeRgbValue(255, 255, 255));
	//D
	lcdLine(37, 25, 64, 50, decodeRgbValue(10, 111, 255));
	lcdCircle(64, 50, 1, decodeRgbValue(255, 255, 255));
	lcdCircle(64, 50, 2, decodeRgbValue(255, 255, 255));
	//S
	lcdLine(64, 50, 91, 50, decodeRgbValue(255, 255, 0));
	lcdCircle(91, 50, 1, decodeRgbValue(255, 255, 255));
	lcdCircle(91, 50, 2, decodeRgbValue(255, 255, 255));
	//R
	lcdLine(91, 50, 116, 85, decodeRgbValue(255, 0, 255));

	lcdLine(10, 25, 10, 90, decodeRgbValue(255, 255, 255));
	lcdLine(5, 85, 118, 85, decodeRgbValue(255, 255, 255));


}


void DrawAllParams() {
	switch(params.osc1_waveform) {
		case SINE:
			DrawSineWave(16, 28);
			break;
		case SQUARE:
			DrawSquare(16, 28);
			break;
		case SAWTOOTH:
			DrawSawtooth(16, 28);
			break;
	}

	switch(params.osc2_waveform) {
			case SINE:
				DrawSineWave(80, 28);
				break;
			case SQUARE:
				DrawSquare(80, 28);
				break;
			case SAWTOOTH:
				DrawSawtooth(80, 28);
				break;
	}

	WriteFreqOSC1(params.osc1_freq);

	WriteFreqOSC2(params.osc2_freq);

}
