#ifndef _INVENTORY_HOLDER_HPP_
#define _INVENTORY_HOLDER_HPP_

#include <bits/stdc++.h>
#include "../Valuable/Card/Card.hpp"
#include "../Valuable/Card/ColorCard/ColorCard.hpp"

using namespace std;

template <class T>
class InventoryHolder
{ // ini tuh dibuatnya kekmana?
protected:
    vector<T> deck;

public:
    /**
     * @brief Construct a new Inventory Holder object
     *
     */
    InventoryHolder();

    /**
     * @brief Copy Construct a new Inventory Holder object
     *
     * @param other
     */
    InventoryHolder(const InventoryHolder &other);

    /**
     * @brief Destroy the Inventory Holder object
     *
     */
    virtual ~InventoryHolder();

    /**
     * @brief Add card to InventoryHolder
     *
     * @param toAdd
     * @return InventoryHolder&
     */
    InventoryHolder &operator+(const T &toAdd);

    /**
     * @brief Remove card to InventoryHolder
     *
     * @param toRemove
     * @return InventoryHolder&
     */
    InventoryHolder &operator-(const T &toRemove);
};

#endif