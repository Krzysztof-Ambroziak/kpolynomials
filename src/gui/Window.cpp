#include "Window.hpp"
#include "../kpoly/Parser.hpp"
#include "../kpoly/Polynomial.hpp"
#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSplitter>

Window::Window(QWidget* parent) :
        QMainWindow(parent),
        m_pPolyLbl(new QLabel(P_POLY_STR)),
        m_pPolyEdt(new QLineEdit),
        m_qPolyLbl(new QLabel(Q_POLY_STR)),
        m_qPolyEdt(new QLineEdit),
        m_negateBtn(new QPushButton("-P(x)")),
        m_additionBtn(new QPushButton("P(x) + Q(x)")),
        m_subtractionBtn(new QPushButton("P(x) - Q(x)")),
        m_multiplicationBtn(new QPushButton("P(x) · Q(x)")),
        m_resultLbl(new QLabel) {
    QWidget* centralWidget = new QWidget(this);
    QLayout* layout = new QVBoxLayout(centralWidget);
    QSplitter* splitter = new QSplitter(Qt::Orientation::Horizontal, centralWidget);
    
    m_pPolyLbl->setParent(centralWidget);
    m_pPolyEdt->setParent(centralWidget);
    m_qPolyLbl->setParent(centralWidget);
    m_qPolyEdt->setParent(centralWidget);
    m_negateBtn->setParent(splitter);
    m_additionBtn->setParent(splitter);
    m_subtractionBtn->setParent(splitter);
    m_multiplicationBtn->setParent(splitter);
    m_resultLbl->setParent(centralWidget);
    
    m_pPolyLbl->setAlignment(Qt::AlignCenter);
    m_pPolyEdt->setAlignment(Qt::AlignCenter);
    m_qPolyLbl->setAlignment(Qt::AlignCenter);
    m_qPolyEdt->setAlignment(Qt::AlignCenter);
    m_resultLbl->setAlignment(Qt::AlignCenter);
    m_resultLbl->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    
    splitter->addWidget(m_negateBtn);
    splitter->addWidget(m_additionBtn);
    splitter->addWidget(m_subtractionBtn);
    splitter->addWidget(m_multiplicationBtn);
    
    layout->addWidget(m_pPolyLbl);
    layout->addWidget(m_pPolyEdt);
    layout->addWidget(m_qPolyLbl);
    layout->addWidget(m_qPolyEdt);
    layout->addWidget(splitter);
    layout->addWidget(m_resultLbl);
    
    setCentralWidget(centralWidget);
    connectSlots();
}

void Window::connectSlots() {
    QObject::connect(m_pPolyEdt, &QLineEdit::textChanged, m_pPolyLbl, [this](const auto& str) {
        m_pPolyLbl->setText(P_POLY_STR + ' ' + Parser::parse(str));
    });
    QObject::connect(m_qPolyEdt, &QLineEdit::textChanged, m_qPolyLbl, [this](const auto& str) {
        m_qPolyLbl->setText(Q_POLY_STR + ' ' + Parser::parse(str));
    });
    QObject::connect(m_negateBtn, &QPushButton::clicked, m_resultLbl, [this]() {
        const auto& text = m_pPolyEdt->text();
        
        if(!text.isEmpty()) {
            const auto& p = Parser::parse(text);
            m_resultLbl->setText(m_negateBtn->text() + " = " + -p);
        }
    });
    QObject::connect(m_additionBtn, &QPushButton::clicked, m_resultLbl, [this]() {
        const auto& textP = m_pPolyEdt->text();
        const auto& textQ = m_qPolyEdt->text();
        
        if(!textP.isEmpty() && !textQ.isEmpty()) {
            const auto& p = Parser::parse(textP);
            const auto& q = Parser::parse(textQ);
            m_resultLbl->setText(m_additionBtn->text() + " = " + (p + q));
        }
    });
    QObject::connect(m_subtractionBtn, &QPushButton::clicked, m_resultLbl, [this]() {
        const auto& textP = m_pPolyEdt->text();
        const auto& textQ = m_qPolyEdt->text();
        
        if(!textP.isEmpty() && !textQ.isEmpty()) {
            const auto& p = Parser::parse(textP);
            const auto& q = Parser::parse(textQ);
            m_resultLbl->setText(m_subtractionBtn->text() + " = " + (p - q));
        }
    });
    QObject::connect(m_multiplicationBtn, &QPushButton::clicked, m_resultLbl, [this]() {
        const auto& textP = m_pPolyEdt->text();
        const auto& textQ = m_qPolyEdt->text();
        
        if(!textP.isEmpty() && !textQ.isEmpty()) {
            const auto& p = Parser::parse(textP);
            const auto& q = Parser::parse(textQ);
            m_resultLbl->setText(m_multiplicationBtn->text() + " = " + (p * q));
        }
    });
}
