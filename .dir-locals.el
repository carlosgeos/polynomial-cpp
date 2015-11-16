;;; Directory Local Variables
;;; For more information see (info "(emacs) Directory Variables")

((c++-mode
  (flycheck-clang-warnings "pedantic all extra conversion effc++ strict-null-sentinel old-style-cast noexcept ctor-dtor-privacy overloaded-virtual sign-promo zero-as-null-pointer-constant suggest-final-types suggest-final-methods suggest-override)")
  (flycheck-gcc-warnings -Wpedantic -Wall -Wextra -Wconversion -Weffc++ -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override)
  (flycheck-gcc-language-standard . c++14)
  (flycheck-clang-language-standard . "c++14")))
