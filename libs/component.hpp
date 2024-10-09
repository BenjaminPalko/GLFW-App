#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <bitset>
#include <cstdint>

using ComponentType = std::uint8_t;

const ComponentType MAX_COMPONENTS = 32;

using Signature = std::bitset<MAX_COMPONENTS>;

#endif // COMPONENT_HPP
