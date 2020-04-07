// Copyright (c) 2017-2020 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/PEGTL/

#ifndef TAO_PEGTL_INTERNAL_BOF_HPP
#define TAO_PEGTL_INTERNAL_BOF_HPP

#include "../config.hpp"

#include "skip_control.hpp"

namespace TAO_PEGTL_NAMESPACE::internal
{
   struct bof
   {
      using rule_t = bof;

      template< typename Input >
      [[nodiscard]] static bool match( Input& in ) noexcept
      {
         return in.byte() == 0;
      }
   };

   template<>
   inline constexpr bool skip_control< bof > = true;

}  // namespace TAO_PEGTL_NAMESPACE::internal

#endif
