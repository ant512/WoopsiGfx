#include "bitmap.h"
#include "framebuffer.h"
#include "graphics.h"
#include <nds.h>

using namespace WoopsiGfx;

void initGfxMode() {
	powerOn(POWER_ALL_2D);

	videoSetMode( MODE_5_2D | DISPLAY_BG3_ACTIVE );
	videoSetModeSub( MODE_5_2D | DISPLAY_BG3_ACTIVE );

	vramSetBankA( VRAM_A_MAIN_BG );
	vramSetBankC( VRAM_C_SUB_BG );

	// Initialise backgrounds
	bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
}

int main(int argc, char* argv[]) {
	initGfxMode();

	Bitmap bmp(100, 100);								// Bitmap we will draw to
	Rect rect(0, 0, 100, 100);							// Clipping region
	Graphics gfx(&bmp, rect);							// Graphics object we use to draw
	FrameBuffer buffer((u16*)BG_BMP_RAM(0), 256, 192);	// Frame buffer we will copy to
	
	// Draw a simple picture
	gfx.drawFilledRect(0, 0, 100, 100, woopsiRGB(0, 0, 0));
	gfx.drawLine(0, 0, 100, 100, woopsiRGB(10, 10, 10));
	gfx.drawEllipse(50, 50, 100, 50, woopsiRGB(31, 0, 0));
	
	// Blit the picture to the frame buffer
	Graphics* fbgfx = buffer.newGraphics();
	fbgfx->drawBitmap(0, 0, 100, 100, &bmp, 10, 10);
	delete fbgfx;
	
	while(1) {
		swiWaitForVBlank();
	}
	
	return 0;
}
