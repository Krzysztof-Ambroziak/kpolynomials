#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <QVector>

namespace poly {
struct Term;
}

class Polynomial {
public:
    void addTerm(const poly::Term& term);

private:
    QVector<poly::Term> m_terms;
};

#endif // POLYNOMIAL_HPP
