<div align="center">

# ⚡ Snappy Switcher

### A blazing-fast, animated Alt+Tab window switcher for wayland compositors

[![License](https://img.shields.io/badge/License-GPL3-blue?style=for-the-badge&logo=gnu)](LICENSE)
[![Language](https://img.shields.io/badge/Language-C-orange?style=for-the-badge&logo=c)](https://en.cppreference.com/w/c)
[![Version](https://img.shields.io/badge/Version-1.0-success?style=for-the-badge)]()
[![AUR](https://img.shields.io/aur/version/snappy-switcher?color=blue&label=AUR&logo=arch-linux&style=for-the-badge)](https://aur.archlinux.org/packages/snappy-switcher)

<br/>

<img src="assets/snappy-slate.png" alt="Snappy Switcher Showcase" width="700"/>

<br/>

*The window switcher that actually understands your workflow.*

</div>

---

## ✨ Why Snappy Switcher?

**Snappy Switcher** isn't just another window list—it's a **context-aware** window manager that thinks like you do:

| Feature | Description |
|---------|-------------|
| 🧠 **Context Grouping** | Automatically groups tiled windows by workspace + app class. Your 5 terminal windows become one clean card. |
| 🎨 **12 Themed Skins** | Ships with Catppuccin, Dracula, Nord, Tokyo Night, and more. Full `.ini` customization. |
| ⚡ **Native Performance** | Pure C with Wayland Layer Shell. No Electron. No lag. |
| 🔄 **Crash Recovery** | Socket takeover protocol ensures seamless recovery if the daemon restarts. |
| 🖼️ **Polished Visuals** | Animated selection, drop shadows, rounded corners, and app badges—all Cairo-rendered. |

---



## 📦 Installation

### <img src="https://img.shields.io/badge/AUR-1793D1?style=flat&logo=archlinux&logoColor=white" height="20"/> Arch Linux (AUR)

<table>
<tr>
<td>

**Using Yay**
```bash
yay -S snappy-switcher
```

</td>
<td>

**Using Paru**
```bash
paru -S snappy-switcher
```

</td>
</tr>
</table>

<details>
<summary>📦 <b>Build from PKGBUILD</b></summary>

```bash
git clone https://github.com/OpalAayan/snappy-switcher.git
cd snappy-switcher
makepkg -si
```

</details>

### Manual Build

<details>
<summary>📋 <b>Dependencies</b></summary>

| Package | Purpose |
|---------|---------|
| `wayland` | Core protocol |
| `cairo` | 2D rendering |
| `pango` | Text layout |
| `json-c` | IPC parsing |
| `libxkbcommon` | Keyboard handling |
| `glib2` | Utilities |
| `librsvg` | SVG icons *(optional)* |

</details>

**Install dependencies (Arch):**
```bash
sudo pacman -S wayland cairo pango json-c libxkbcommon glib2 librsvg
```

```bash
# Build
make

# Install system-wide
sudo make install

# Or install for current user only
make install-user
```

---

## 🚀 Quick Start

### 1️⃣ Setup Configuration

```bash
snappy-install-config
```

This copies themes and creates `~/.config/snappy-switcher/config.ini`.

### 2️⃣ Add to Sway Config

Add these lines to `~/.config/sway/config`:

```bash
# Start the daemon on login
exec-once = snappy-switcher --daemon

# Keybindings
bind = ALT, Tab, exec, snappy-switcher next
bind = ALT SHIFT, Tab, exec, snappy-switcher prev
```

### 3️⃣ You're Done! 🎉

Press <kbd>Alt</kbd> + <kbd>Tab</kbd> to see it in action.

---

## 🎨 Theme Gallery

> All 12 themes included out of the box. Just change one line in your config!

<table>
<tr>
<td align="center">
<img src="assets/snappy-slate.png" width="250"/><br/>
<b>Snappy Slate</b><br/><sub>Default</sub>
</td>
<td align="center">
<img src="assets/catppuccin-mocha.png" width="250"/><br/>
<b>Catppuccin Mocha</b>
</td>
<td align="center">
<img src="assets/catppuccin-latte.png" width="250"/><br/>
<b>Catppuccin Latte</b>
</td>
</tr>
<tr>
<td align="center">
<img src="assets/tokyo-night.png" width="250"/><br/>
<b>Tokyo Night</b>
</td>
<td align="center">
<img src="assets/nord.png" width="250"/><br/>
<b>Nord</b>
</td>
<td align="center">
<img src="assets/nordic.png" width="250"/><br/>
<b>Nordic</b>
</td>
</tr>
<tr>
<td align="center">
<img src="assets/dracula.png" width="250"/><br/>
<b>Dracula</b>
</td>
<td align="center">
<img src="assets/gruvbox-dark.png" width="250"/><br/>
<b>Gruvbox Dark</b>
</td>
<td align="center">
<img src="assets/rose-pine.png" width="250"/><br/>
<b>Rosé Pine</b>
</td>
</tr>
<tr>
<td align="center">
<img src="assets/cyberpunk.png" width="250"/><br/>
<b>Cyberpunk</b>
</td>
<td align="center">
<img src="assets/grovestorm.png" width="250"/><br/>
<b>Grovestorm</b>
</td>
<td align="center">
<img src="assets/default-fallback.png" width="250"/><br/>
<b>Default Fallback</b>
</td>
</tr>
</table>

### 🎯 Change Theme

Edit `~/.config/snappy-switcher/config.ini`:

```ini
[theme]
name = catppuccin-mocha.ini
```

---

## ⚙️ Configuration

<details>
<summary>🔧 <b>Full Configuration Reference</b></summary>

```ini
# ~/.config/snappy-switcher/config.ini

[general]
# overview = Show all windows individually
# context  = Group tiled windows by workspace + app class
mode = context

[theme]
name = snappy-slate.ini
border_width = 2
corner_radius = 12

[layout]
card_width = 160
card_height = 140
card_gap = 10
padding = 20
max_cols = 5
icon_size = 56

[icons]
theme = Tela-dracula
fallback = hicolor
show_letter_fallback = true

[font]
family = Sans
weight = Bold
title_size = 10
```

</details>

📘 **[Full Configuration Documentation →](docs/CONFIGURATION.md)**

---




## 🧪 Available Commands

| Command | Description |
|---------|-------------|
| `snappy-switcher --daemon` | Start background daemon |
| `snappy-switcher next` | Cycle to next window |
| `snappy-switcher prev` | Cycle to previous window |
| `snappy-switcher toggle` | Show/hide switcher |
| `snappy-switcher hide` | Force hide overlay |
| `snappy-switcher select` | Confirm current selection |
| `snappy-switcher quit` | Stop the daemon |

---

## 🤝 Contributing

Contributions are welcome! Here's how to get started:

```bash
# Clone the repo
git clone https://github.com/OpalAayan/snappy-switcher.git
cd snappy-switcher

# Build
make

# Run tests
make test

# Clean build
make clean && make

# Run stress tests
./scripts/ultimate_stress_test.sh
```

---

## 💡 Credits & Inspiration

This project was built with ❤️ for the Linux customization community.

| Project | Contribution |
|---------|--------------|
| **[hyprshell](https://github.com/H3rmt/hyprshell)** | Massive inspiration for client parsing and layer-shell handling |
| **[Catppuccin](https://github.com/catppuccin)** | Beautiful color palettes used in themes |

---

<div align="center">

### ⚡ Made with love by [OpalAayan](mailto:YougurtMyFace@proton.me)

[![Star](https://img.shields.io/github/stars/OpalAayan/snappy-switcher?style=social)](https://github.com/OpalAayan/snappy-switcher)

## Star History

[![Star History Chart](https://api.star-history.com/svg?repos=OpalAayan/snappy-switcher&type=date&legend=top-left)](https://www.star-history.com/#OpalAayan/snappy-switcher&type=date&legend=top-left)

<sub>Licensed under GPL-3.0</sub>

</div>
