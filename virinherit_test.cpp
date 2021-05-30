//inherit virtualy
class iostream{};
class istream: public virtual iostream{};
class ostream: virtual public iostream{};