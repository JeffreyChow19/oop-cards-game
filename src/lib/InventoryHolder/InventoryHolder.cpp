#include "InventoryHolder.hpp"

template <typename T>
InventoryHolder<T>::InventoryHolder() {}

template <typename T>
InventoryHolder<T>::InventoryHolder(const InventoryHolder &other)
{
    for (auto elmt : other.deck) {
        this->deck.push_back(elmt);
    }
}

template <typename T>
InventoryHolder<T>::~InventoryHolder()
{
    this->deck.clear();
}

template <typename T>
InventoryHolder<T> &InventoryHolder<T>::operator+(const T &toAdd)
{
    // auto toAddPtr = make_shared<Card>(toAdd);
    // this->deck.push_back(make_shared<Card>(toAdd));
    this->deck.push_back(toAdd);
    return *this;
}

template <typename T>
InventoryHolder<T> &InventoryHolder<T>::operator-(const T &toRemove)
{
    auto idxRemove = find(this->deck.begin(), this->deck.end(), toRemove);
    if (idxRemove != this->deck.end())
    {
        this->deck.erase(idxRemove);
    }
    return *this;
}

