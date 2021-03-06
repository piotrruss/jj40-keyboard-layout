/*'########::'########::'##::::'##::'######:::'######:::::::'####:'########:
:: ##.... ##: ##.... ##: ##:::: ##:'##... ##:'##... ##::::::. ##::... ##..::
:: ##:::: ##: ##:::: ##: ##:::: ##: ##:::..:: ##:::..:::::::: ##::::: ##::::
:: ########:: ########:: ##:::: ##:. ######::. ######:::::::: ##::::: ##::::
:: ##.....::: ##.. ##::: ##:::: ##::..... ##::..... ##::::::: ##::::: ##::::
:: ##:::::::: ##::. ##:: ##:::: ##:'##::: ##:'##::: ##:'###:: ##::::: ##::::
:: ##:::::::: ##:::. ##:. #######::. ######::. ######:: ###:'####:::: ##::::
::..:::::::::..:::::..:::.......::::......::::......:::...::....:::::..:::*/
//My everyday layout that I use with i3wm

#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Del  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Tab,Sh|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  UP  |Entr,S|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Ctrl  |   -  | Alt,+|GUI,\ |Lower |  Spc |  Spc |Raise | /,Alt| LEFT | DOWN |RIGHT |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,    KC_Y,    KC_U,       KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,      KC_G,    KC_H,    KC_J,       KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  LSFT_T(KC_TAB), KC_Z, KC_X, KC_C,   KC_V,      KC_B,    KC_N,    KC_M,       KC_COMM, KC_DOT,  KC_UP,  RSFT_T(KC_ENT), \
  KC_LCTL, KC_MINS, ALT_T(KC_PLUS), LGUI_T(KC_BSLS), MO(_LOWER), KC_SPC, KC_SPC, MO(_RAISE), ALGR_T(KC_SLSH), KC_LEFT, KC_DOWN, KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      | GUI+1| GUI+2| GUI+3| GUI+4| GUI+5| GUI+6| GUI+7| GUI+8|	GUI+9| GUI+0| INSRT|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Stop | Vol+ | Next |  [   |   (  |   {  | Left | Down |  Up  |Right | PGUP | HOME |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Play/S| Vol- | Prev |  ]   |   )  |   }  |   0  |   ^  |   %  |   $  | PGDN | END  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Mute | Alt  | GUI  |Lower | RGB_T| RGB_M|Raise | LED  |LED_i |LED_d |PRNSCR|
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  _______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), KC_INS, \
  KC_MSTP, KC_VOLU,  KC_MNXT,  KC_LBRC,  KC_LPRN,  KC_LCBR,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_PGUP,  KC_HOME, \
  LSFT_T(KC_MPLY), KC_VOLD, KC_MPRV, KC_RBRC, KC_RPRN, KC_RCBR,  KC_0, KC_CIRC,  KC_PERC,  KC_DLR,   KC_PGDN,  KC_END, \
  KC_LCTL, KC_MUTE,  KC_LALT,  KC_LGUI,  _______,  RGB_TOG,  RGB_MOD,  _______,  BL_TOGG,  BL_INC,   BL_DEC,   KC_PSCR \
),

/* Rise
 * ,-----------------------------------------------------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   _  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      | Alt  | GUI  |Lower |      |      |Raise |      |      |      |      |  
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_EQL, \
  KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL, \
  KC_LSFT,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, \
  KC_LCTL,  _______, KC_LALT, KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______ \
)
};

// Loop
void matrix_scan_user(void) {
  // Empty
};
