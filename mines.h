#ifdef MINES

#ifndef __MINES_H__
#define __MINES_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define NUM_MINES 200

/*!
 * \name e3d objects for mine types
 */
/*! @{ */
#define MINE_SMALL_MINE_E3D "./3dobjects/trees/branch1.e3d"
#define MINE_MEDIUM_MINE_E3D "./3dobjects/trees/branch1.e3d"
#define MINE_HIGH_EXPLOSIVE_MINE_E3D "./3dobjects/trees/branch1.e3d"
#define MINE_TRAP_E3D "./3dobjects/trees/branch1.e3d"
#define MINE_CALTROP_E3D "./3dobjects/trees/branch1.e3d"
#define MINE_POISONED_CALTROP_E3D "./3dobjects/trees/branch1.e3d"
#define MINE_BARRICADE_E3D "./3dobjects/trees/branch1.e3d"
#define MINE_MANA_DRAINER_E3D "./3dobjects/trees/branch1.e3d"
#define MINE_MANA_BURNER_E3D "./3dobjects/trees/branch1.e3d"
#define MINE_UNINVIZIBILIZER_E3D "./3dobjects/trees/branch1.e3d"
#define MINE_MAGIC_IMMUNITY_REMOVAL_E3D "./3dobjects/trees/branch1.e3d"
/*! @} */

typedef struct
{
	int x;
	int y;
	int type;
	int obj_3d_id;
} mine;

/*!
 * \ingroup item
 * \brief   Puts the mine \a mine_id on the ground at coordinates (\a mine_x, \a mine_y).
 *
 *      Puts the mine \a mine_id at the coordinates (\a mine_x, \a mine_y) on the ground.
 *
 * \param mine_x     x coordinate of the mines position
 * \param mine_y     y coordinate of the mines position
 * \param mine_type  type of mine being placed
 * \param mine_id    index into \ref mine_list to be used for the mine
 *
 * \callgraph
 */
void put_mine_on_ground(int mine_x, int mine_y, int mine_type, int mine_id);

/*!
 * \ingroup item
 * \brief   Adds the mines given in \a data.
 *
 *      Adds the mines that are given in \a data.
 *
 * \param data  the data from the server for the mines to add
 *
 * \callgraph
 *
 * \note No sanity checks on \a data are performed. This may be a possible bug.
 * \bug No sanity checks on \a data are performed.
 */
void add_mines_from_list (const Uint8 *data);

/*!
 * \ingroup item
 * \brief   Removes the mine with the given \a object_id.
 *
 *      Searches for \a which_mine for the given \a object_id and passes this \a which_mine to remove_mine.
 *
 * \param object_id the object_id for the mine to remove
 *
 * \callgraph
 */
void click_mine(int object_id);

/*!
 * \ingroup item
 * \brief   Removes the mine with the given index \a which_mine from the \ref mine_list.
 *
 *      Removes the mine at the given index \a which_mine from the \ref mine_list with the "safe" removal effect. The list of mines will be adjusted accordingly.
 *
 * \param which_mine the index into \ref mine_list for the mine to remove
 *
 * \callgraph
 */
void remove_mine(int object_id);

/*!
 * \ingroup item
 * \brief   Removes all the mines from a map.
 *
 *      Removes all the mines on a map.
 *
 * \callgraph
 */
void remove_all_mines();

/*!
 * \ingroup item
 * \brief   "Primes" the mine at the given index \a which_mine from the \ref mine_list.
 *
 *      Shows the mine prime effect for the mine with the given index \a which_mine from the \ref mine_list.
 *
 * \param which_mine the index into \ref mine_list for the mine to "prime"
 *
 * \callgraph
 */
void prime_mine(int object_id);

/*!
 * \ingroup item
 * \brief   "Detonates" the mine with the given index \a which_mine from the \ref mine_list.
 *
 *      Removes the mine at the given index \a which_mine from the \ref mine_list with the "detonate" removal effect according to the mine type. The list of mines will be adjusted accordingly.
 *
 * \param which_mine the index into \ref mine_list for the mine to "detonate"
 *
 * \callgraph
 */
void detonate_mine(int object_id);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // __MINES_H__

#endif // MINES