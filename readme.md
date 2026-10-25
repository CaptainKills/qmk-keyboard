# 34-Key Ferris Sweep Keymap

A clean, ergonomic keymap for the 34-key Ferris Sweep split keyboard, optimized for **Neovim**,
**Linux Desktop Environment workspace switching**, and **Tmux window navigation**.

---

## Layer Architecture Overview

The keymap defines four layers in `enum layer_t` within `keymap.c`:
- **`L_KBD`**: Base Alpha Layer
- **`L_NAV`**: Navigation, Movement & Number Layer
- **`L_SYM`**: Symbol Layer *(reserved for future implementation)*
- **`L_FUN`**: Function Layer *(reserved for future implementation)*

Thumb cluster keys on `L_KBD` act as layer switchers (via `LT()` layer-tap behaviour), allowing
instant access to navigation and future symbol/function layers while maintaining standard typing
keys on tap.

---

## Keyboard Physical Layout

The Ferris Sweep features a split 3x5 column-staggered layout with 2 thumb keys per hand centred
towards the inner side of each half (under the index and inner-index columns):

```
Left Hand                                                Right Hand
[  0  ] [  1  ] [  2  ] [  3  ] [  4  ]       [  4  ] [  3  ] [  2  ] [  1  ] [  0  ]
(Pinky) (Ring)  (Mid)   (Index) (Inner)       (Inner) (Index) (Mid)   (Ring)  (Pinky)
[     ] [     ] [     ] [     ] [     ]       [     ] [     ] [     ] [     ] [     ]
[     ] [     ] [     ] [     ] [     ]       [     ] [     ] [     ] [     ] [     ]
[     ] [     ] [     ] [     ] [     ]       [     ] [     ] [     ] [     ] [     ]
                        [ T1  ] [ T2  ]       [ T3  ] [ T4  ]
                        (Outer) (Inner)       (Inner) (Outer)
```

---

## Layer 0: Base Alpha Layer (`L_KBD`)

The base layer uses standard **QWERTY** alphas combined with **Home Row Mods (HRM)** and centred
thumb keys.

```
Left Hand                                                Right Hand
[ KC_Q  ] [ KC_W  ] [ KC_E  ] [ KC_R  ] [ KC_T  ]       [ KC_Y  ] [ KC_U  ] [ KC_I  ] [ KC_O  ] [ KC_P  ]
[ MOD_A ] [ MOD_S ] [ MOD_D ] [ MOD_F ] [ KC_G  ]       [ KC_H  ] [ MOD_J ] [ MOD_K ] [ MOD_L ] [MOD_SCLN]
[ KC_Z  ] [ KC_X  ] [ KC_C  ] [ KC_V  ] [ KC_B  ]       [ KC_N  ] [ KC_M  ] [KC_COMM] [KC_DOT ] [KC_SLSH]
                              [NAV_ESC] [KC_SPC ]       [KC_ENT ] [KC_BSPC]
                              (Outer)   (Inner)         (Inner)   (Outer)
```

### Mod-Tap Definitions (`keymap.c`)

Holding any home row key applies the modifier; tapping sends the primary character:


| Define | Keycode Definition | Tap Key | Hold Modifier |
| :--- | :--- | :--- | :--- |
| **`MOD_A`** | `MT(MOD_LGUI, KC_A)` | `a` | `LGUI` (Super / Windows) |
| **`MOD_S`** | `MT(MOD_LALT, KC_S)` | `s` | `LALT` (Left Alt) |
| **`MOD_D`** | `MT(MOD_LSFT, KC_D)` | `d` | `LSFT` (Left Shift) |
| **`MOD_F`** | `MT(MOD_LCTL, KC_F)` | `f` | `LCTL` (Left Control) |
| **`MOD_J`** | `MT(MOD_RCTL, KC_J)` | `j` | `RCTL` (Right Control) |
| **`MOD_K`** | `MT(MOD_RSFT, KC_K)` | `k` | `RSFT` (Right Shift) |
| **`MOD_L`** | `MT(MOD_RALT, KC_L)` | `l` | `RALT` (Right Alt) |
| **`MOD_SCLN`** | `MT(MOD_RGUI, KC_SEMICOLON)` | `;` | `RGUI` (Right GUI) |

### Layer-Tap & Thumb Cluster (`keymap.c`)

- **`NAV_ESC`** (`LT(L_NAV, KC_ESC)`):
  - **Tap**: `KC_ESC` (drops to Normal mode in Neovim).
  - **Hold**: Switches to **`L_NAV`** (Navigation, Movement & Number Layer).
- **`KC_SPC`**: Space key (home resting position), planned to serve as layer switch for `L_SYM`
  (Symbol Layer).
- **`KC_ENT`**: Enter key (home resting position), planned to serve as layer switch for `L_FUN`
  (Function Layer).
- **`KC_BSPC`**: Backspace key.

---

## Layer 1: Navigation, Movement & Number Layer (`L_NAV`)

Activated by **holding the Outer Left Thumb (`NAV_ESC`)**.

```
Left Hand                                                Right Hand
[ KC_1  ] [ KC_2  ] [ KC_3  ] [ KC_4  ] [ KC_5  ]       [ KC_6  ] [ KC_7  ] [ KC_8  ] [ KC_9  ] [ KC_0  ]
[KC_TRNS] [KC_TRNS] [KC_TRNS] [KC_TRNS] [ KC_NO ]       [KC_LEFT] [KC_DOWN] [ KC_UP ] [KC_RGHT] [ KC_NO ]
[ KC_NO ] [ KC_NO ] [ KC_NO ] [ KC_NO ] [ KC_NO ]       [ KC_NO ] [ KC_NO ] [ KC_NO ] [ KC_NO ] [ KC_NO ]
                              [KC_TRNS] [ KC_NO ]       [OSM(MOD_LCTL)] [OSM(MOD_LALT)]
                              (Held)                    (Tmux Windows)  (DE Workspaces)
```

### Features

#### 1. Top Number Row

- Numbers `KC_1` through `KC_5` on the left hand, and `KC_6` through `KC_0` on the right hand.
- Hold `NAV_ESC` and tap any digit to input numbers without requiring a separate numeric keypad.

#### 2. Neovim `HJKL` Navigation

- Mapped directly to the right hand home row:
  - `H` $\rightarrow$ Left Arrow (`KC_LEFT`)
  - `J` $\rightarrow$ Down Arrow (`KC_DOWN`)
  - `K` $\rightarrow$ Up Arrow (`KC_UP`)
  - `L` $\rightarrow$ Right Arrow (`KC_RGHT`)

#### 3. One-Shot Modifiers for Workspaces & Tmux (No Holding Required)

- **Desktop Environment Workspaces (`Alt + Num`)**:
  - Hold `NAV_ESC` $\rightarrow$ tap **Outer Right Thumb** (`OSM(MOD_LALT)`) $\rightarrow$ tap
    number (`1` ... `0`).
  - The modifier is armed with a single tap, applies to the number, and unarms automatically.
- **Tmux Windows (`Ctrl + Num`)**:
  - Hold `NAV_ESC` $\rightarrow$ tap **Inner Right Thumb** (`OSM(MOD_LCTL)`) $\rightarrow$ tap
    number (`1` ... `0`).
  - Instantly switches Tmux window without needing 3-finger chording.

#### 4. Modifier Chording (`KC_TRNS`)

- The left home row mods (`MOD_A`, `MOD_S`, `MOD_D`, `MOD_F`) fall through from `L_KBD` via
  `KC_TRNS`, enabling seamless two-hand combinations:
  - `Shift + HJKL`: Hold `MOD_D` (Shift) + press arrows for text selection.
  - `Ctrl + HJKL`: Hold `MOD_F` (Ctrl) + press arrows for split/window navigation in Vim or Tmux.
  - `Alt + HJKL`: Hold `MOD_S` (Alt) + press arrows for word-by-word jumping.

#### 5. Ergonomic Safety Rails (`KC_NO`)

- All unused positions (bottom row alphas and inner columns) are mapped to `KC_NO` (No-Operation).
- Accidental slips or brushes do not send stray characters or trigger destructive commands in
  Neovim.

---

## Building the Firmware

To compile this keymap using the QMK CLI:

```bash
qmk compile -kb ferris/sweep -km <name>
```
