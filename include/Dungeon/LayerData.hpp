/*!
 * \brief   Header of the class Dungeon factory
 * \file    DungeonFacory.hpp
 * \author  Kraghan, Aredhele
 * \version 0.1
 * \date    12/09/2016
 */

#ifndef __LAYER_DATA_HPP
#define __LAYER_DATA_HPP

#include <vector>

class LayerData
{
public:

    /*!
     * \brief   Default constructor
     */
    explicit LayerData();

    /*!
     * \brief   Constructor
     * \param   layerData   The data layer
     */
    explicit LayerData(std::vector<char> const&layerData);

    /*!
     * \brief   Destructor
     */
    virtual ~LayerData();

    /*!
     * \brief   Return the data layer
     * \return  the data layer
     */
    std::vector<char> const &getLayerData();

private:

    std::vector<char> m_layerData;

};

#endif // __LAYER_DATA_HPP
