// SPDX-License-Identifier: MIT
// Integration with Sway WM.
// Copyright (C) 2020 Artem Senichev <artemsen@gmail.com>

#pragma once

#include "types.h"

#include <stdbool.h>

/**
 * Connect to Sway.
 * @return IPC context, -1 if error
 */
int sway_connect(void);

/**
 * Disconnect IPC channel.
 * @param ipc IPC context
 */
void sway_disconnect(int ipc);

/**
 * Get geometry for currently focused window.
 * @param ipc IPC context
 * @param wnd geometry of currently focused window
 * @param fullscreen current full screen mode
 * @return true if operation completed successfully
 */
bool sway_current(int ipc, struct rect* wnd, bool* fullscreen);

/**
 * Add rules for Sway for application's window:
 * 1. Enable floating mode;
 * 2. Set initial position.
 *
 * @param ipc IPC context
 * @param app application Id
 * @param x horizontal window position relative to current workspace
 * @param v vertical window position relative to current workspace
 * @return true if operation completed successfully
 */
bool sway_add_rules(int ipc, const char* app, int x, int y);
