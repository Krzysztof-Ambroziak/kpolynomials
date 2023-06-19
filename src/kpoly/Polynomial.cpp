#include "Polynomial.hpp"
#include "Global.hpp"

void Polynomial::addTerm(const poly::Term& t) {
    const auto& [newCoefficient, newPower] = t;
    
    for(int i = 0; i < m_terms.size(); i++) {
        const auto& [coefficient, power] = m_terms[i];
        
        if(power == newPower) {
            const auto coeff = coefficient + newCoefficient;
            if(coeff != 0)
                m_terms[i].coefficient = coeff;
            else
                m_terms.remove(i);
            return;
        }
    }
    m_terms.push_back(t);
}

Polynomial::operator QString() const {
    QString str;
    
    foreach(const poly::Term& term, terms()) {
        const auto [coefficient, power] = term;
        
        if(term.coefficient < 0)
            if(str.isEmpty())
                str += '-';
            else
                str += " - ";
        else
            if(!str.isEmpty())
                str += " + ";
        if(qAbs(coefficient) > 1 || power == 0)
            str += QString::number(qAbs(coefficient));
        if(power >= 1) {
            str += 'x';
            if(power >= 2)
                str += "<sup>" + QString::number(power) + "</sup>";
        }
    }
    
    return str;
}

Polynomial Polynomial::operator-() const {
    Polynomial polynomial;
    
    foreach (const auto& term, m_terms) {
        const auto& [coefficient, power] = term;
        polynomial.addTerm({-coefficient, power});
    }
    
    return polynomial;
}

Polynomial Polynomial::operator+(const Polynomial& rhs) const {
    auto polynomial(*this);
    
    foreach(const auto& term, rhs.m_terms) {
        polynomial.addTerm(term);
    }
    
    return polynomial;
}

Polynomial Polynomial::operator-(const Polynomial& rhs) const {
    return *this + -rhs;
}

Polynomial Polynomial::operator*(const Polynomial& rhs) const {
    Polynomial polynomial;
    
    foreach(const auto& term, m_terms) {
        const auto& [lCoeff, lPower] = term;
        foreach(const auto& rhsTerm, rhs.m_terms) {
            const auto& [rCoeff, rPower] = rhsTerm;
            polynomial.addTerm({lCoeff * rCoeff, lPower + rPower});
        }
    }
    
    return polynomial;
}

QVector<poly::Term> Polynomial::terms(PowerOrder powerOrder) const {
    static constexpr auto decreasing = [](auto a, auto b) -> bool { return a.power > b.power; };
    static constexpr auto increasing = [](auto a, auto b) -> bool { return a.power < b.power; };
    auto terms(m_terms);
    
    switch(powerOrder) {
    case POWER_INCREASING:
        std::sort(terms.begin(), terms.end(), increasing);
        break;
    case POWER_DECREASING:
        std::sort(terms.begin(), terms.end(), decreasing);
        break;
    default: {} // no default
    }
    
    return terms;
}
