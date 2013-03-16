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

#include <boost/array.hpp>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include "Step.hpp"

namespace take_it_easy
{
  typedef boost::array<uint8_t, 3> CardType;
  typedef boost::array<CardType*, 27> CardVectorType;
  
  template<class RandomNumberGenerator>
  class Board
  {
  private:
    CardVectorType card_space;
    simulation_time_type simulation_time;

    CardType* gen_card(const uint8_t&, const uint8_t&, const uint8_t&);
  public:
    Board();
    ~Board();
    
    double energy() const;
    simulation_time_type get_simulation_time() const;
    Step<RandomNumberGenerator> propose_step(RandomNumberGenerator*);
    void commit(Step<RandomNumberGenerator>&);
    void swap_cards(const card_id_type&, const card_id_type&);

    template<class Archive> void serialize(Archive & ar, const unsigned int)
    {
      ar & simulation_time;
    }
  };
}


#include "Board.cpp"

#endif
