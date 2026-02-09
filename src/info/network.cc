#include "info/network.h"
#include <ifaddrs.h>
#include <arpa/inet.h>

namespace breadfetch::network {

    std::string Interface() {
        struct ifaddrs* ifa;
        getifaddrs(&ifa);
        for (auto* p = ifa; p; p = p->ifa_next)
            if (p->ifa_addr && p->ifa_addr->sa_family == AF_INET)
                return p->ifa_name;
        return "unknown";
    }

    std::string LocalIP() {
        struct ifaddrs* ifa;
        getifaddrs(&ifa);
        for (auto* p = ifa; p; p = p->ifa_next) {
            if (p->ifa_addr && p->ifa_addr->sa_family == AF_INET) {
                char buf[INET_ADDRSTRLEN];
                inet_ntop(AF_INET,
                          &((struct sockaddr_in*)p->ifa_addr)->sin_addr,
                          buf, sizeof(buf));
                return buf;
            }
        }
        return "unknown";
    }

} // namespace breadfetch::network
