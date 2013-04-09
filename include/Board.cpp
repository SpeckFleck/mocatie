// -*- coding: utf-8; -*-
/*!
 * 
 * \file Board.cpp
 * \brief Description of the take it easy board -- implementation
 * 
 * Data type: 27-array of Cards
 *
 *
 *
 *              00
 *            01  02
 *          03  04  05
 *            06  07
 *          08  09  10
 *            11  12
 *          13  14  15
 *            16  17
 *              18
 *
 * 
 * For later visualization: http://commons.wikimedia.org/wiki/File:Take_it_easy_Tiles.svg
 *
 * \author Johannes Knauf
 */

#ifdef BOARD_HPP

namespace take_it_easy
{

  Board::Board()
  { 
    // vertical: 1 5 9
    // up down diagonal: 3 4 8
    // bottom up diagonal: 2 6 7
    card_space[0] = gen_card(1, 3, 2);
    card_space[1] = gen_card(1, 3, 6);
    card_space[2] = gen_card(1, 3, 7);
    card_space[3] = gen_card(1, 4, 2);
    card_space[4] = gen_card(1, 4, 6);
    card_space[5] = gen_card(1, 4, 7);
    card_space[6] = gen_card(1, 8, 2);
    card_space[7] = gen_card(1, 8, 6);
    card_space[8] = gen_card(1, 8, 7);
    card_space[9] = gen_card(5, 3, 2);
    card_space[10] = gen_card(5, 3, 6);
    card_space[11] = gen_card(5, 3, 7);
    card_space[12] = gen_card(5, 4, 2);
    card_space[13] = gen_card(5, 4, 6);
    card_space[14] = gen_card(5, 4, 7);
    card_space[15] = gen_card(5, 8, 2);
    card_space[16] = gen_card(5, 8, 6);
    card_space[17] = gen_card(5, 8, 7);
    card_space[18] = gen_card(9, 3, 2);
    card_space[19] = gen_card(9, 3, 6);
    card_space[20] = gen_card(9, 3, 7);
    card_space[21] = gen_card(9, 4, 2);
    card_space[22] = gen_card(9, 4, 6);
    card_space[23] = gen_card(9, 4, 7);
    card_space[24] = gen_card(9, 8, 2);
    card_space[25] = gen_card(9, 8, 6);
    card_space[26] = gen_card(9, 8, 7);
  }

  Board::~Board()
  {
    for (card_id_type i = 0; i < 27; i++)
      delete card_space[i];
  }

  CardType* Board::gen_card(const CardNumberType& x, const CardNumberType& y, const CardNumberType& z)
  {
    CardType* new_card = new CardType();
    (*new_card)[0] = x;
    (*new_card)[1] = y;
    (*new_card)[2] = z;
    return new_card;
  }

  energy_type Board::energy() const
  {
    energy_type current_energy = 0;

    // currently all rules are hard coded
    // could definitely be coded more intelligently and adapted for easy delta_E generation in take_it_easy::Step

    // vertical lines
    if ((*(card_space[3]))[0] == (*(card_space[8]))[0] && 
	(*(card_space[3]))[0] == (*(card_space[13]))[0])
      {	current_energy += 3 * (*(card_space[3]))[0]; }
    if ((*(card_space[1]))[0] == (*(card_space[6]))[0] && 
	(*(card_space[1]))[0] == (*(card_space[11]))[0] && 
	(*(card_space[1]))[0] == (*(card_space[16]))[0])
      {	current_energy += 4 * (*(card_space[1]))[0]; }
    if ((*(card_space[0]))[0] == (*(card_space[4]))[0] && 
	(*(card_space[0]))[0] == (*(card_space[9]))[0] && 
	(*(card_space[0]))[0] == (*(card_space[14]))[0] &&
	(*(card_space[0]))[0] == (*(card_space[18]))[0])
      {	current_energy += 5 * (*(card_space[0]))[0]; }
    if ((*(card_space[2]))[0] == (*(card_space[7]))[0] && 
	(*(card_space[2]))[0] == (*(card_space[12]))[0] && 
	(*(card_space[2]))[0] == (*(card_space[17]))[0])
      {	current_energy += 4 * (*(card_space[2]))[0]; }
    if ((*(card_space[5]))[0] == (*(card_space[10]))[0] && 
	(*(card_space[5]))[0] == (*(card_space[15]))[0])
      {	current_energy += 3 * (*(card_space[5]))[0]; }

    // up down diagonal
    if ((*(card_space[0]))[1] == (*(card_space[2]))[1] && 
	(*(card_space[0]))[1] == (*(card_space[5]))[1])
      {	current_energy += 3 * (*(card_space[0]))[1]; }
    if ((*(card_space[1]))[1] == (*(card_space[4]))[1] && 
	(*(card_space[1]))[1] == (*(card_space[7]))[1] && 
	(*(card_space[1]))[1] == (*(card_space[10]))[1])
      {	current_energy += 4 * (*(card_space[1]))[1]; }
    if ((*(card_space[3]))[1] == (*(card_space[6]))[1] && 
	(*(card_space[3]))[1] == (*(card_space[9]))[1] && 
	(*(card_space[3]))[1] == (*(card_space[12]))[1] &&
	(*(card_space[3]))[1] == (*(card_space[15]))[1])
      {	current_energy += 5 * (*(card_space[3]))[1]; }
    if ((*(card_space[8]))[1] == (*(card_space[11]))[1] && 
	(*(card_space[8]))[1] == (*(card_space[14]))[1] && 
	(*(card_space[8]))[1] == (*(card_space[17]))[1])
      {	current_energy += 4 * (*(card_space[8]))[1]; }
    if ((*(card_space[13]))[1] == (*(card_space[16]))[1] && 
	(*(card_space[13]))[1] == (*(card_space[18]))[1])
      {	current_energy += 3 * (*(card_space[13]))[1]; }

    // bottom up diagonal
    if ((*(card_space[3]))[2] == (*(card_space[1]))[2] && 
	(*(card_space[3]))[2] == (*(card_space[0]))[2])
      {	current_energy += 3 * (*(card_space[3]))[2]; }
    if ((*(card_space[8]))[2] == (*(card_space[6]))[2] && 
	(*(card_space[8]))[2] == (*(card_space[4]))[2] && 
	(*(card_space[8]))[2] == (*(card_space[2]))[2])
      {	current_energy += 4 * (*(card_space[8]))[2]; }
    if ((*(card_space[13]))[2] == (*(card_space[11]))[2] && 
	(*(card_space[13]))[2] == (*(card_space[9]))[2] && 
	(*(card_space[13]))[2] == (*(card_space[7]))[2] &&
	(*(card_space[13]))[2] == (*(card_space[5]))[2])
      {	current_energy += 5 * (*(card_space[13]))[2]; }
    if ((*(card_space[16]))[2] == (*(card_space[14]))[2] && 
	(*(card_space[16]))[2] == (*(card_space[12]))[2] && 
	(*(card_space[16]))[2] == (*(card_space[10]))[2])
      {	current_energy += 4 * (*(card_space[16]))[2]; }
    if ((*(card_space[18]))[2] == (*(card_space[17]))[2] && 
	(*(card_space[18]))[2] == (*(card_space[15]))[2])
      {	current_energy += 3 * (*(card_space[18]))[2]; }

    assert (current_energy >= 0);
    return current_energy;
  }

  simulation_time_type Board::get_simulation_time() const
  {
    return simulation_time;
  }

  template<class RandomNumberGenerator>
  Step<Board> Board::propose_step(RandomNumberGenerator* rng)
  {
    const card_id_type remove_idx = rng->random_uint32(0, 18);
    const card_id_type insert_idx = rng->random_uint32(0, 25);
    if (insert_idx >= remove_idx)
      return Step<Board>(this, remove_idx, insert_idx + 1);
    else
      return Step<Board>(this, remove_idx, insert_idx);
  }

  void Board::commit(Step<Board>& step_to_commit)
  {
    const card_id_type remove_idx = step_to_commit.get_remove_idx();
    const card_id_type insert_idx = step_to_commit.get_insert_idx();

    swap_cards(remove_idx, insert_idx);
    simulation_time += 1;
  }
  
  void Board::swap_cards(const card_id_type& remove_idx, const card_id_type& insert_idx)
  {
    assert(remove_idx != insert_idx);
    assert(remove_idx < 27);
    assert(insert_idx < 27);

    CardType* const to_be_removed = card_space[remove_idx];
    CardType* const to_be_inserted = card_space[insert_idx];

    card_space[insert_idx] = to_be_removed;
    card_space[remove_idx] = to_be_inserted;
  }

  std::ostream& operator<<(std::ostream& out_stream, const Board& board)
  {
    out_stream << board.card_space;
    return out_stream;
  }

  std::ostream& operator<<(std::ostream& out_stream, const CardType& card)
  {
    const std::string separator("\t");
    out_stream << (int)card[0] << separator;
    out_stream << (int)card[1] << separator;
    out_stream << (int)card[2];
    return out_stream;
  }

  std::ostream& operator<<(std::ostream& out_stream, const CardVectorType& card_vector)
  {
    const std::string separator("\n");
    for (CardVectorType::const_iterator cv_it = card_vector.begin(); cv_it != card_vector.end(); cv_it++)
      {
	out_stream << *(*cv_it) << separator;
      }
    return out_stream;
  }
  
}


#endif
