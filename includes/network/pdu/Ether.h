#pragma once

#include <cstdint>
#include <ostream>
#include "network/HwAddr.h"

using byte=uint8_t;

namespace network {
    class Ether {
    public:
        static const int size = 14;
        HwAddr dst;
        HwAddr src;
        u_short type {0x0800};
    public:
        Ether() = default;
        Ether(const Ether& eth) = default;
        explicit Ether(const byte pk[size]);
        explicit Ether(const HwAddr& dst, const HwAddr& src, u_short type);
    public:
        byte* to_bytes() const;
    };
}
