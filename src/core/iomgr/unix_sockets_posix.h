/*
 *
 * Copyright 2016, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef GRPC_INTERNAL_CORE_IOMGR_UNIX_SOCKETS_POSIX_H
#define GRPC_INTERNAL_CORE_IOMGR_UNIX_SOCKETS_POSIX_H

#include <grpc/support/port_platform.h>

#ifdef GPR_POSIX_SOCKET

#include <sys/socket.h>

#include <grpc/support/string_util.h>

#include "src/core/client_config/resolver_factory.h"
#include "src/core/client_config/uri_parser.h"
#include "src/core/iomgr/resolve_address.h"

void grpc_create_socketpair_if_unix(int sv[2]);

grpc_resolved_addresses *grpc_resolve_unix_domain_address(const char* name);

int grpc_is_unix_socket(const struct sockaddr *addr);

void grpc_unlink_if_unix_domain_socket(const struct sockaddr *addr);

int grpc_parse_unix(grpc_uri *uri, struct sockaddr_storage *addr, size_t *len);

char *grpc_unix_get_default_authority(grpc_resolver_factory *factory,
                                      grpc_uri *uri);

char *grpc_sockaddr_to_uri_unix_if_possible(const struct sockaddr *addr);

#endif
#endif /* GRPC_INTERNAL_CORE_IOMGR_UNIX_SOCKETS_POSIX_H */
