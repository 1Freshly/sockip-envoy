#include "sockip.h"

#include "envoy/buffer/buffer.h"
#include "envoy/network/connection.h"

#include "source/common/common/assert.h"

namespace Envoy {
namespace Filter {

Network::FilterStatus SockIP::onAccept(Network::ListenerFilterCallbacks& cb) {
  ENVOY_LOG(debug, "sockip: connection accepted");
  Network::ConnectionSocket& socket = cb.socket();
  if (socket.addressType() == Network::Address::Type::Ip) {
    auto address = socket.ioHandle().localAddress()->ip()->ipv4()->address();
    auto port = socket.ioHandle().localAddress()->ip()->port();
    ENVOY_LOG(debug, "sockip: local address {}:{}", address, port);
  }
  return Network::FilterStatus::Continue;
}

} // namespace Filter
} // namespace Envoy
