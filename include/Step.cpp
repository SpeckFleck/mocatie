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

  template <class RandomNumberGenerator>
  Step<RandomNumberGenerator>::Step(Board<RandomNumberGenerator>* const configuration, const card_id_type& random_remove_idx, const card_id_type& random_insert_idx) : take_it_easy_space(configuration)
  {
    remove_idx = random_remove_idx;
    insert_idx = random_insert_idx;
  }

  template <class RandomNumberGenerator>
  Step<RandomNumberGenerator>::~Step()
  {
  }

  template <class RandomNumberGenerator>
  int Step<RandomNumberGenerator>::get_creation_simulation_time() const
  {
    return creation_simulation_time;
  }

  template <class RandomNumberGenerator>
  energy_type Step<RandomNumberGenerator>::delta_E() const
  {
    // quick and dirty and most unefficient: do move, calc energy, undo move
    const energy_type energy_before = take_it_easy_space->energy();
    take_it_easy_space->swap_cards(remove_idx, insert_idx);
    const energy_type energy_after = take_it_easy_space->energy();
    take_it_easy_space->swap_cards(remove_idx, insert_idx);

    return energy_after - energy_before; // TBD!
  }

  template <class RandomNumberGenerator>
  bool Step<RandomNumberGenerator>::is_executable() const
  {
    return true;
  }

  template <class RandomNumberGenerator>
  card_id_type Step<RandomNumberGenerator>::get_remove_idx() const
  {
    return remove_idx;
  }

  template <class RandomNumberGenerator>
  card_id_type Step<RandomNumberGenerator>::get_insert_idx() const
  {
    return insert_idx;
  }

  template <class RandomNumberGenerator>
  void Step<RandomNumberGenerator>::execute()
  {
    take_it_easy_space->commit(*this);
  }

  template <class RandomNumberGenerator>
  double Step<RandomNumberGenerator>::selection_probability_factor() const
  {
    return 1.0;
  }


}


#endif
