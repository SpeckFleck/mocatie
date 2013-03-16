// -*- coding: utf-8; -*-
/*!
 * 
 * \file Step.hpp
 * \brief Encapsulator for step data
 * 
 * Provides is_executable() interface for Mocasinns.
 * Provides execute() interface for Mocasinns.
 * Provides delta_E() interface for Mocasinns.
 * Provides selection_probability_factor() interface for Mocasinns.
 * Provides get_creation_simulation_time() interface for Mocasinns SimulationStatus() watcher.
 *
 * Contains backreference to the originating HardDiscs configuration space.
 * 
 * \author Johannes Knauf
 */

#ifndef STEP_HPP
#define STEP_HPP

namespace take_it_easy
{

  template <class> class Board;

  typedef uint8_t card_id_type;
  typedef uint32_t energy_type;
  typedef uint64_t simulation_time_type;

  template<class RandomNumberGenerator>
  class Step {
  private:
    Board<RandomNumberGenerator>* const take_it_easy_space;
    card_id_type remove_idx;
    card_id_type insert_idx;
    simulation_time_type creation_simulation_time;
  public:
    Step(Board<RandomNumberGenerator>* const, const card_id_type&, const card_id_type&);
    ~Step();
    int get_creation_simulation_time() const;
    energy_type delta_E() const;
    bool is_executable() const;
    void execute();
    card_id_type get_remove_idx() const;
    card_id_type get_insert_idx() const;
    double selection_probability_factor() const;
  };

}

#include <Step.cpp>

#endif
