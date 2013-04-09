// -*- coding: utf-8; -*-
/*!
 * 
 * \file Board.hpp
 * \brief Description of the take it easy board -- header
 * 
 * 
 * 
 * \author Johannes Knauf
 */

#ifndef BOARD_HPP
#define BOARD_HPP

#include <cassert>
#include <boost/array.hpp>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include "Step.hpp"

namespace take_it_easy
{
  typedef uint8_t CardNumberType;
  typedef boost::array<CardNumberType, 3> CardType;
  typedef boost::array<CardType*, 27> CardVectorType;

  std::ostream& operator<<(std::ostream&, const CardType&);
  std::ostream& operator<<(std::ostream&, const CardVectorType&);

  class Board
  {
    friend std::ostream& operator<< (std::ostream&, const Board &);
  private:
    CardVectorType card_space;
    simulation_time_type simulation_time;

    CardType* gen_card(const CardNumberType&, const CardNumberType&, const CardNumberType&);
  public:
    Board();
    ~Board();
    
    energy_type energy() const;
    simulation_time_type get_simulation_time() const;
    template<class RandomNumberGenerator> Step<Board> propose_step(RandomNumberGenerator*);
    void commit(Step<Board>&);
    void swap_cards(const card_id_type&, const card_id_type&);

    template<class Archive> void serialize(Archive & ar, const unsigned int)
    {
      ar & simulation_time;
    }
  };
}


#include "Board.cpp"

#endif
