#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

#include <QVector>

namespace poly {
struct Term;
}

class Polynomial {
private:
    enum PowerOrder {
        POWER_INCREASING,
        POWER_DECREASING
    };

public:
    void addTerm(const poly::Term& term);
    
    operator QString() const;
    
    Polynomial operator-() const;
    
    Polynomial operator+(const Polynomial& rhs) const;
    
    Polynomial operator-(const Polynomial& rhs) const;
    
    Polynomial operator*(const Polynomial& rhs) const;

private:
    QVector<poly::Term> terms(PowerOrder powerOrder = POWER_DECREASING) const;

private:
    QVector<poly::Term> m_terms;
};

#endif // POLYNOMIAL_HPP
