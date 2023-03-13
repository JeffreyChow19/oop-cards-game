#include <ThreeOfAKind.hpp>


ThreeOfAKind::ThreeOfAKind(ColorCard firstCard, ColorCard secondCard, ColorCard thirdCard) 
{
    triple_ = make_tuple(firstCard, secondCard, thirdCard);
}

ThreeOfAKind::~ThreeOfAKind() {}

float ThreeOfAKind::getValue() 
{
    return (
        0.2 * get<0>(triple_).getValue()
        + 0.05 * max(get<0>(triple_).getBaseValue(), max(get<1>(triple_).getBaseValue(), get<2>(triple_).getBaseValue()))
        + 8.28 
    );       
}