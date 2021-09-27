/*!
 *  This program implements the Keno game.
 *
 *  @author
 *  @file main.cpp
 */

#include <cstdlib> // EXIT_SUCCESS
#include "keno_common.h"
#include "keno_bet.h"

/*
This function receives the path of the file and the struct where the data w
will be stored, and return the possibles errors
*/
size_t analyze_file(char *argv, Keno::KenoBet *KB)
{
    std::string filename(argv);
    size_t number;
    float aux;

    //Try to open the file
    std::ifstream input_file(filename);
    if (!input_file.is_open()) { return 1;}

    //Get the money
    if (!(input_file >> aux)) { return 2;}
    KB->set_wage(aux);
    //Get the rounds
    if (!(input_file >> number)) { return 3;}
    KB->set_rounds(number);
    //Get the spots
    while (input_file >> number) {
        if(KB->size() >= 20){ return 5;}
        KB->add_spot(number);
        
    }
    if(KB->size() == 0){ return 4;}

    input_file.close();
    return 0;
}

void print_line(size_t qnt){
    for(size_t i = 0 ; i < qnt;i++){ std::cout << "-";}
    std::cout << std::endl;
    return;
}
int main( int argc, char *argv[] )
{

    size_t erro;
    Keno::KenoBet KB;
    Keno::cash_type total = 0;

    std::cout << ">>> Preparing to read bet file[" << argv[1] <<"], please wait...\n";
    erro = analyze_file(argv[1], &KB);
    //Verify possible errors
    switch (erro)
    {
    case 1:
        std::cout << ">>> ERROR 1: COULD NOT OPEN THE FILE - '" 
            << argv << "'." << std::endl;
        
        return EXIT_FAILURE;
    case 2:
        std::cout << ">>> ERROR 2: INVALID INITIAL CREDIT." << std::endl;
        return EXIT_FAILURE;
    case 3:
        std::cout << ">>> ERROR 3: INVALID ROUND."<< std::endl;
        return EXIT_FAILURE;
    case 4:
        std::cout << ">>> ERROR 4: THERE IS NO SPOT."<< std::endl;
        return EXIT_FAILURE;
    case 5:
        std::cout << ">>> More than 20 spots were passed, only the first 20 valid spots were selected."<< std::endl;
        break;
    default:
        break;
    }
    std::cout << ">>> Bet successfully read!\n";
    std::cout << ">>> Starting the game!\n";

    total = KB.get_wage();
    print_line(80);
    KB.welcome();
    print_line(80);
    Keno::cash_type round_wage = KB.get_wage()/KB.get_rounds();
    for(size_t i = 0 ; i < KB.get_rounds();i++){
        total -= round_wage;
        KB.create_draw();
        Keno::set_of_numbers_type hits = KB.find_hits();
        std::cout << "  This is round #" << i+1 <<" of " << KB.get_rounds() << ", and your wage is $"<< std::fixed << std::setprecision(2) << round_wage <<". Good luck!\n";
        std::cout << "  The draws numbers are: ";
        KB.print_draw();
        std::cout <<  std::endl;
        std::cout << "  You hit the following number(s): [";   
        for(size_t i=0; i < hits.size();i++){
            std::cout << hits[i] << " ";
        }

        std::cout << "] a total of "<< hits.size()<<" hit out of "<< KB.size() <<".\n";
        total += KB.get_payout(hits.size())*(round_wage);
        std::cout << "  The payout rate is " << KB.get_payout(hits.size()) << ", thus you came out with: $" << KB.get_payout(hits.size())*(round_wage)<<"\n";
        std::cout << "  Your net balance so far is: $" << total << std::endl;

        print_line(80);
        
        
    }
    KB.summary(total);
    return EXIT_SUCCESS;
}
