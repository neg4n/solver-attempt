#include <lexer.hpp>
#include <token.hpp>

#include <iostream>
#include <iomanip>

int main( ) {
  using namespace solver::internal;

  const char* code = "x + (30 * 2) / 2 - 20 = y";
  Lexer lexer { code };

  std::cout << std::string(40, '-')
            << std::endl
            << std::setw(33)
            << code
            << std::endl
            << std::string(40, '-')
            << std::endl
            << std::setw(20)
            << "Type" << " | " << "Inner"
            << std::endl
            << std::string(40, '-')
            << std::endl;

  for ( auto token = lexer.next( );
        !token.is_one_of( Token::Type::Eof, Token::Type::Invalid );
        token = lexer.next( ) ) {
    std::cout << std::setw( 20 ) << Token::type_str( token.type( ) ) << " | "
              << token.inner( ) << std::endl;
  }

  return 0;
}