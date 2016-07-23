// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#include "timer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

LEADER_EXTERNS();

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _COLEMAK 0
#define _QWERTY 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _MAUS 5
#define _PLOVER 6
#define _ADJUST 7

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define ENTER (OSM(MOD_RSFT))
#define SHIFT (OSM(MOD_LSFT))
#define ADJ1 (LT(_LOWER, KC_SPC))
#define ADJ2 (LT(_RAISE, KC_SPC))
#define ADJ3 (LT(_MAUS, KC_CAPS))
#define WANDOWS (LALT(LCTL(KC_DEL)))
#define TSKMNGR (LCTL(LSFT(KC_ESC)))
#define MINI  (LGUI(KC_DOWN))
#define MAXI  (LGUI(KC_UP))
#define LEFT  (LGUI(KC_LEFT))
#define RIGHT (LGUI(KC_RGHT))
#define HIDE  (LGUI(KC_D))
#define CLOSE  (LCTL(LSFT(KC_W)))
#define DESKTOP (LGUI(LCTL(KC_D)))
#define CLOZE (LGUI(LCTL(KC_F4)))
#define LOCK (LGUI(KC_L))
#define SNDUP (LCTL(KC_F2))
#define SNDDN (LCTL(KC_F1))
#define PLUS (LSFT(KC_EQL))
#define TILDE  (LSFT(KC_GRV))
#define EXIT   (LALT(KC_F4))
#define FILL  (LALT(KC_DEL))


enum {
  CT_CLN = 0,
  CT_QST,
  CT_QUT,
  ESC,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,   KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    TD(CT_CLN),   KC_BSPC},
  {ADJ3,    KC_A,    KC_R,    KC_S,    KC_T,   KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,         TD(CT_QUT) },
  {SHIFT,   KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  TD(CT_QST),   ENTER },
  {KC_LCTL, KC_LALT, KC_LGUI, KC_LEAD, ADJ1,   OSL(8),  KC_ENT,  ADJ2,    TG(9),   KC_ESC,  KC_LEFT,      KC_RGHT}
},

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {ADJ3,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TD(2),   TD(0) },
  {SHIFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  TD(1),   ENTER },
  {KC_LCTL, KC_LGUI, KC_LALT, KC_LEAD, ADJ1,    OSL(8), KC_ENT,   ADJ2,    TG(9),   KC_LEAD, KC_LEFT, KC_RGHT}
},

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_Q,    KC_W,    KC_F,    KC_P,   KC_G,    KC_ESC,  KC_BSPC,  KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, },
  {KC_A,    KC_R,    KC_S,    KC_T,   KC_D,    ADJ3,    KC_QUOT,  KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    },
  {KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    SHIFT,   ENTER,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, },
  {KC_LCTL, KC_LALT, KC_LGUI, ADJ1,   KC_BSPC, KC_LSFT, KC_RSFT,  KC_ENT,  ADJ2,    KC_LBRC, KC_RBRC, KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {TILDE,   KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______, KC_UNDS, KC_EQL,  KC_MINS, PLUS,    KC_BSPC},
  {_______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, _______, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_FN1,  KC_FN2,  KC_FN3,  KC_FN4,  _______, _______, KC_LBRC, KC_RBRC, WANDOWS, TSKMNGR, MO(7)  },
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_LBRC, KC_RBRC, KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS},
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY}
},

[5] = {
  {_______, KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,  _______, _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______},
  {_______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______},
  {_______, _______,    KC_LBRC,    KC_RBRC,     FILL,    _______, _______, _______, _______, _______, _______, _______},
  {_______, _______,    _______,    _______,     _______, _______, _______, _______, _______, _______, _______, _______}
},
/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |TogOut|   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = {
  {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[7] = {
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL},
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  PLOVER,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[8] = {
{_______, MINI,    MAXI,    LEFT,    RIGHT,   SNDUP,   _______, _______, _______, _______, _______, KC_PWR},
{_______, HIDE,    CLOSE,   DESKTOP, CLOZE,   SNDDN,   _______, _______, _______, _______, _______, _______},
{_______, LOCK,    KC_CALC, KC_SLEP, KC_MYCM, EXIT,    _______, _______, _______, _______, _______, _______},
{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

[9] = {
{_______, _______, _______, KC_E,    KC_R,    _______, KC_SLSH,  KC_7, KC_8,    KC_9,    KC_PSCR, _______},
{KC_CAPS, _______, KC_S,    KC_D,    KC_F,    KC_G,    KC_ASTR,  KC_4, KC_5,    KC_6,    KC_ENT,  KC_EQL},
{_______, _______, _______, _______, _______, _______, KC_MINS,  KC_1, KC_2,    KC_3,    KC_UP,   _______},
{_______, _______, _______, _______, KC_SPC, _______, PLUS,     KC_0, _______, KC_LEFT, KC_DOWN, KC_RGHT}
},
};


void COLON (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    register_code (KC_SCLN);
    unregister_code (KC_SCLN);
  } else {
    register_code (KC_RSFT);
    register_code (KC_SCLN);
    unregister_code (KC_SCLN);
    unregister_code (KC_RSFT);
    reset_tap_dance (state);
  }
}

void QUEST (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    register_code (KC_SLSH);
    unregister_code (KC_SLSH);
  } else {
    register_code (KC_RSFT);
    register_code (KC_SLSH);
    unregister_code (KC_SLSH);
    unregister_code (KC_RSFT);
    reset_tap_dance (state);
  }
}

void QUOTES (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    register_code (KC_QUOT);
    unregister_code (KC_QUOT);
  } else {
    register_code (KC_RSFT);
    register_code (KC_QUOT);
    unregister_code (KC_QUOT);
    unregister_code (KC_RSFT);
    reset_tap_dance (state);
  }
}

const qk_tap_dance_action_t tap_dance_actions[] = {
  [CT_QUT] = ACTION_TAP_DANCE_FN(QUOTES),
  [CT_QST] = ACTION_TAP_DANCE_FN(QUEST),
  [CT_CLN] = ACTION_TAP_DANCE_FN(COLON),
  [ESC] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
};

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_A) {
      register_code(KC_LCTL);
      register_code(KC_LSFT);
      register_code(KC_I);
      unregister_code(KC_I);
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_ESC) {
      register_code(KC_DEL);
      unregister_code(KC_DEL);
    }
    SEQ_ONE_KEY(KC_R) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_N);
      unregister_code(KC_N);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(KC_S) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_Z);
      unregister_code(KC_Z);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
    SEQ_TWO_KEYS(KC_A, KC_T) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_LSFT);
      register_code(KC_E);
      unregister_code(KC_E);
      unregister_code(KC_LSFT);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }
  }
}

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      break;
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_COLEMAK);
      }
      break;
      return false;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_DVORAK);
      }
      break;
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      break;
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      break;
      return false;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      break;
      return false;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_NOTE_ARRAY(tone_plover, false, 0);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      break;
      return false;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_plover_gb, false, 0);
        #endif
        layer_off(_PLOVER);
      }
      break;
      return false;
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
