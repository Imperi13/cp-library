#pragma once

#include <cstdint>

using u64 = std::uint64_t;
using u32 = std::uint32_t;
using u16 = std::uint16_t;
using u8 = std::uint8_t;

using i64 = std::int64_t;
using i32 = std::int32_t;
using i16 = std::int16_t;
using i8 = std::int8_t;

using usize = std::size_t;
using isize = std::ptrdiff_t;

i64 operator"" _i64(unsigned long long num){
  return i64(num);
}
 
u64 operator"" _u64(unsigned long long num){
  return u64(num);
}