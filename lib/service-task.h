/*
 * dLeyna
 *
 * Copyright (C) 2012-2013 Intel Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU Lesser General Public License,
 * version 2.1, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Ludovic Ferrandis <ludovic.ferrandis@intel.com>
 * Regis Merlino <regis.merlino@intel.com>
 *
 */

#ifndef DLR_SERVICE_TASK_H__
#define DLR_SERVICE_TASK_H__

#include <glib.h>
#include <libgupnp/gupnp-service-proxy.h>

#include <libdleyna/core/task-atom.h>

#include "server.h"

typedef struct dlr_service_task_t_ dlr_service_task_t;

typedef GUPnPServiceProxyAction *(*dlr_service_task_action)
						(dlr_service_task_t *task,
						 GUPnPServiceProxy *proxy,
						 gboolean *failed);

const char *dlr_service_task_create_source(void);

void dlr_service_task_add(const dleyna_task_queue_key_t *queue_id,
			  dlr_service_task_action action,
			  dlr_device_t *device,
			  GUPnPServiceProxy *proxy,
			  GUPnPServiceProxyActionCallback action_cb,
			  GDestroyNotify free_func,
			  gpointer cb_user_data);

void dlr_service_task_begin_action_cb(GUPnPServiceProxy *proxy,
				      GUPnPServiceProxyAction *action,
				      gpointer user_data);

void dlr_service_task_process_cb(dleyna_task_atom_t *atom, gpointer user_data);

void dlr_service_task_cancel_cb(dleyna_task_atom_t *atom, gpointer user_data);

void dlr_service_task_delete_cb(dleyna_task_atom_t *atom, gpointer user_data);

dlr_device_t *dlr_service_task_get_device(dlr_service_task_t *task);

gpointer *dlr_service_task_get_user_data(dlr_service_task_t *task);

#endif /* DLR_SERVICE_TASK_H__ */
