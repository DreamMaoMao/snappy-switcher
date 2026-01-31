/* src/input.h - Keyboard Input Handling */
#ifndef INPUT_H
#define INPUT_H

#include "data.h"
#include <stdbool.h>
#include <wayland-client.h>

/* Callback for modifier release event (set by main.c) */
typedef void (*modifier_release_callback_t)(void);
extern modifier_release_callback_t on_modifier_release;

/* Callback for Escape key - hide without switching (set by main.c) */
extern modifier_release_callback_t on_escape;

/* Reset modifier states (call when switcher shows to avoid stale detection) */
void input_reset_modifier_states(void);

/* Get keyboard listener for Wayland seat */
const struct wl_keyboard_listener *get_keyboard_listener(void);

/* Cleanup input resources */
void input_cleanup(void);

#endif /* INPUT_H */