template <typename T>
class reg : public RegisterInterface {
 private:
  T curr_;
  T next_;

  // disallow copy and assign
  reg<T>(const reg<T>& other);
  reg<T>& operator=(const reg<T>& rhs);
 public:
  reg(): curr_(0), next_(0) {
    ArchHDL::Singleton::GetInstance().AddRegister(this);
  }
  void Update() {
    curr_ = next_;
  }
  void operator=(T val) {
    curr_ =  val;
    next_ = val;
  }
  void operator<<=(T val) {
    next_ = val;
  }
  T operator()() {
    return curr_;
  }
};
