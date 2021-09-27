/*!
 *  This program implements the Keno game.
 *
 *  @author
 *  @file keno_bet.cpp
 *
 */

#include "keno_bet.h"

namespace Keno {

    bool KenoBet::add_spot( Keno::number_type spot )
    {
        if(spot < 1 ||spot > 80 ){
            std::cout << ">>> The number [" << spot << "] is out of interval of spots, therefore will be ignored.\n" ;
                return false;
        }
        for(size_t i = 0; i < m_spots.size(); i++){
            if(spot == m_spots[i]){
                std::cout << ">>> The number [" << spot << "] is already in the spots, therefore will be ignored.\n" ;
                return true;
            }  
        }
        m_spots.push_back(spot);
        std::sort(m_spots.begin(), m_spots.end());
        return true;
    }

    bool KenoBet::set_wage( Keno::cash_type wage )
    {
        if(wage >= 100000)
        {
            std::cout << ">>> INVALID INPUT: You are spending a large amount of money, please be modest.\n";
            return false;
        }else
        {
            m_wage = wage;
        }
        return false;
    }

    bool KenoBet::set_rounds( Keno::number_type rounds)
    {
        m_rounds = rounds;
        return true;
    }

    void KenoBet::reset()
    {   
        m_spots.clear();
        m_wage = 0;

    }

    Keno::cash_type KenoBet::get_wage( void ) const
    {
        if(!m_wage){
            std::cout << ">>> INVALID OPERATION: You called a NULL variable, please use set_wage() to initialized it.\n";
            return 0;
        }
        return m_wage;
    }

    size_t KenoBet::size( void ) const
    {   
        return m_spots.size();
    }

    Keno::number_type KenoBet::get_rounds( void )
    {
        return m_rounds;
    }

    float KenoBet::get_payout(Keno::number_type hit)
    {
        return payout[m_spots.size()-1][hit];
    }

    void KenoBet::create_draw( void )
    {
        draw.clear();
        // hold all numbers from 1 to 80
        std::vector<int> all_numbers;
        // hold the 20 values drawn
        //std::vector<int> draw;
        // loop to initialize the possible values of the draw
        for(int i = 0; i < 80; i++) all_numbers.push_back(i + 1);
        // time-based seed
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        // shuffle all possible values
        shuffle(all_numbers.begin(), all_numbers.end(), std::default_random_engine(seed));
        // copy the first 20 values
        for(int i = 0; i < 20; i++) draw.push_back(all_numbers[i]);
        // sort the values drawn
        sort(draw.begin(), draw.end());
        return;
    }

    void KenoBet::print_draw( void )
    {
        std::cout << "[";
        for(size_t i=0; i < draw.size()-1; i++){
            std::cout << draw[i] << " ";
        }
        std::cout << draw[(draw.size()-1)] << "]\n";
        return;
    }

    Keno::set_of_numbers_type
    KenoBet::find_hits() const
    {
        // This container will store all common elements, if any exists.
        Keno::set_of_numbers_type intersection;
        //std::vector<int> intersection(20); 
        std::set_intersection(m_spots.begin(), m_spots.end(), draw.begin(), draw.end(), std::back_inserter(intersection));
        return intersection;
    }


    Keno::set_of_numbers_type
    KenoBet::get_spots( void ) const
    {
        Keno::set_of_numbers_type dummy;
        if(m_spots.size() == 0){
            std::cout << ">>> INVALID OPERATION: The spots are empty, please use add_spot() ta fill it.\n";
        }
        for (size_t i=0; i< m_spots.size(); i++)
            dummy.push_back(m_spots[i]);
        return dummy;
    }

    void KenoBet::summary(Keno::cash_type total)
    {
        std::cout << "===== SUMMARY =====" << '\n';
        std::cout << ">>> You spent in this game a total of " << m_wage << " dollars.\n";
        if(total > m_wage) std::cout << ">>> Hooray, you won " << total - m_wage << " dollars. See you next time!\n";
        else if(total == m_wage) std::cout << ">>> You won 0 dollars. Or did you lose 0 dollars? Half-full or half-empty? Anyway, see you next time!\n";
        else std::cout << ">>> Oops... you lost " << m_wage - total << " dollars. See you (hopefully with more luck) next time!\n";
    }

    void KenoBet::welcome( void ) 
    {
        size_t bet_sz = m_spots.size();
        std::cout << "  You are going to wage a total of $" << m_wage << " dollars.\n";
        std::cout << "  Going for a total of " << m_rounds << " rounds, waging $" << (m_wage/m_rounds) << " per round.\n";
        std::cout << std::endl;
        std::cout << "  Your bet has " << bet_sz << " numbers. They are: [ ";
        for(size_t i = 0; i < bet_sz; i++) std::cout << m_spots[i] << " ";
        std::cout << "]\n";

        std::cout << "  ------+-------\n";
        std::cout << "  Hits  | Payout\n";
        std::cout << "  ------+-------\n";
        for(size_t i = 0; i <= bet_sz; i++) std::cout << "  "<< i << "    | " << payout[bet_sz-1][i] << "       \n";
    }
} // namespace Keno


//============[ End KenoBet class ]===============//
