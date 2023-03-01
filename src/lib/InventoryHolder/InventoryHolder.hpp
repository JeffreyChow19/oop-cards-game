#ifndef _INVENTORY_HOLDER_HPP_
#define _INVENTORY_HOLDER_HPP_

#include <bits/stdc++.h>
#include "../Card/Card.hpp"

using namespace std;

class InventoryHolder { // ini tuh dibuatnya kekmana? 
    protected:
        vector<Card> deck;

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
        InventoryHolder(const InventoryHolder& other);

        /**
         * @brief Destroy the Inventory Holder object
         * 
         */
        ~InventoryHolder();

        /**
         * @brief Add card to InventoryHolder
         * 
         * @param toAdd 
         * @return InventoryHolder& 
         */
        InventoryHolder& operator+ (const Card& toAdd);

        /**
         * @brief Remove card to InventoryHolder
         * 
         * @param toRemove 
         * @return InventoryHolder& 
         */
        InventoryHolder& operator- (const Card& toRemove);

        /**
         * @brief Assign InventoryHolder
         * 
         * @param other 
         * @return InventoryHolder& 
         */
        InventoryHolder& operator= (const Card& other);
        
};

#endif