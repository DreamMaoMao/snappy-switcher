/* src/backend.c - Backend abstraction layer */
#include "backend.h"
#include "wlr_backend.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LOG(fmt, ...) fprintf(stderr, "[Backend] " fmt "\n", ##__VA_ARGS__)

/* Backend implementations */
static Backend backends[] = {{.type = BACKEND_WLR,
                              .init = wlr_backend_init,
                              .cleanup = wlr_backend_cleanup,
                              .get_windows = wlr_get_windows,
                              .activate_window = wlr_activate_window,
                              .get_name = wlr_get_name}};

static Backend *current_backend = NULL;

/* Helper function to detect which backend to use */
static BackendType detect_backend(void) { return BACKEND_WLR; }

Backend *backend_init(struct wl_display *display) {
  if (current_backend) {
    return current_backend;
  }

  BackendType type = detect_backend();

  for (size_t i = 0; i < sizeof(backends) / sizeof(backends[0]); i++) {
    if (backends[i].type == type) {
      current_backend = &backends[i];

      /* Initialize the backend */
      if (current_backend->init && current_backend->init(display) < 0) {
        LOG("Failed to initialize %s backend", current_backend->get_name());
        current_backend = NULL;
        return NULL;
      }

      LOG("Using %s backend", current_backend->get_name());
      return current_backend;
    }
  }

  LOG("No suitable backend found");
  return NULL;
}

void backend_cleanup(Backend *backend) {
  if (!backend)
    return;

  if (backend->cleanup) {
    backend->cleanup();
  }

  if (backend == current_backend) {
    current_backend = NULL;
  }
}

BackendType backend_get_type(Backend *backend) {
  return backend ? backend->type : BACKEND_UNKNOWN;
}