#ifndef ARP_SENDER_ETHER_H
#define ARP_SENDER_ETHER_H

#include <cstdint>
#include <ostream>
#include "../HwAddr.h"

using byte=uint8_t;

namespace network {
    class Ether {
    public:
        static const int size = 14;
        HwAddr dst {"00:00:00:00:00:00"};
        HwAddr src {"00:00:00:00:00:00"};
        u_short type {0x0800};
    public:
        Ether() = default;
        explicit Ether(const byte pk[size]);
        explicit Ether(const HwAddr& dst, const HwAddr& src, u_short type);
    };
}

#endif //ARP_SENDER_ETHER_H
