#ifndef _KENO_BET_H_
#define _KENO_BET_H_


/*!
 *  Class the defines a Keno bet.
 *
 *  @author Selan R. dos Santos
 *  @file keno_bet.h
 */

#include "keno_common.h"

namespace Keno
{
    class KenoBet
    {
        public:
            //! Creates a Keno bet.
            /*! A Keno bet stores the player's picked numbers or spots, up to a limit passed as argument.
             *  Any attempt of inserting spots beyond the set limit is ignored.
             *  @param max_n_sposts_ Maximim number of spots this bet may hold.
             */
            KenoBet( ) : m_wage{0.f}
            { /* empty */ }

            //! Adds a number to the player's bet.
            /*! This method adds the number passed as argument to the player's spots
             *  only if the number is not already there.
             *  @param spot The number we wish to include in the bet.
             *  @return Returns true if number chosen is successfuly inserted; false otherwise.
             */
            bool add_spot( Keno::number_type spot );

            //! Sets the player's wage on this bet.
            /*! This method set the amount of money the player is betting.
             *  @param wage The wage.
             *  @return True if we have a wage above zero; false otherwise.
             */
            bool set_wage( Keno::cash_type wage );

            //! Sets the player's rounds.
            /*! This method set the amount of money the player is betting.
             *  @return Return the number of rounds.
             */
            Keno::number_type get_rounds( void );
            
            //! Return player's payout rate.
            /*! This method search the player payout rate in the payout vector.
             *  @return Return payout rate.
             *  @param hit Numbers of player hits.
             */
            float get_payout(Keno::number_type hit);

            //! Set the players number of rounds
            /*! This method set the number of player's round.
             *  @param wage The wage.
             *  @return True if we have a wage above zero; false otherwise.
             */
            bool set_rounds( Keno::number_type rounds);
            //! Resets a bet to an emtpy state.
            /*! Resets a bet object to an empty state, which means the spot list clered.
            */
            void reset();

            //! Recovers the player's wage on this particular bet.
            /*! Retrieves the player's wage on this bet.
             *  @return The wage value.
             */
            Keno::cash_type get_wage( void ) const;

            //! Performs the draw.
            /*! Draws 20 random and unique values ​​between 1 and 80 and stores them in a vector.
            */
            void create_draw( void );

            //! Prints the draw.
            /*! Print all 20 random values.
            */
            void print_draw( void );

            //! Return the amount of spots currently in the bet.
            /*! Returns to the application the current number of spots in the player's bet.
             *  @return Number of spots present in the bet.
             */
            size_t size( void ) const;

            /*! Determine how many spots from the player's match the hits passed as argument.
             * @param draw List of hits randomly chosen by the computer.
             * @return An vector with the list of hits according to the currently stored bet.
             */
            Keno::set_of_numbers_type find_hits() const;

            //! Return the player's spots.
            /*! Return an std::vector<number_type> with the spots the player has picked so far.
             *  @return The std::vector<number_type> with the plyer's spots picked so far.
             */
            Keno::set_of_numbers_type get_spots( void ) const;
            
            //! Welcome message.
            /*! Prints welcome message and bet information.
            */
            void welcome( void );

            //! Prints summary with the main information of the game.
            /*!
             *  @param total Total of players money after the rounds.
             */
            void summary(Keno::cash_type total );

        private:
            Keno::set_of_numbers_type m_spots;      //<!The player's bet, i.e.\ a set of numbers (aka spots).
            Keno::cash_type m_wage;                 //<!The player's wage
            Keno::set_of_numbers_type draw;         //<!The 20 values drawn
            Keno::number_type m_rounds;             //<!The number of rounds
            std::vector<std::vector<float>> payout  //<!Table of rewards multiplier
            {
                {0, 3},
                {0, 1, 9},
                {0, 1, 2, 16},
                {0, 0.5, 2, 6, 12},
                {0, 0.5, 1, 3, 15, 50},
                {0, 0.5, 1, 2, 3, 30, 75},
                {0, 0.5, 0.5, 1, 6, 12, 36, 100},
                {0, 0.5, 0.5, 1, 3, 6, 19, 90, 720},
                {0, 0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200},
                {0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800},
                {0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000},
                {0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000},
                {0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000},
                {0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500},
                {0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000}
            };

    };
}

#endif
