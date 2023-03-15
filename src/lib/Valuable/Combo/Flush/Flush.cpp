#include "Flush.hpp"

Flush::Flush(vector<ColorCard> cards)
{
    this->flushHand_ = cards;

    /* sort ascending by card value */
    sort(this->flushHand_.begin(), this->flushHand_.end(), ColorCard::compareByValue);
}

Flush::~Flush()
{
    this->flushHand_.clear();
}

float Flush::getValue() const
{
    /* base13Encoding for combination:
        process: get base13 value -> convert to decimal

        base-13:    X-X-X-X-X-C
        exp_index:  5-4-3-2-1-0

        X : card values of index [X-1], ascending; values of X={0...13}
        C : color bit {1..4}
    */

    /* color bit */
    int colorBit = this->flushHand_[0].getBaseValue() + 1;

    /* card value bits */
    int base13Encoding = 0;
    for (int i = 0; i < this->flushHand_.size(); i++)
    {
        base13Encoding += pow(13, i) * (this->flushHand_[i].getValue() - 1);
    }
}

void Flush::print()
{
    ColorCard::printGroup(this->flushHand_);
}
