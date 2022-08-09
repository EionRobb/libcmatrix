/* -*- mode: c; c-basic-offset: 2; indent-tabs-mode: nil; -*- */
/*
 * Copyright (C) 2022 Purism SPC
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <glib-object.h>
#include <json-glib/json-glib.h>
#include <libsoup/soup.h>

#include "cm-enums.h"

GError       *cm_utils_json_node_get_error      (JsonNode            *node);
gboolean      cm_utils_get_item_position        (GListModel          *list,
                                                 gpointer             item,
                                                 guint               *position);
gboolean      cm_utils_remove_list_item         (GListStore          *store,
                                                 gpointer             item);
char         *cm_utils_json_object_to_string    (JsonObject          *object,
                                                 gboolean             prettify);
GString      *cm_utils_json_get_canonical       (JsonObject          *object,
                                                 GString             *out);
JsonObject   *cm_utils_string_to_json_object    (const char          *json_str);
gint64        cm_utils_json_object_get_int      (JsonObject          *object,
                                                 const char          *member);
gboolean      cm_utils_json_object_get_bool     (JsonObject          *object,
                                                 const char          *member);
const char   *cm_utils_json_object_get_string   (JsonObject          *object,
                                                 const char          *member);
JsonObject   *cm_utils_json_object_get_object   (JsonObject          *object,
                                                 const char          *member);
JsonArray    *cm_utils_json_object_get_array    (JsonObject          *object,
                                                 const char          *member);

JsonObject   *cm_utils_get_message_json_object  (SoupMessage         *message,
                                                 const char          *member);
void          cm_utils_clear                    (char                *buffer,
                                                 size_t               length);
void          cm_utils_free_buffer              (char                *buffer);
const char   *cm_utils_get_url_from_user_id     (const char          *user_id);
gboolean      cm_utils_user_name_valid          (const char          *matrix_user_id);
gboolean      cm_utils_user_name_is_email       (const char          *user_id);
gboolean      cm_utils_mobile_is_valid          (const char          *mobile_num);

gboolean      cm_utils_home_server_valid        (const char          *homeserver);
void          cm_utils_read_uri_async           (const char          *uri,
                                                 guint                timeout,
                                                 GCancellable        *cancellable,
                                                 GAsyncReadyCallback  callback,
                                                 gpointer             user_data);
gpointer      cm_utils_read_uri_finish          (GAsyncResult        *result,
                                                 GError             **error);
void          cm_utils_get_homeserver_async     (const char          *username,
                                                 guint                timeout,
                                                 GCancellable        *cancellable,
                                                 GAsyncReadyCallback  callback,
                                                 gpointer             user_data);
char         *cm_utils_get_homeserver_finish    (GAsyncResult        *result,
                                                 GError             **error);
void          cm_utils_verify_homeserver_async  (const char          *server,
                                                 guint                timeout,
                                                 GCancellable        *cancellable,
                                                 GAsyncReadyCallback  callback,
                                                 gpointer             user_data);
gboolean      cm_utils_verify_homeserver_finish (GAsyncResult        *result,
                                                 GError             **error);
char         *cm_utils_get_path_for_m_type      (const char          *base_path,
                                                 CmEventType          type,
                                                 gboolean             thumbnail,
                                                 const char          *file_name);
