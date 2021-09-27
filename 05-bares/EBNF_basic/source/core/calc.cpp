#include "calc.h"


int Calc::prec(std::string c) {
    if(c == "^")
        return 3;
    else if(c == "/" || c == "*" || c == "%")
        return 2;
    else if(c == "+" || c == "-")
        return 1;
    else
        return -1;
}

int Calc::op_exp(required_int_type A, required_int_type B, std::string Op) {
    if(Op == "^") return (std::pow(A, B));
    else if(Op == "/") {
        if(B == 0) {
            erro = execution_error::DIVISION_BY_ZERO;
            return B;
        }
        return A/B;
    }
    else if(Op == "*") return A*B;
    else if(Op == "%") return A%B;
    else if(Op== "+") return (A+B);
    else return (A-B); // Case Op == "-"
}

void Calc::infixToPostfix( std::vector< Token > input) {
 
    std::stack<Token> tk; // Store in a stack the operators.
 
    for(long unsigned int i = 0; i < input.size(); i++) {
        
        // If the scanned character is OPERAND, add it to output stack.
        if(input[i].type == Token::token_t::OPERAND)
            exp_postfix.push_back(input[i]);
 
        // If the scanned character is an ‘(‘, add to the end the stack.
        else if(input[i].value == "(")
            tk.push(input[i]);
 
        // If the scanned character is an ‘)’, pop and to output string from the stack until an ‘(‘ is encountered.
        else if(input[i].value == ")") {
            while(tk.top().value != "(")
            {
                exp_postfix.push_back(tk.top());
                tk.pop();
            }
            tk.pop();
        }
 
        // If the scanned character is OPERATOR
        else {
            // Check if the stack is not empty and if the precedence of the current operator is less
            // than the top-of-stack operator to add to truly_result.
            while(!tk.empty() && prec(input[i].value) <= prec(tk.top().value)) {
                exp_postfix.push_back(tk.top());
                tk.pop(); 
            }
            tk.push(input[i]);
        }
    }
 
    // Pop all the remaining elements from the stack
    while(!tk.empty()) {
        exp_postfix.push_back(tk.top());
        tk.pop();
    }
}

    void Calc::print_exp() {
        for(auto i: exp_postfix)
            std::cout << i.value <<" ";
        std::cout << std::endl;
    }
    bool Calc::calc_exp() {
        int value;
        for(size_t i = 0; i < exp_postfix.size(); i++){ //Pass by each element in size
            if(exp_postfix[i].type == Token::token_t::OPERAND){ //If is an operation
                value = std::stoi(exp_postfix[i].value);
                if(not Calc::is_in_range(value)){ return false;}
                exp_stack_aux.push((short)value); //Push into the stack
            }
            else { 
                required_int_type B = exp_stack_aux.top();
                exp_stack_aux.pop(); //Remove from stack
                required_int_type A = exp_stack_aux.top();
                exp_stack_aux.pop();//Remove from stack
                value = Calc::op_exp(A, B, exp_postfix[i].value); //Do the operation
                if(erro != execution_error::OK){return false;}
                if(not Calc::is_in_range(value)){ return false;}
                exp_stack_aux.push(value);  //Add the new result
            }  
        }
        exp_result = exp_stack_aux.top();//The last element is the result
        exp_stack_aux.pop(); //Empty the stack
        return true;
    }

    bool Calc::is_in_range(int value) {
        if(value < -32768 || value > 32767) {
            erro = execution_error::NUMERIC_OVERFLOW;
            return false;
        }
        return true;
    }