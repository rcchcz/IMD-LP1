#include "parser.h"
#include "common.h"
#include "calc.h"

/// List of expressions to test the outputs
/*
std::vector<std::string> expressions = {
    "(1+2",
    "12^(((4/2) -6*(4+1)",
    "1/0",
    "99^99",
    "1+2*2-3",
    "(1+2)*(2-3)",
    "1^2*3 -4 + 5/6/(7+8)"
    "1^2*3-4+100/4/(3+2)-(12+3)*6"
    "4 + 03",
    "10",
    "    12    +    4   8",
    "32767 - 32768 + 3",
    "5 + -32766",
    "5 + -32769",
    "12 + 3",
    "-3+-5+-6",
    "12 + 3     -3 + -34 ",
    "+12",
    "1.3 * 4",
    "a + 4",
    "       ",
    "  123 *  548",
    "4 + ",
    "32a23",
    "43 + 54 -   "
};
*/
/// Send to the standard output the proper error messages.
void print_error_msg( const Parser::ResultType & result, const std::string &str ) {

    // Have we got a parsing error?
    switch ( result.type ) {
        case Parser::ResultType::UNEXPECTED_END_OF_EXPRESSION:
            std::cout << ">>> Unexpected end of input at column (" << result.at_col << ")!\n";
            break;
        case Parser::ResultType::ILL_FORMED_INTEGER:
            std::cout << ">>> Ill formed integer at column (" << result.at_col << ")!\n";
            break;
        case Parser::ResultType::MISSING_TERM:
            std::cout << ">>> Missing <term> at column (" << result.at_col << ")!\n";
            break;
        case Parser::ResultType::EXTRANEOUS_SYMBOL:
            std::cout << ">>> Extraneous symbol after valid expression found at column (" << result.at_col << ")!\n";
            break;
        case Parser::ResultType::INTEGER_OUT_OF_RANGE:
            std::cout << ">>> Integer constant out of range beginning at column (" << result.at_col << ")!\n";
            break;
        case Parser::ResultType::MISSING_CLOSING:
            std::cout << ">>> Missing closing ”)”at column (" << result.at_col << ")!\n";
            break;
        default:
            std::cout << ">>> Unhandled error found!\n";
            break;
    }
}
//Print executions erros
void print_exec_error(execution_error input){
    switch (input)
    {
    case execution_error::DIVISION_BY_ZERO:
        std::cout << ">>> Division by Zero!\n";
        break;
    case execution_error::NUMERIC_OVERFLOW:
        std::cout << ">>> Numeric overflow: some operation is making the result get out of the range [-32768,32767]\n";
        break;
    default:
        break;
    }
    return;
}
int main( void ) {
    Parser my_parser; // Instancia um parser.
    std::string expr;
    while(std::getline(std::cin, expr)) {
    //for( const auto & expr : expressions ) { //If you want to test expressions in a list
        // [I] Fazer o parsing desta expressão.
        auto result = my_parser.parse_and_tokenize( expr );  
        // Se deu pau, imprimir a mensagem adequada.
        if ( result.type == Parser::ResultType::OK ){ 
            // [II] Recuperar a lista de tokens.
            auto lista = my_parser.get_tokens();
            if ( result.type == Parser::ResultType::OK ) {
                Calc expression(lista);
                if(expression.calc_exp()) {
                    expression.print_result();
                } else {
                    print_exec_error(expression.erro);
                }   
            }
        } else
            print_error_msg( result, expr );
    }
    std::cout << "\n>>> Normal exiting...\n";

    return EXIT_SUCCESS;
}
