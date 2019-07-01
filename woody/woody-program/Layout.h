#pragma once

#include "Leds.h"

#define CODE_TYPE    ( 0xF0000000 )
#define EVENT_TYPE   ( 0X0F000000 )
#define CODE_DATA    ( 0x00FFFFFF )

enum LayoutEvents {
  BOTH_EVENTS =     ( 0X00000000 ),
  BOTH_ON_EVENTS =  ( 0X01000000 ),
  BOTH_OFF_EVENTS = ( 0X02000000 ),
  ON_EVENTS =       ( 0X03000000 ),
  OFF_EVENTS =      ( 0X04000000 ),
  NO_EVENTS =       ( 0X05000000 ),
};

#define LAYOUT_CODE      ( 0x10000000 )
#define LAYOUT_CODE_TYPE ( 0x00F00000 )
#define LAYOUT_CODE_DATA ( 0x0000FFFF )

enum LayoutCodes {
  EMPTY_LAYER = ( 0x00000000 | LAYOUT_CODE ), // Do nothing / fall through layer
  ____ =       ( 0x00000000 | LAYOUT_CODE ), // Same as above; readability
  LAYER =      ( 0x00100000 | LAYOUT_CODE ),
};

#define NUM_LAYERS 2
#define NUM_EVENTS 94

unsigned long Layout[NUM_LAYERS][NUM_EVENTS] = {
  {
    KEY_ESC, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12, ( LED_TOGGLE | ON_EVENTS ), KEY_MEDIA_PLAY_PAUSE, KEY_MEDIA_MUTE, ____,
    KEY_TILDE, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0, KEY_MINUS, KEY_EQUAL, KEY_BACKSPACE, KEY_INSERT, KEY_HOME, KEY_PAGE_UP,
    KEY_TAB, KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P, KEY_LEFT_BRACE, KEY_RIGHT_BRACE, KEY_BACKSLASH, KEY_DELETE, KEY_END, KEY_PAGE_DOWN,
    KEY_CAPS_LOCK, KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_H, KEY_J, KEY_K, KEY_L, KEY_SEMICOLON, KEY_QUOTE, KEY_ENTER,
    MODIFIERKEY_SHIFT, KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEY_N, KEY_M, KEY_COMMA, KEY_PERIOD, KEY_SLASH, MODIFIERKEY_RIGHT_SHIFT, KEY_UP_ARROW,
    MODIFIERKEY_CTRL, MODIFIERKEY_GUI, MODIFIERKEY_ALT, KEY_SPACE, MODIFIERKEY_RIGHT_ALT, MODIFIERKEY_RIGHT_GUI, ( LAYER | 1 ), MODIFIERKEY_RIGHT_CTRL, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW,
    ( LED_INC | ON_EVENTS ), ( LED_DEC | ON_EVENTS ),
    ( KEY_MEDIA_VOLUME_INC | BOTH_ON_EVENTS ), ( KEY_MEDIA_VOLUME_DEC | BOTH_ON_EVENTS ),
    ( KEY_MEDIA_NEXT_TRACK | BOTH_ON_EVENTS ), ( KEY_MEDIA_PREV_TRACK | BOTH_ON_EVENTS ),
  },
  {
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ( LED_SYNC_GAME | ON_EVENTS ), ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ( LAYER | 0 ), ____, ____, ____, ____,
    ( LED_INC_GAME | ON_EVENTS ), ( LED_DEC_GAME | ON_EVENTS ), ____, ____, ____, ____,
  }
};
