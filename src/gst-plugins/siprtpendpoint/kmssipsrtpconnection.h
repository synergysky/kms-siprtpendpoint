/*
 * (C) Copyright 2015 Kurento (http://kurento.org/)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef __KMS_SIP_SRTP_CONNECTION_H__
#define __KMS_SIP_SRTP_CONNECTION_H__

#include "kmssrtpconnection.h"
#include "kmsrtpfilterutils.h"
#include <gio/gio.h>
#include <gst/sdp/gstsdpmessage.h>

G_BEGIN_DECLS


KmsSrtpConnection *
kms_sip_srtp_connection_new (guint16 min_port, guint16 max_port, gboolean use_ipv6,
		GSocket *rtp_sock, GSocket *rtcp_sock,
		SipFilterSsrcInfo* filter_info, gulong *rtp_probe_id, gulong *rtcp_probe_id);

void
kms_sip_srtp_connection_add_probes (KmsSrtpConnection *conn, SipFilterSsrcInfo* filter_info, gulong *rtp_probe_id, gulong *rtcp_probe_id);

void
kms_sip_srtp_connection_release_probes (KmsSrtpConnection *conn, gulong rtp_probe_id, gulong rtcp_probe_id);

void kms_sip_srtp_connection_retrieve_sockets (KmsSrtpConnection *conn, GSocket **rtp, GSocket **rtcp);

void kms_sip_srtp_connection_set_key (KmsSrtpConnection *conn, const gchar *key, guint auth, guint cipher, gboolean local);

G_END_DECLS
#endif /* __KMS_SIP_SRTP_CONNECTION_H__ */
