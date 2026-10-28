# 34-Key Ferris Sweep Keymap

A clean, ergonomic keymap for the 34-key Ferris Sweep split keyboard, optimized for **Neovim**,
**Tiling Window Managers**, and **Tmux**.

---

## Layer Architecture Overview

The keymap defines four layers in `enum layer_t` within `keymap.c`:
- **`L_KBD`**: Base Alpha Layer
- **`L_NAV`**: Navigation, Movement & Number Layer
- **`L_SYM`**: Symbol Layer
- **`L_FUN`**: Function Layer *(reserved for future implementation)*

Thumb cluster keys on `L_KBD` act as layer switchers (via `LT()` layer-tap behaviour), allowing
instant access to navigation and symbol layers while maintaining standard typing keys on tap.

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
                              [LAY_ESC] [LAY_SPC]       [LAY_ENT] [LAY_BSPC]
                              (Outer)   (Inner)         (Inner)   (Outer)
```

### Mod-Tap Definitions (`keymap.c`)

Holding any home row key applies the modifier; tapping sends the primary character:


| Define | Keycode Definition | Tap Key | Hold Modifier |
| :--- | :--- | :--- | :--- |
| **`MOD_A`** | `MT(MOD_LGUI, KC_A)` | `a` | `LGUI` (Left Super) |
| **`MOD_S`** | `MT(MOD_LALT, KC_S)` | `s` | `LALT` (Left Alt) |
| **`MOD_D`** | `MT(MOD_LSFT, KC_D)` | `d` | `LSFT` (Left Shift) |
| **`MOD_F`** | `MT(MOD_LCTL, KC_F)` | `f` | `LCTL` (Left Control) |
| **`MOD_J`** | `MT(MOD_RCTL, KC_J)` | `j` | `RCTL` (Right Control) |
| **`MOD_K`** | `MT(MOD_RSFT, KC_K)` | `k` | `RSFT` (Right Shift) |
| **`MOD_L`** | `MT(MOD_RALT, KC_L)` | `l` | `RALT` (Right Alt) |
| **`MOD_SCLN`** | `MT(MOD_RGUI, KC_SEMICOLON)` | `;` | `RGUI` (Right Super) |

### Layer-Tap & Thumb Cluster (`keymap.c`)

Holding a thumb key activates an alternate layer; tapping sends the primary key:

| Define | Keycode Definition | Tap Key | Hold Action |
| :--- | :--- | :--- | :--- |
| **`LAY_ESC`** | `LT(L_NAV, KC_ESC)` | `Escape` (`KC_ESC`) | Activate **`L_NAV`** (Navigation Layer) |
| **`LAY_SPC`** | `LT(L_SYM, KC_SPACE)` | `Space` (`KC_SPACE`) | Activate **`L_SYM`** (Symbol Layer) |
| **`LAY_ENT`** | `LT(L_KBD, KC_ENTER)` | `Enter` (`KC_ENTER`) | Base Layer (`L_KBD`) |
| **`LAY_BSPC`** | `LT(L_KBD, KC_BACKSPACE)` | `Backspace` (`KC_BACKSPACE`) | Base Layer (`L_KBD`) |

- **`LAY_ESC`** (`LT(L_NAV, KC_ESC)`):
  - **Tap**: `KC_ESC` (drops to Normal mode in Neovim).
  - **Hold**: Switches to **`L_NAV`** (Navigation, Movement & Number Layer).
- **`LAY_SPC`** (`LT(L_SYM, KC_SPACE)`):
  - **Tap**: `KC_SPACE` (Space key, home resting position).
  - **Hold**: Switches to **`L_SYM`** (Symbol Layer).
- **`LAY_ENT`** (`LT(L_KBD, KC_ENTER)`):
  - **Tap**: `KC_ENTER` (Enter key, home resting position).
  - **Hold**: Base layer tap definition (reserved for future layer switching, e.g. `L_FUN`).
- **`LAY_BSPC`** (`LT(L_KBD, KC_BACKSPACE)`):
  - **Tap**: `KC_BACKSPACE` (Backspace key).
  - **Hold**: Base layer tap definition.

---

## Layer 1: Navigation, Movement & Number Layer (`L_NAV`)

Activated by **holding the Outer Left Thumb (`LAY_ESC`)**.

```
Left Hand                                               Right Hand
[ KC_1  ] [ KC_2  ] [ KC_3  ] [ KC_4  ] [ KC_5  ]       [ KC_6  ] [ KC_7  ] [ KC_8  ] [ KC_9  ] [ KC_0  ]
[KC_TRNS] [KC_TRNS] [KC_TRNS] [KC_TRNS] [ KC_NO ]       [KC_LEFT] [KC_DOWN] [ KC_UP ] [KC_RGHT] [ KC_NO ]
[ KC_NO ] [ KC_NO ] [ KC_NO ] [ KC_NO ] [ KC_NO ]       [ KC_NO ] [ KC_NO ] [ KC_NO ] [ KC_NO ] [ KC_NO ]
                              [KC_TRNS] [ KC_NO ]       [ LCTL(KC_B)  ] [OSM(MOD_LALT)]
                              (Held)                    (Tmux Prefix)   (WM Workspaces)
```

### Features

#### 1. Top Number Row

- Numbers `KC_1` through `KC_5` on the left hand, and `KC_6` through `KC_0` on the right hand.
- Hold `LAY_ESC` and tap any digit to input numbers without requiring a separate numeric keypad.

#### 2. Neovim `HJKL` Navigation

- Mapped directly to the right hand home row:
  - `H` $\rightarrow$ Left Arrow (`KC_LEFT`)
  - `J` $\rightarrow$ Down Arrow (`KC_DOWN`)
  - `K` $\rightarrow$ Up Arrow (`KC_UP`)
  - `L` $\rightarrow$ Right Arrow (`KC_RGHT`)

#### 3. Workspace Switching & Tmux Navigation

- **Desktop Environment Workspaces (`Alt + Num`)**:
  - Hold `LAY_ESC` $\rightarrow$ tap **Outer Right Thumb** (`OSM(MOD_LALT)`) $\rightarrow$ tap
    number (`1` ... `0`).
  - The modifier is armed with a single tap, applies to the number, and unarms automatically.
- **Tmux Windows (`Ctrl + b`, then `Num`)**:
  - Hold `LAY_ESC` $\rightarrow$ tap **Inner Right Thumb** (`LCTL(KC_B)`) $\rightarrow$ tap
    number (`1` ... `0`).
  - Sends the standard Tmux prefix `Ctrl + b` without releasing the layer, allowing immediate window selection with the top number row.

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

## Layer 2: Symbol Layer (`L_SYM`)

Activated by **holding the Inner Left Thumb (`LAY_SPC`)**.

```
Left Hand                                               Right Hand
[KC_EXLM] [ KC_AT ] [KC_LCBR] [KC_RCBR] [KC_PIPE]       [KC_BSLS] [KC_PLUS] [KC_MINS] [KC_ASTR] [KC_SLSH]
[KC_HASH] [ KC_DLR] [KC_LPRN] [KC_RPRN] [KC_TILD]       [KC_UNDS] [KC_COLN] [ KC_EQL] [KC_DQUO] [KC_QUOT]
[KC_PERC] [KC_CIRC] [KC_LBRC] [KC_RBRC] [ KC_GRV]       [KC_SCLN] [ KC_LT ] [ KC_GT ] [KC_QUES] [KC_AMPR]
                              [ KC_NO ] [KC_TRNS]       [KC_ENT ] [KC_BSPC]
                                        (Held)          (Enter)   (Backspace)
```

### Features

#### 1. Paired Enclosures on Strong Fingers

Opening and closing brackets, braces, and parentheses are symmetrically placed next to each other on
the agile middle and index columns:
- **Curly Braces**: `{` (`KC_LCBR`) and `}` (`KC_RCBR`) on the top row.
- **Parentheses**: `(` (`KC_LPRN`) and `)` (`KC_RPRN`) on the home row.
- **Square Brackets**: `[` (`KC_LBRC`) and `]` (`KC_RBRC`) on the bottom row.
- **Angle Brackets**: `<` (`KC_LT`) and `>` (`KC_GT`) on the right-hand bottom row.

#### 2. Programming, Syntax & Arithmetic Operators

- **Mathematical Operators**: `+` (`KC_PLUS`), `-` (`KC_MINS`), `*` (`KC_ASTR`), and `/` (`KC_SLSH`)
  grouped on the right-hand top row.
- **Assignment & Delimiters**: Underscore `_` (`KC_UNDS`), colon `:` (`KC_COLN`), and equals `=`
  (`KC_EQL`) on the right-hand home row.
- **Quotes**: Double quote `"` (`KC_DQUO`) and single quote `'` (`KC_QUOT`) positioned on the
  right-hand ring and pinky home row.
- **Slashes & Piping**: Pipe `|` (`KC_PIPE`) and backslash `\` (`KC_BSLS`) meet on the inner columns
  of the top row.
- **Shell & Regex Symbols**: Exclamation mark `!` (`KC_EXLM`), at `@` (`KC_AT`), hash `#`
  (`KC_HASH`), dollar `$` (`KC_DLR`), percent `%` (`KC_PERC`), caret `^` (`KC_CIRC`), tilde `~`
  (`KC_TILD`), grave / backtick `` ` `` (`KC_GRV`), semicolon `;` (`KC_SCLN`), question mark `?`
  (`KC_QUES`), and ampersand `&` (`KC_AMPR`).

#### 3. Thumb Cluster in Symbol Mode

- **`KC_ENT`** (Inner Right Thumb) and **`KC_BSPC`** (Outer Right Thumb) allow immediate newline
  creation and error correction while typing code expressions without releasing the layer.
- The outer left thumb is deactivated (`KC_NO`) to prevent accidental mispresses while holding
  `LAY_SPC`.

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

## Building the Firmware

To compile this keymap using the QMK CLI:

```bash
qmk compile -kb ferris/sweep -km <name>
```
