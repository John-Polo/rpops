/*
 * PoPS model - deterministic neighbor dispersal kernel
 *
 * Copyright (C) 2020 by the authors.
 *
 * Authors: Vaclav Petras (wenzeslaus gmail com)
 *
 * The code contained herein is licensed under the GNU General Public
 * License. You may obtain a copy of the GNU General Public License
 * Version 2 or later at the following locations:
 *
 * http://www.opensource.org/licenses/gpl-license.html
 * http://www.gnu.org/copyleft/gpl.html
 */

#ifndef POPS_NEIGHBOR_KERNEL_HPP
#define POPS_NEIGHBOR_KERNEL_HPP

#include "kernel_types.hpp"
#include "radial_kernel.hpp"

namespace pops {

/*! Dispersal kernel for deterministic spread to a next cell
 *
 * This kernel spreads only in one direction specified by a parameter.
 * It is useful for testing because the result is completely
 * deterministic.
 *
 * When a diagonal direction such as SE is used, disperser is moved
 * one cell in each cooresponding cardial direction, i.e., 1 S and 1 E
 * for SE.
 */
class DeterministicNeighborDispersalKernel
{
protected:
    Direction direction_;
public:
    DeterministicNeighborDispersalKernel(Direction dispersal_direction)
        :
          direction_(dispersal_direction)
    {}

    /*! \copybrief RadialDispersalKernel::operator()()
     *
     * Thehere is no randomness, so the *generator*
     * is unused.
     */
    template<typename Generator>
    std::tuple<int, int> operator() (Generator& generator, int row, int col)
    {
        switch (direction_) {
        case Direction::E:
            col += 1;
            break;
        case Direction::N:
            row -= 1;
            break;
        case Direction::NE:
            row -= 1;
            col += 1;
            break;
        case Direction::NW:
            row -= 1;
            col -= 1;
            break;
        case Direction::S:
            row += 1;
            break;
        case Direction::SE:
            row += 1;
            col += 1;
            break;
        case Direction::SW:
            row += 1;
            col -= 1;
            break;
        case Direction::W:
            col -= 1;
            break;
        default:
            throw std::invalid_argument("NeighborDispersalKernel: Unsupported Direction");
        }
        return std::make_tuple(row, col);
    }

    /*! Enum value is defined, so this always returns false.
     */
    static bool supports_kernel(const DispersalKernelType type)
    {
        return false;
    }
};

} // namespace pops

#endif // POPS_NEIGHBOR_KERNEL_HPP