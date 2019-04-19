#include "node.h"

using namespace std;

DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& date) : cmp_(cmp), date_(date){}
bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    if (cmp_ == Comparison::Equal) {
        return date_ == date;
    }
    else if (cmp_ == Comparison::NotEqual) {
        return date_ != date;
    }
    else if (cmp_ == Comparison::Greater) {
        return date_ < date;
    }
    else if (cmp_ == Comparison::GreaterOrEqual) {
        return date_ <= date;
    }
    else if (cmp_ == Comparison::Less) {
        return date_ > date;
    }
    else if (cmp_ == Comparison::LessOrEqual) {
        return date_ >= date;
    }
    return true;
}

EventComparisonNode::EventComparisonNode(const Comparison& cmp, const string& event) : cmp_(cmp), event_(event) {}
bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
    if (cmp_ == Comparison::Equal) {
        return event_ == event;
    }
    else if (cmp_ == Comparison::NotEqual) {
        return event_ != event;
    }
    else if (cmp_ == Comparison::Greater) {
        return event_ < event;
    }
    else if (cmp_ == Comparison::GreaterOrEqual) {
        return event_ <= event;
    }
    else if (cmp_ == Comparison::Less) {
        return event_ > event;
    }
    else if (cmp_ == Comparison::LessOrEqual) {
        return event_ >= event;
    }
    return true;
}

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
    return true;
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& op, const shared_ptr<Node>& lhs,
                                           const shared_ptr<Node>& rhs) : op_(op), left(lhs), right(rhs) {}
bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
    if (op_ == LogicalOperation::And) {
        return (left -> Evaluate(date, event)) && (right -> Evaluate(date, event));
    }
    else if (op_ == LogicalOperation::Or) {
        return (left -> Evaluate(date, event)) || (right -> Evaluate(date, event));
    }
    return true;
}


