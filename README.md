# 34-Key Ferris Sweep Keymap

A clean, ergonomic keymap for the 34-key Ferris Sweep split keyboard, optimized for **Neovim**,
**Tiling Window Managers**, and **Tmux**.

---

## Layer Architecture Overview

The keymap defines four layers in `enum layer_t` within `keymap.c`:
- **`L_KBD`**: Base Alpha Layer
- **`L_NAV`**: Navigation, Movement & Number Layer
- **`L_SYM`**: Symbol Layer
- **`L_FUN`**: Function Layer

Thumb cluster keys on `L_KBD` act as layer switchers (via `LT()` layer-tap behaviour) and specialized controls (such as `CW_TOGG` for Caps Word), allowing instant access to navigation, symbol, and function layers while maintaining standard typing keys on tap.

---

## Keyboard Physical Layout

The Ferris Sweep features a split 3x5 column-staggered layout with 2 thumb keys per hand centred
towards the inner side of each half (under the index and inner-index columns):

```
Left Hand                                     Right Hand
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
Left Hand                                               Right Hand
[ KC_Q  ] [ KC_W  ] [ KC_E  ] [ KC_R  ] [ KC_T  ]       [ KC_Y  ] [ KC_U  ] [ KC_I  ] [ KC_O  ] [ KC_P  ]
[ MOD_A ] [ MOD_S ] [ MOD_D ] [ MOD_F ] [ KC_G  ]       [ KC_H  ] [ MOD_J ] [ MOD_K ] [ MOD_L ] [MOD_SCLN]
[ KC_Z  ] [ KC_X  ] [ KC_C  ] [ KC_V  ] [ KC_B  ]       [ KC_N  ] [ KC_M  ] [KC_COMM] [KC_DOT ] [KC_SLSH]
                              [LAY_SPC] [LAY_ESC]       [CW_TOGG] [LAY_ENT]
                              (Outer)   (Inner)         (Inner)   (Outer)
```

### Mod-Tap Definitions (`keymap.c`)

Holding any home row key applies the modifier; tapping sends the primary character:

| Define | Keycode Definition | Tap Key | Hold Modifier |
| :--- | :--- | :--- | :--- |
| **`MOD_A`** | `MT(MOD_LALT, KC_A)` | `a` | `LALT` (Left Alt) |
| **`MOD_S`** | `MT(MOD_LGUI, KC_S)` | `s` | `LGUI` (Left Super / Windows) |
| **`MOD_D`** | `MT(MOD_LSFT, KC_D)` | `d` | `LSFT` (Left Shift) |
| **`MOD_F`** | `MT(MOD_LCTL, KC_F)` | `f` | `LCTL` (Left Control) |
| **`MOD_J`** | `MT(MOD_RCTL, KC_J)` | `j` | `RCTL` (Right Control) |
| **`MOD_K`** | `MT(MOD_RSFT, KC_K)` | `k` | `RSFT` (Right Shift) |
| **`MOD_L`** | `MT(MOD_RGUI, KC_L)` | `l` | `RGUI` (Right Super / Windows) |
| **`MOD_SCLN`** | `MT(MOD_RALT, KC_SEMICOLON)` | `;` | `RALT` (Right Alt) |

### Thumb Cluster & Layer Switching (`keymap.c`)

Holding a layer-tap thumb key activates an alternate layer; tapping sends the primary key. Dedicated controls like Caps Word are directly toggleable:

| Define / Keycode | Keycode Definition | Tap Key / Action | Hold Action |
| :--- | :--- | :--- | :--- |
| **`LAY_SPC`** | `LT(L_SYM, KC_SPACE)` | `Space` (`KC_SPACE`) | Activate **`L_SYM`** (Symbol Layer) |
| **`LAY_ESC`** | `LT(L_NAV, KC_ESC)` | `Escape` (`KC_ESC`) | Activate **`L_NAV`** (Navigation Layer) |
| **`CW_TOGG`** | `CW_TOGG` | Caps Word Toggle | — |
| **`LAY_ENT`** | `LT(L_FUN, KC_ENTER)` | `Enter` (`KC_ENTER`) | Activate **`L_FUN`** (Function Layer) |

- **`LAY_SPC`** (`LT(L_SYM, KC_SPACE)`) — **Outer Left Thumb**:
  - **Tap**: `KC_SPACE` (Space key, primary resting position).
  - **Hold**: Switches to **`L_SYM`** (Symbol Layer).
- **`LAY_ESC`** (`LT(L_NAV, KC_ESC)`) — **Inner Left Thumb**:
  - **Tap**: `KC_ESC` (Escape key, returns to Normal mode in Neovim).
  - **Hold**: Switches to **`L_NAV`** (Navigation, Movement & Number Layer).
- **`CW_TOGG`** (`CW_TOGG`) — **Inner Right Thumb**:
  - **Tap**: Toggles QMK **Caps Word**, capitalizing all alphanumeric characters until a delimiter (e.g., whitespace or symbol) or Escape is pressed. Ideal for `CONSTANT_CASE` identifiers without holding Shift.
- **`LAY_ENT`** (`LT(L_FUN, KC_ENTER)`) — **Outer Right Thumb**:
  - **Tap**: `KC_ENTER` (Enter key, primary resting position).
  - **Hold**: Switches to **`L_FUN`** (Function Layer).

---

## Layer 1: Navigation, Movement & Number Layer (`L_NAV`)

Activated by **holding the Inner Left Thumb (`LAY_ESC`)**.

```
Left Hand                                               Right Hand
[ KC_1  ] [ KC_2  ] [ KC_3  ] [ KC_4  ] [ KC_5  ]       [ KC_6  ] [ KC_7  ] [ KC_8  ] [ KC_9  ] [ KC_0  ]
[KC_TRNS] [KC_TRNS] [KC_TRNS] [KC_TRNS] [ KC_NO ]       [KC_LEFT] [KC_DOWN] [ KC_UP ] [KC_RIGHT] [KC_DEL]
[ KC_NO ] [ KC_NO ] [ KC_NO ] [ KC_NO ] [ KC_NO ]       [ KC_NO ] [ KC_NO ] [ KC_NO ] [ KC_NO ] [ KC_NO ]
                              [ KC_NO ] [KC_TRNS]       [ LCTL(KC_B)  ] [OSM(MOD_LGUI)]
                                        (Held)          (Tmux Prefix)   (WM Workspaces)
```

### Features

#### 1. Top Number Row
- Numbers `KC_1` through `KC_5` on the left hand, and `KC_6` through `KC_0` on the right hand.
- Hold `LAY_ESC` and tap any digit to input numbers without requiring a separate numeric keypad.

#### 2. Neovim `HJKL` Navigation & Editing
- Mapped directly to the right hand home row:
  - `H` $\rightarrow$ Left Arrow (`KC_LEFT`)
  - `J` $\rightarrow$ Down Arrow (`KC_DOWN`)
  - `K` $\rightarrow$ Up Arrow (`KC_UP`)
  - `L` $\rightarrow$ Right Arrow (`KC_RIGHT`)
  - `;` (Pinky) $\rightarrow$ Delete (`KC_DEL`) for quick forward deletion while navigating.

#### 3. Workspace Switching & Tmux Navigation
- **Tmux Windows (`Ctrl + b`, then `Num`)**:
  - Hold `LAY_ESC` $\rightarrow$ tap **Inner Right Thumb** (`LCTL(KC_B)`) $\rightarrow$ tap number (`1` ... `0`).
  - Sends the standard Tmux prefix `Ctrl + b` without releasing the layer, allowing immediate window selection with the top number row.
- **Tiling Window Manager Workspaces (`Super + Num`)**:
  - Hold `LAY_ESC` $\rightarrow$ tap **Outer Right Thumb** (`OSM(MOD_LGUI)`) $\rightarrow$ tap number (`1` ... `0`).
  - One-shot modifier arms `Super` (`LGUI`) with a single tap, applies to the number, and unarms automatically. Perfect for workspace switching in tiling window managers (e.g., Sway, i3, Hyprland).

#### 4. Modifier Chording (`KC_TRNS`)
- The left home row mods (`MOD_A`, `MOD_S`, `MOD_D`, `MOD_F`) fall through from `L_KBD` via `KC_TRNS`, enabling seamless two-hand combinations:
  - `Shift + HJKL`: Hold `MOD_D` (Shift) + press arrows for text selection.
  - `Ctrl + HJKL`: Hold `MOD_F` (Ctrl) + press arrows for split/window navigation in Vim or Tmux.
  - `Alt + HJKL`: Hold `MOD_A` (Alt) + press arrows for word-by-word jumping.
  - `Super + HJKL`: Hold `MOD_S` (GUI) + press arrows for window manager focus shifting.

#### 5. Ergonomic Safety Rails (`KC_NO`)
- All unused positions (bottom row alphas, left inner column, and unused thumbs) are mapped to `KC_NO` (No-Operation).
- Accidental slips or brushes do not send stray characters or trigger destructive commands in Neovim.

---

## Layer 2: Symbol Layer (`L_SYM`)

Activated by **holding the Outer Left Thumb (`LAY_SPC`)**.

```
Left Hand                                               Right Hand
[KC_EXLM] [ KC_AT ] [KC_LCBR] [KC_RCBR] [KC_PIPE]       [KC_BSLS] [KC_PLUS] [KC_MINS] [KC_ASTR] [KC_SLSH]
[KC_HASH] [ KC_DLR] [KC_LPRN] [KC_RPRN] [KC_TILD]       [KC_UNDS] [KC_COLN] [ KC_EQL] [KC_DQUO] [KC_QUOT]
[KC_PERC] [KC_CIRC] [KC_LBRC] [KC_RBRC] [ KC_GRV]       [KC_SCLN] [ KC_LT ] [ KC_GT ] [KC_QUES] [KC_AMPR]
                              [KC_TRNS] [ KC_NO ]       [ KC_TAB] [KC_BSPC]
                              (Held)                    (Tab)     (Backspace)
```

### Features

#### 1. Paired Enclosures on Strong Fingers
Opening and closing brackets, braces, and parentheses are symmetrically placed next to each other on the agile middle and index columns:
- **Curly Braces**: `{` (`KC_LCBR`) and `}` (`KC_RCBR`) on the top row.
- **Parentheses**: `(` (`KC_LPRN`) and `)` (`KC_RPRN`) on the home row.
- **Square Brackets**: `[` (`KC_LBRC`) and `]` (`KC_RBRC`) on the bottom row.
- **Angle Brackets**: `<` (`KC_LT`) and `>` (`KC_GT`) on the right-hand bottom row.

#### 2. Programming, Syntax & Arithmetic Operators
- **Mathematical Operators**: `+` (`KC_PLUS`), `-` (`KC_MINS`), `*` (`KC_ASTR`), and `/` (`KC_SLSH`) grouped on the right-hand top row.
- **Assignment & Delimiters**: Underscore `_` (`KC_UNDS`), colon `:` (`KC_COLN`), and equals `=` (`KC_EQL`) on the right-hand home row.
- **Quotes**: Double quote `"` (`KC_DQUO`) and single quote `'` (`KC_QUOT`) positioned on the right-hand ring and pinky home row.
- **Slashes & Piping**: Pipe `|` (`KC_PIPE`) and backslash `\` (`KC_BSLS`) meet on the inner columns of the top row.
- **Shell & Regex Symbols**: Exclamation mark `!` (`KC_EXLM`), at `@` (`KC_AT`), hash `#` (`KC_HASH`), dollar `$` (`KC_DLR`), percent `%` (`KC_PERC`), caret `^` (`KC_CIRC`), tilde `~` (`KC_TILD`), grave / backtick `` ` `` (`KC_GRV`), semicolon `;` (`KC_SCLN`), question mark `?` (`KC_QUES`), and ampersand `&` (`KC_AMPR`).

#### 3. Thumb Cluster in Symbol Mode
- **`KC_TAB`** (Inner Right Thumb) and **`KC_BSPC`** (Outer Right Thumb) allow immediate code indentation and error correction while typing code expressions without releasing the layer.
- The inner left thumb is deactivated (`KC_NO`) to prevent accidental mispresses while holding `LAY_SPC`.

### Keymap Quick Reference

| Hand | Finger | Top Row | Home Row | Bottom Row |
| :--- | :--- | :--- | :--- | :--- |
| **Left** | Pinky | `!` (`KC_EXLM`) | `#` (`KC_HASH`) | `%` (`KC_PERC`) |
| | Ring | `@` (`KC_AT`) | `$` (`KC_DLR`) | `^` (`KC_CIRC`) |
| | Middle | `{` (`KC_LCBR`) | `(` (`KC_LPRN`) | `[` (`KC_LBRC`) |
| | Index | `}` (`KC_RCBR`) | `)` (`KC_RPRN`) | `]` (`KC_RBRC`) |
| | Inner | `\|` (`KC_PIPE`) | `~` (`KC_TILD`) | `` ` `` (`KC_GRV`) |
| **Right** | Inner | `\` (`KC_BSLS`) | `_` (`KC_UNDS`) | `;` (`KC_SCLN`) |
| | Index | `+` (`KC_PLUS`) | `:` (`KC_COLN`) | `<` (`KC_LT`) |
| | Middle | `-` (`KC_MINS`) | `=` (`KC_EQL`) | `>` (`KC_GT`) |
| | Ring | `*` (`KC_ASTR`) | `"` (`KC_DQUO`) | `?` (`KC_QUES`) |
| | Pinky | `/` (`KC_SLSH`) | `'` (`KC_QUOT`) | `&` (`KC_AMPR`) |

---

## Layer 3: Function Layer (`L_FUN`)

Activated by **holding the Outer Right Thumb (`LAY_ENT`)**.

```
Left Hand                                               Right Hand
[ KC_F1 ] [ KC_F2 ] [ KC_F3 ] [ KC_F4 ] [ KC_F5 ]       [ KC_F6 ] [ KC_F7 ] [ KC_F8 ] [ KC_F9 ] [KC_F10 ]
[KC_TRNS] [KC_TRNS] [KC_TRNS] [KC_TRNS] [KC_F11 ]       [KC_F12 ] [KC_TRNS] [KC_TRNS] [KC_TRNS] [KC_TRNS]
[KC_TRNS] [KC_TRNS] [KC_TRNS] [KC_TRNS] [KC_TRNS]       [KC_TRNS] [KC_TRNS] [KC_TRNS] [KC_TRNS] [KC_TRNS]
                              [ KC_NO ] [ KC_NO ]       [ KC_NO ] [KC_TRNS]
                                                                  (Held)
```

### Features

#### 1. Complete F1–F12 Function Keys
- Full function key row without adding extra physical rows:
  - **Left Top Row**: `KC_F1` through `KC_F5`.
  - **Right Top Row**: `KC_F6` through `KC_F10`.
  - **Inner Columns (Home Row)**: `KC_F11` (left inner index) and `KC_F12` (right inner index), placed conveniently within easy index reach.

#### 2. Modifier Chording Fallthrough (`KC_TRNS`)
- Home row modifier positions and bottom row keys are mapped to `KC_TRNS`, allowing seamless combinations:
  - `Alt + F4` (Window close): Hold `MOD_A` (Alt) + tap `KC_F4`.
  - `Shift + F10` / `Ctrl + F5` (IDE debugging/refactoring shortcuts): Seamlessly chord modifiers while holding the function layer thumb key.

### Keymap Quick Reference

| Hand | Finger | Top Row | Home Row | Bottom Row |
| :--- | :--- | :--- | :--- | :--- |
| **Left** | Pinky | `F1` (`KC_F1`) | *Fallthrough (`KC_TRNS`)* | *Fallthrough (`KC_TRNS`)* |
| | Ring | `F2` (`KC_F2`) | *Fallthrough (`KC_TRNS`)* | *Fallthrough (`KC_TRNS`)* |
| | Middle | `F3` (`KC_F3`) | *Fallthrough (`KC_TRNS`)* | *Fallthrough (`KC_TRNS`)* |
| | Index | `F4` (`KC_F4`) | *Fallthrough (`KC_TRNS`)* | *Fallthrough (`KC_TRNS`)* |
| | Inner | `F5` (`KC_F5`) | `F11` (`KC_F11`) | *Fallthrough (`KC_TRNS`)* |
| **Right** | Inner | `F6` (`KC_F6`) | `F12` (`KC_F12`) | *Fallthrough (`KC_TRNS`)* |
| | Index | `F7` (`KC_F7`) | *Fallthrough (`KC_TRNS`)* | *Fallthrough (`KC_TRNS`)* |
| | Middle | `F8` (`KC_F8`) | *Fallthrough (`KC_TRNS`)* | *Fallthrough (`KC_TRNS`)* |
| | Ring | `F9` (`KC_F9`) | *Fallthrough (`KC_TRNS`)* | *Fallthrough (`KC_TRNS`)* |
| | Pinky | `F10` (`KC_F10`) | *Fallthrough (`KC_TRNS`)* | *Fallthrough (`KC_TRNS`)* |

---

## Building and Flashing the Firmware

### Compiling

To compile this keymap using the QMK CLI:

```bash
qmk compile -kb ferris/sweep -km danick
```

### Flashing with `EE_HANDS`

This configuration uses `EE_HANDS` and `SPLIT_USB_DETECT` so you can connect the USB cable to either half without the keymap mirroring or flipping.

Because handedness is stored in EEPROM, flash each Pro Micro with its corresponding side target:

- **Left half**:
  ```bash
  qmk flash -kb ferris/sweep -km danick -bl avrdude-split-left
  ```
- **Right half**:
  ```bash
  qmk flash -kb ferris/sweep -km danick -bl avrdude-split-right
  ```

*(Or using `make`: `make ferris/sweep:danick:avrdude-split-left` and `make ferris/sweep:danick:avrdude-split-right`).*
