/* -*- mode: c; c-basic-offset: 2; indent-tabs-mode: nil; -*- */
/* cm-user-private.h
 *
 * Copyright 2022 Purism SPC
 *
 * Author(s):
 *   Mohammed Sadiq <sadiq@sadiqpk.org>
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#pragma once

#if !defined(_CMATRIX_TAKEN) && !defined(CMATRIX_COMPILATION)
# error "Only <cmatrix.h> can be included directly."
#endif

#include <glib-object.h>
#include <gio/gio.h>

#include "cm-client.h"
#include "cm-user.h"

G_BEGIN_DECLS

void           cm_user_set_client            (CmUser        *self,
                                              CmClient      *client);
CmClient      *cm_user_get_client            (CmUser        *self);
void           cm_user_set_user_id           (CmUser        *self,
                                              const char    *user_id);
void           cm_user_set_details          (CmUser         *self,
                                             const char     *display_name,
                                             const char     *avatar_url);
GListModel    *cm_user_get_devices          (CmUser         *self);
gboolean       cm_user_get_device_changed   (CmUser         *self);
void           cm_user_set_device_changed   (CmUser         *self);
gboolean       cm_user_get_device_removed   (CmUser         *self);
JsonObject    *cm_user_get_device_key_json  (CmUser         *self,
                                             gboolean        all_device);
void           cm_user_set_devices          (CmUser         *self,
                                             JsonObject     *root);
void           cm_user_add_one_time_keys    (CmUser         *self,
                                             JsonObject     *root);

G_END_DECLS
