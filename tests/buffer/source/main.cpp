#include <nds.h>
#include "bufferedbitmap.h"
#include "framebuffer.h"
#include "graphics.h"
#include "newtopaz.h"

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

	BufferedBitmap bmp(100, 100);						// Bitmap we will draw to
	Rect rect(0, 0, 100, 100);							// Clipping region
	Graphics gfx(&bmp, rect);							// Graphics object we use to draw
	FrameBuffer buffer((u16*)BG_BMP_RAM(0), 256, 192);	// Frame buffer we will copy to
	NewTopaz font;										// Font we will write with
	
	// Draw a simple picture
	gfx.drawFilledRect(0, 0, 100, 100, woopsiRGB(5, 5, 5));		// Clear background
	gfx.drawLine(0, 0, 100, 100, woopsiRGB(0, 31, 10));			// Green cross
	gfx.drawLine(100, 0, 0, 100, woopsiRGB(0, 31, 10));			// Green cross
	gfx.drawFilledRect(20, 20, 20, 60, woopsiRGB(5, 5, 20));	// Blue box
	gfx.drawFilledEllipse(50, 50, 20, 10, woopsiRGB(31, 0, 0));	// Red ellipse
	gfx.drawFilledRect(10, 80, 60, 5, woopsiRGB(10, 20, 10));	// Green box
	gfx.floodFill(90, 50, woopsiRGB(10, 10, 10));				// Fill right triangle
	gfx.floodFill(50, 90, woopsiRGB(15, 15, 15));				// Fill bottom triangle
	gfx.floodFill(0, 50, woopsiRGB(20, 20, 20));				// Fill left triangle
	gfx.dim(80, 0, 20, 100);									// Dim right edge
	gfx.drawLine(80, 0, 80, 100, woopsiRGB(20, 20, 20));		// Right edge border
	
	gfx.drawText(17, 0, &font, "Hello World!", 0, 17, woopsiRGB(31, 31, 31));		// Top text
	gfx.drawText(0, 90, &font, "This is some text", 0, 17, woopsiRGB(31, 31, 31));	// Bottom text
	
	gfx.drawFilledXORRect(0, 0, 50, 100, woopsiRGB(31, 0, 0));	// XOR left of bitmap against red
	
	// Buffer the current bitmap contents
	bmp.buffer();
		
	// Get a graphics object to draw to the frame buffer
	Graphics* fbgfx = buffer.newGraphics();
	
	s16 x = 0;
	s16 y = 0;
	s16 xAdd = 1;
	
	while(1) {
		swiWaitForVBlank();
		
		x += xAdd;
		
		if (x < 0) {
			x = 0;
			xAdd = 1;
		} else if (x > bmp.getWidth() - 1) {
			x = bmp.getWidth() - 1;
			xAdd = -1;
		}
		
		gfx.drawLine(x, y, 50, 50, woopsiRGB(31, 0, 0));
		
		// Draw the bitmap to the framebuffer
		fbgfx->drawBitmap(10, 10, 100, 100, &bmp, 0, 0);
		
		bmp.unbuffer();
	}
	
	// Clean up the framebuffer graphics object
	delete fbgfx;
	
	return 0;
}
