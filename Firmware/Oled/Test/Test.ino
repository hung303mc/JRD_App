/*

  U8gLogo.pde
  
  Put the U8GLIB logo on the display.
  
  >>> Before compiling: Please remove comment from the constructor of the 
  >>> connected graphics display (see below).
  
  Universal 8bit Graphics Library, http://code.google.com/p/u8glib/
  
  Copyright (c) 2012, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
  
*/


#include "U8glib.h"


U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);	// I2C / TWI 

//#define MINI_LOGO

void drawColorBox(void)
{
  u8g_uint_t w,h;
  u8g_uint_t r, g, b;
  
  w = u8g.getWidth()/32;
  h = u8g.getHeight()/8;
  for( b = 0; b < 4; b++ )
    for( g = 0; g < 8; g++ )
      for( r = 0; r < 8; r++ )
      {
        u8g.setColorIndex((r<<5) |  (g<<2) | b );
        u8g.drawBox(g*w + b*w*8, r*h, w, h);
      }
}

void DrawHello(uint8_t d)
{
    u8g.setFont(u8g_font_gdr17r);
    u8g.drawStr(0+d, 22+d, "S");
    u8g.setFont(u8g_font_gdr17r);
    u8g.drawStr(17+d, 22+d, "i");
    u8g.setFont(u8g_font_gdr17r);
    u8g.drawStr(30+d,22+d,"z");
    u8g.setFont(u8g_font_gdr17r);
    u8g.drawStr(47+d, 22+d, "e");
    u8g.setFont(u8g_font_gdr17r);
    u8g.drawStr(60+d, 22+d, "1");
    u8g.setFont(u8g_font_gdr17r);
    u8g.drawStr(73+d, 22+d, "7");
}
void DrawHelloSmall(uint8_t d)
{
    u8g.setFont(u8g_font_gdr10r);
    u8g.drawStr(0+d, 44+d, "S");
    u8g.setFont(u8g_font_gdr10r);
    u8g.drawStr(10+d, 44+d, "i");
    u8g.setFont(u8g_font_gdr10r);
    u8g.drawStr(18+d,44+d,"z");
    u8g.setFont(u8g_font_gdr10r);
    u8g.drawStr(26+d, 44+d, "e");
    u8g.setFont(u8g_font_gdr10r);
    u8g.drawStr(34+d, 44+d, "1");
    u8g.setFont(u8g_font_gdr10r);
    u8g.drawStr(42+d, 44+d, "0");
}
void DrawHelloRange(uint8_t d)
{
    u8g.setFont(u8g_font_gdr10r);
    u8g.drawStr(0+d, 44+d, "M");
    u8g.setFont(u8g_font_gdr10r);
    u8g.drawStr(10+d, 44+d, "i");
    u8g.setFont(u8g_font_gdr10r);
    u8g.drawStr(18+d,44+d,"n");
    u8g.setFont(u8g_font_gdr10r);
    u8g.drawStr(26+d, 44+d, "9");
    u8g.setFont(u8g_font_gdr10r);
    u8g.drawStr(34+d, 44+d, "-");
    u8g.setFont(u8g_font_gdr10r);
    u8g.drawStr(42+d, 44+d, "M");
    u8g.setFont(u8g_font_gdr10r);
    u8g.drawStr(52+d, 44+d, "a");
    u8g.setFont(u8g_font_gdr10r);
    u8g.drawStr(62+d, 44+d, "x");
    u8g.setFont(u8g_font_gdr10r);
    u8g.drawStr(72+d, 44+d, "3");
    u8g.setFont(u8g_font_gdr10r);
    u8g.drawStr(82+d, 44+d, "0");
}

void draw(void) {
  // if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
  //   drawColorBox();
  // }
  // u8g.setColorIndex(1);
  // if ( U8G_MODE_GET_BITS_PER_PIXEL(u8g.getMode()) > 1 ) {
    DrawHello(2);
    DrawHelloSmall(2);
  //   // u8g.setColorIndex(2);
  //   drawLogo(1);
  //   // u8g.setColorIndex(3);
  // }
  // drawLogo(0);
  // drawURL();
  
}

void setup(void) {
  // flip screen, if required
  //u8g.setRot180();
}

void loop(void) {
  
  // picture loop
  u8g.firstPage();  
  do {
    draw();
  u8g.setColorIndex(1);
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(200);  
}

