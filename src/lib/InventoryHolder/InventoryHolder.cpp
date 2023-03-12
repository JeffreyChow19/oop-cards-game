#include "InventoryHolder.hpp"

template<typename T>
InventoryHolder<T>::InventoryHolder() {}

template<typename T>
InventoryHolder<T>::InventoryHolder(const InventoryHolder& other) {
    this->deck=other.deck;
}

template<typename T>
InventoryHolder<T>::~InventoryHolder() {
    this->deck.clear();
}

template<typename T>
InventoryHolder<T>& InventoryHolder<T>::operator+ (const T& toAdd) {
    // auto toAddPtr = make_shared<Card>(toAdd);
    // this->deck.push_back(make_shared<Card>(toAdd));
    this->deck.push_back(toAdd);
    return *this;
}

template<typename T>
InventoryHolder<T>& InventoryHolder<T>::operator- (const T& toRemove) {
    auto idxRemove = find(this->deck.begin(), this->deck.end(), toRemove);
    if (idxRemove != this->deck.end()) {
        this->deck.erase(idxRemove);
    }
    return *this;
}

template<typename T>
InventoryHolder<T>& InventoryHolder<T>::operator= (const InventoryHolder& other) {
    if (this != &other) {
        this->deck.clear();
        this->deck = other.deck;
    }
    return *this;
}