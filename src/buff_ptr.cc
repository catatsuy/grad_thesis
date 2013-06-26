namespace ArchHDL {
static uint buffCurr[BUFF_SIZE_MAX];
static uint buffNext[BUFF_SIZE_MAX];
static int register_size_curr;
static int register_size_next;
class Singleton {
  /**  */
 public:
  void* GetCurrPtr(int size) {
    if (register_size_curr >= BUFF_SIZE_MAX) {
      printf("enlarge the BUFF_SIZE_MAX %d\n", BUFF_SIZE_MAX);
      exit(0);
    }
    void* rtn = &buffCurr[register_size_curr];
    int tmp = size / sizeof(uint);
    if (tmp == 0) {
      tmp = 1;
    }
    register_size_curr += tmp;
    return rtn;
  }
  void* GetNextPtr(int size) { /**  */ }
}
