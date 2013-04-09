// -*- coding: utf-8; -*-
/*!
 * 
 * \file Step.cpp
 * \brief Encapsulator of step data -- implementation
 * 
 * 
 * 
 * \author Johannes Knauf
 */

#ifdef STEP_HPP

namespace take_it_easy
{

  template <class Board>
  Step<Board>::Step(Board* const configuration, const card_id_type& random_remove_idx, const card_id_type& random_insert_idx) : take_it_easy_space(configuration)
  {
    remove_idx = random_remove_idx;
    insert_idx = random_insert_idx;
    assert(remove_idx != insert_idx);
    assert(remove_idx < 19);
    assert(insert_idx < 27);
  }

  template <class Board>
  Step<Board>::~Step()
  {
  }

  template <class Board>
  int Step<Board>::get_creation_simulation_time() const
  {
    return creation_simulation_time;
  }

  template <class Board>
  energy_type Step<Board>::delta_E() const
  {
    // quick and dirty and most unefficient: do move, calc energy, undo move
    const energy_type energy_before = take_it_easy_space->energy();
    take_it_easy_space->swap_cards(remove_idx, insert_idx);
    const energy_type energy_after = take_it_easy_space->energy();
    take_it_easy_space->swap_cards(remove_idx, insert_idx);
    assert(take_it_easy_space->energy() == energy_before);

    const energy_type energy_change = energy_after - energy_before;
    assert((energy_before + energy_change) >= 0);

    return energy_change;
  }

  template <class Board>
  bool Step<Board>::is_executable() const
  {
    return true;
  }

  template <class Board>
  card_id_type Step<Board>::get_remove_idx() const
  {
    return remove_idx;
  }

  template <class Board>
  card_id_type Step<Board>::get_insert_idx() const
  {
    return insert_idx;
  }

  template <class Board>
  void Step<Board>::execute()
  {
    take_it_easy_space->commit(*this);
  }

  template <class Board>
  double Step<Board>::selection_probability_factor() const
  {
    return 1.0;
  }


}


#endif
