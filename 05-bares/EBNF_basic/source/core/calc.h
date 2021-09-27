#ifndef _CALC_H_
#define _CALC_H_

#include "token.h"  
#include "common.h"

/**
 * This class represents a postfix expression calculator.
 */
class Calc {
    private: 
        input_int_type exp_result;        // Expression result.
        std::stack<required_int_type> exp_stack_aux;  // Stack for calculation process.
        std::vector<Token> exp_postfix;   // Postfix expression to be calculated.

        /**
         * @brief Give the order of certain operation
         * 
         * @param c The operator can be : "+","-","*","/","%","^"
         * @return int value of priority
         */
        int prec(std::string c); 

        /**
         * Test if value is a short int.
         */
        bool is_in_range(int value);

        /**
         * @brief Recieve two short int and do an especific operation
         * 
         * @param A First element of operation
         * @param B Second element of operation
         * @param op Operator can be : "+","-","*","/","%","^"
         * @return int The result of operation
         */
        int op_exp(required_int_type A, required_int_type B, std::string op);

    
    public:
        
        execution_error erro = execution_error::OK; // Check if some execution error happened.

        /**
         * @brief Construct a new Calc object, and convert infix expression
         * to posfix expression
         * 
         * @param exp_infix expression of constructor
         */
        Calc(std::vector<Token> exp_infix) { infixToPostfix(exp_infix); }
        
        /**
         * Default destructor.
         */
        ~Calc() = default;

        /**
         * Convert infix to postfix expression.
         * @param input Token vector; each token is an element of the infix expression.
         */
        void infixToPostfix( std::vector< Token > input);

        /** 
         * Print expression.
         */
        void print_exp();

        /**
         * Calculate the result of a postfix expression.
         */
        bool calc_exp();

        /**
         * Print result.
         */
        void print_result() { std::cout << exp_result << '\n';}

};


#endif