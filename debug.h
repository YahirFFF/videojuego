#define fastio
#define usaco(...)
#define info static int j = 1; cerr << "TEST CASE #" << j++ << ": " << '\n';
#define orz cerr << "====================================================\n\n";
#define del std::cerr << '\n'
#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)

template <class X, class Y>
std::ostream& operator<<(std::ostream& os, const std::pair<X, Y>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template <class Ch, class Tr, class Container>
auto operator<<(std::basic_ostream<Ch, Tr>& os, const Container& x)
    -> decltype(x.begin(), x.end(), os) {

    os << "{ ";
    bool first = true;
    for (const auto& y : x) {
        if (!first) os << ", ";
        first = false;
        os << y;
    }
    return os << " }";
}

template <typename... Args>
void _debug(const char* s, Args&&... args) {
    std::cerr << "{ ";
    std::size_t i = 0, cnt = 0, n = sizeof...(args);

    auto next = [&]() {
        while (s[i] && (s[i] == ' ' || s[i] == ',')) ++i;
        std::size_t st = i;
        while (s[i] && s[i] != ',') ++i;
        return std::string(s + st, i - st);
    };

    auto dummy = {
        (std::cerr << next() << ": " << args
                   << (++cnt < n ? ", " : ""), 0)...
    };
    (void)dummy;

    std::cerr << " }\n";
}


