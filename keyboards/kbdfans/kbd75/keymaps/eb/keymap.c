#include QMK_KEYBOARD_H


// Names of layers
#define _BASE 0
#define _FN 1
#define _NAV 2

// Custom Keycode names
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define ESCNAV LT(_NAV,KC_ESC)
#define ESCHPR MT(MOD_HYPR,KC_ESC)
#define CTLSLSH MT(MOD_LCTL,KC_SLSH)
#define ___ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Keymap _BASE: Default Layer
* ,-------------------------------------------------------------------------------.
* | Esc| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11| F12|Pscr| Ins|Home|
* |-------------------------------------------------------------------------------|
* | `  | 1  |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | Backspc |PgUp|
* |-------------------------------------------------------------------------------|
* | Tab  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ]  |  \   |Del |
* |-------------------------------------------------------------------------------|
* | Ctrl  |  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' |   Return  |PgUp|
* |-------------------------------------------------------------------------------|
* |  Shift   |  Z |  X |  C |  V |  B |  N |  M |  , |  . |Ctl/|  Shift | Up |PgDn|
* |-------------------------------------------------------------------------------|
* | Ctrl | Opt | Cmd |            Space             | FN | FN |Ctrl|Left|Down|Rght|
* `-------------------------------------------------------------------------------'
*/

[_BASE] = LAYOUT(

	ESCNAV ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR,KC_INS ,KC_HOME,
// |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|

	KC_GRV , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  , KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS, KC_EQL, KC_DEL,KC_BSPC,KC_PGUP,
// |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|

	   KC_TAB  , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  , KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_LBRC,KC_RBRC,   KC_BSLS ,KC_PGDN,
// |-----------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-----------+-------|

	   KC_LCTL   , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  , KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,      KC_ENT     , KC_END,
// |-------------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-----------------+-------|

	  KC_LSFT ,KC_NO, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  , KC_N  , KC_M  ,KC_COMM, KC_DOT,CTLSLSH,    KC_RSFT   , KC_UP , KC_DEL,
//|-----------------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+--------------+-------+-------|

	KC_LCTL  , KC_LALT, KC_LGUI,            KC_SPC, KC_SPC, KC_SPC                 ,MO(_FN),MO(_FN),KC_RALT,KC_LEFT,KC_DOWN,KC_RGHT
// +---------+--------+--------+---------------------------------------------------+-------+-------+-------+--------+-------+------+
),


/* Keymap _FN: Function Layer
* ,-------------------------------------------------------------------------------.
* Reset|    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
* |-------------------------------------------------------------------------------|
* |    |    |    |    |    |    |    |    |    |    |    |    |    |         |    |
* |-------------------------------------------------------------------------------|
* |      |OnOff|Mode|HueUp|HueDn|SatUp|SatDn|Brighter|Dimmmer|  | |  |  |    |    |
* |-------------------------------------------------------------------------------|
* |  Caps |    |    |    |    |    |    |    |    |    |    |    |           |    |
* |-------------------------------------------------------------------------------|
* |          |    |    |    |Dimmer|On/Off|Brighter|Step|    |   |   |   |   |    |
* |-------------------------------------------------------------------------------|
* |      |     |     |                              |    |    |    |    |    |    |
* `-------------------------------------------------------------------------------'
*/

/*
 *  Each segment in each comment row is below the input for the key associated to the
 *  given symbol.
 */

[_FN] =	LAYOUT(

	RESET  ,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
// |- ESC -|- F1 --|- F2 --|- F3 --|- F4 --|- F5 --|- F6 --|- F7 --|- F8 --|- F9 --|- F10 -|- F11 -|- F12 -| PSCR -|- INS -|- HOME-|

	_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
// |-------|---1---|---2---|---3---|---4---|---5---|---6---|---7---|---8---|---9---|---0---|-------|-------|-------|-------|-------|

	_______    ,RGB_TOG,RGB_MOD,RGB_HUI,RGB_HUD,RGB_SAI,RGB_SAD,RGB_VAI,RGB_VAD,_______,_______,_______,_______,  _______  ,_______,
// |--- TAB ---|---Q---|---W---|---E---|----R--|---T---|---Y---|---U---|---I---|---O---|---P---|-- [ --|-- ] --|----- \ ---|-------|

	   KC_CAPS   ,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______     ,_______,
// |-------------|-- A --|-- S --|-- D --|-- F --|-- G --|-- H --|-- J --|-- K --|-- L --|-- ; --|-- ' --|------- ENT -----|-------|

	_______ ,_______,_______,_______,BL_DEC ,BL_TOGG,BL_INC ,BL_STEP,_______,_______,_______,_______,    _______   ,_______,_______,
// |----- Shift ----|-- Z --|-- X --|-- C --|-- V --|-- B --|-- N --|-- M --|-- , --|-- . --|-- / --|--- Shift ----|-- UP -|- DEL -|

	 _______ ,_______ ,_______ ,      _______ ,  _______ , _______                 ,_______,_______,_______,_______,_______,_______
// |- CTRL --|-- OPT -|- CMD --|-------------------- SPACE ------------------------|- FNC -|- MENU-|- ALT -|- LEFT-|- DOWN |- RIGHT|
),


// Keymap _NAV: Navigation Layer


[_NAV] = LAYOUT(

	_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
// |- ESC -|- F1 --|- F2 --|- F3 --|- F4 --|- F5 --|- F6 --|- F7 --|- F8 --|- F9 --|- F10 -|- F11 -|- F12 -| PSCR -|- INS -|- HOME-|

	_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_BSPC,_______,_______,
// |-------|---1---|---2---|---3---|---4---|---5---|---6---|---7---|---8---|---9---|---0---|-------|-------|-------|-------|-------|

	_______    ,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  _______  ,_______,
// |--- TAB ---|---Q---|---W---|---E---|----R--|---T---|---Y---|---U---|---I---|---O---|---P---|-- [ --|-- ] --|----- \ ---|-------|

	  _______    ,_______,_______,_______,_______,_______,KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT,_______,_______,     _______     ,_______,
// |-------------|-- A --|-- S --|-- D --|-- F --|-- G --|-- H --|-- J --|-- K --|-- L --|-- ; --|-- ' --|------- ENT -----|-------|

	_______ ,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______   ,_______, KC_DEL,
// |----- Shift ----|-- Z --|-- X --|-- C --|-- V --|-- B --|-- N --|-- M --|-- , --|-- . --|-- / --|--- Shift ----|-- UP -|- DEL -|

	 _______ ,_______ ,_______ ,      _______ ,  _______ , _______                 ,_______,_______,_______,_______,_______,_______
// |- CTRL --|-- OPT -|- CMD --|-------------------- SPACE ------------------------|- FNC -|- MENU-|- ALT -|- LEFT-|- DOWN |- RIGHT|
),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {


	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		DDRB |= (1 << 2); PORTB &= ~(1 << 2);
	} else {
		DDRB &= ~(1 << 2); PORTB &= ~(1 << 2);
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_KANA)) {

	} else {

	}

}

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
