#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    int pos = 0;

    // Union of two sets
    set<string> setUnion(const set<string>& a, const set<string>& b) {
        set<string> res = a;
        res.insert(b.begin(), b.end());
        return res;
    }

    // Cartesian product of two sets
    set<string> setProduct(const set<string>& a, const set<string>& b) {
        if (a.empty()) return b;
        if (b.empty()) return a;
        set<string> res;
        for (const string& s1 : a) {
            for (const string& s2 : b) {
                res.insert(s1 + s2);
            }
        }
        return res;
    }

    // Factor: either a sequence of letters or '{' Expression '}'
    set<string> parseFactor(const string& s) {
        if (s[pos] == '{') {
            pos++; // skip '{'
            set<string> res = parseExpression(s);
            pos++; // skip '}'
            return res;
        } else {
            string word = "";
            while (pos < s.size() && islower(s[pos])) {
                word += s[pos++];
            }
            return {word};
        }
    }

    // Term: concatenation of factors (implicit multiplication)
    set<string> parseTerm(const string& s) {
        set<string> res = {""}; // multiplicative identity
        while (pos < s.size() && (islower(s[pos]) || s[pos] == '{')) {
            set<string> factor = parseFactor(s);
            res = setProduct(res, factor);
        }
        return res;
    }

    // Expression: union of comma-separated terms
    set<string> parseExpression(const string& s) {
        set<string> res = parseTerm(s);
        while (pos < s.size() && s[pos] == ',') {
            pos++; // skip ','
            set<string> nextTerm = parseTerm(s);
            res = setUnion(res, nextTerm);
        }
        return res;
    }

public:
    vector<string> braceExpansionII(string expression) {
        pos = 0;
        set<string> resultSet = parseExpression(expression);
        return vector<string>(resultSet.begin(), resultSet.end());
    }
};