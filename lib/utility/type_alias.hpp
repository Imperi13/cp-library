#pragma once

#include <cstdint>

using i64 = std::int64_t;
using i32 = std::int32_t;
using i16 = std::int16_t;
using i8 = std::int8_t;

using u64 = std::uint64_t;
using u32 = std::uint32_t;
using u16 = std::uint16_t;
using u8 = std::uint8_t;

using usize = std::size_t;
using isize = std::ptrdiff_t;

constexpr i64 operator"" _i64(unsigned long long num) { return i64(num); }
constexpr i32 operator"" _i32(unsigned long long num) { return i32(num); }
constexpr i16 operator"" _i16(unsigned long long num) { return i16(num); }
constexpr i8 operator"" _i8(unsigned long long num) { return i8(num); }

constexpr u64 operator"" _u64(unsigned long long num) { return u64(num); }
constexpr u32 operator"" _u32(unsigned long long num) { return u32(num); }
constexpr u16 operator"" _u16(unsigned long long num) { return u16(num); }
constexpr u8 operator"" _u8(unsigned long long num) { return u8(num); }
