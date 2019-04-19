#pragma once

#include "date.h"
#include <memory>

enum class LogicalOperation {
    And,
    Or
};

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

class Node {
public:
    Node () = default;
    virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode (const Comparison& cmp, const Date& date);
    bool Evaluate (const Date& date, const string& event) const override;
private:
    const Comparison cmp_;
    const Date date_;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode (const Comparison& cmp, const string& event);
    bool Evaluate (const Date& date, const string& event) const override;
private:
    const Comparison cmp_;
    const string event_;
};

class EmptyNode : public Node {
public:
    EmptyNode () = default;
    bool Evaluate (const Date& date, const string& event) const override;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode (const LogicalOperation& op, const shared_ptr<Node>& lhs, const shared_ptr<Node>& rhs);
    bool Evaluate (const Date& date, const string& event) const override;
private:
    const LogicalOperation op_;
    const shared_ptr<Node> left;
    const shared_ptr<Node> right;
};