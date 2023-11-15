#include "shortcut.h"
#include "board_def.h"
#include "app/app_key.h"

static void init(void *data)
{
 
	// bleKeyboard.begin();
}

static void enter(void *data)
{
	// insert code
	int16_t x1;
	int16_t y1;
	uint16_t w;
	uint16_t h;

	gfx1->fillScreen(BLACK);
	gfx2->fillScreen(BLACK);
	gfx3->fillScreen(BLACK);

	myDrawPNG(24, 0, "/shortcut/select_all_48px.png", 0);
	myDrawPNG(24, 0, "/shortcut/copy_48px.png", 1);
	myDrawPNG(24, 0, "/shortcut/paste_48px.png", 2);


	gfx[0]->setTextColor(BLUE>>1);
	// gfx[0]->setFont(u8g2_font_10x20_mr); 	
	gfx[0]->setFont(&Orbitron_Medium_12);
	gfx[0]->getTextBounds("SelectAll", 0, 0, &x1, &y1, &w, &h);	
	gfx[0]->setCursor((OLED_WIDTH - w) / 2, 63);
	gfx[0]->print("SelectAll");

	gfx[1]->setTextColor(BLUE>>1);
	// gfx[1]->setFont(u8g2_font_10x20_mr); 	
	gfx[1]->setFont(&Orbitron_Medium_12);
	gfx[1]->getTextBounds("Copy", 0, 0, &x1, &y1, &w, &h);	
	gfx[1]->setCursor((OLED_WIDTH - w) / 2, 63);
	gfx[1]->print("Copy");


	gfx[2]->setTextColor(BLUE>>1);
	// gfx[2]->setFont(u8g2_font_10x20_mr); 	
	gfx[2]->setFont(&Orbitron_Medium_12);
	gfx[2]->getTextBounds("Paste", 0, 0, &x1, &y1, &w, &h);	
	gfx[2]->setCursor((OLED_WIDTH - w) / 2, 63);
	gfx[2]->print("Paste");


	// while (bleKeyboard.isConnected() == false)
	// {
	// 	delay(20);
	// }
 

	
	// gfx[0]->setFont(u8g2_font_4x6_mr);
	// gfx[0]->drawChar(0, 6, 'B', BLUE, BLACK);

	//
	manager_setBusy(false);
}

static void loop(void *data)
{
	KEY_TYPE key;
	key = app_key_get();
	switch (key)
	{

	case KEY1_DOWN:
		if (bleKeyboard.isConnected())
		{

			bleKeyboard.press(KEY_LEFT_CTRL);
			bleKeyboard.press('a');
			bleKeyboard.release('a');
            bleKeyboard.release(KEY_LEFT_CTRL);
			 

		}
		break;
	case KEY2_DOWN:
		if (bleKeyboard.isConnected())
		{

			bleKeyboard.press(KEY_LEFT_CTRL);
			bleKeyboard.press('c');
			bleKeyboard.release('c');
            bleKeyboard.release(KEY_LEFT_CTRL);

		}
		break;
	case KEY3_DOWN:
		if (bleKeyboard.isConnected())
		{

			bleKeyboard.press(KEY_LEFT_CTRL);
			bleKeyboard.press('v');
			bleKeyboard.release('v');
            bleKeyboard.release(KEY_LEFT_CTRL);

		}
		break;

	 

	case KEY4_LONG:				  //长按
		manager_switchToParent(); //进入父项目 //退出
		break;
	default:
		break;
	}
}

static void exit(void *data)
{
	// insert code
	
	// bleKeyboard.end();
	//
	manager_setBusy(true);
}

#include "img.h"
page_t page_shortcut = {
	.init = init,
	.enter = enter,
	.exit = exit,
	.loop = loop,
	.title_en = "shortcut",
	.title_cn = "快捷键",
	.icon = img_bits,
	.icon_width = img_width,
	.icon_height = img_height,
	.sleep_enable = false,
	.wakeup_btn_effect_enable = false,
	.acc_enable = false,

};