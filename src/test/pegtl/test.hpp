// Copyright (c) 2014-2020 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#ifndef TAO_PEGTL_SRC_TEST_PEGTL_TEST_HPP
#define TAO_PEGTL_SRC_TEST_PEGTL_TEST_HPP

#include <cstddef>
#include <iostream>

#include <tao/pegtl.hpp>

namespace TAO_PEGTL_NAMESPACE
{
   std::size_t failed = 0;

}  // namespace TAO_PEGTL_NAMESPACE

#define TAO_TEST_STRINGIZE_INTERNAL( ... ) #__VA_ARGS__
#define TAO_TEST_STRINGIZE( ... ) TAO_TEST_STRINGIZE_INTERNAL( __VA_ARGS__ )

#define TAO_TEST_LINE TAO_TEST_STRINGIZE( __LINE__ )

#define TAO_PEGTL_TEST_UNWRAP( ... ) __VA_ARGS__

#define TAO_PEGTL_TEST_FAILED( MeSSaGe )            \
   do {                                             \
      std::cerr << "pegtl: unit test failed for [ " \
                << internal::demangle< Rule >()     \
                << " ] "                            \
                << TAO_PEGTL_TEST_UNWRAP( MeSSaGe ) \
                << " in line [ "                    \
                << line                             \
                << " ] file [ "                     \
                << file << " ]"                     \
                << std::endl;                       \
      ++failed;                                     \
   } while( false )

#define TAO_PEGTL_TEST_ASSERT( ... )               \
   do {                                            \
      if( !( __VA_ARGS__ ) ) {                     \
         std::cerr << "pegtl: unit test assert [ " \
                   << ( #__VA_ARGS__ )             \
                   << " ] failed in line [ "       \
                   << __LINE__                     \
                   << " ] file [ "                 \
                   << __FILE__ << " ]"             \
                   << std::endl;                   \
         ++failed;                                 \
      }                                            \
   } while( false )

#define TAO_PEGTL_TEST_THROWS( ... )                \
   do {                                             \
      try {                                         \
         __VA_ARGS__;                               \
         std::cerr << "pegtl: unit test [ "         \
                   << ( #__VA_ARGS__ )              \
                   << " ] did not throw in line [ " \
                   << __LINE__                      \
                   << " ] file [ "                  \
                   << __FILE__ << " ]"              \
                   << std::endl;                    \
         ++failed;                                  \
      }                                             \
      catch( ... ) {                                \
      }                                             \
   } while( false )

#endif
