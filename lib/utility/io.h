static int Scanner(void) {
  int x = 0, f = 1, c;
  while (c = getchar_unlocked(), c < 48 || c > 57) if (c == 45) f = -f;
  while (47 < c && c < 58) {
    x = x * 10 + c - 48;
    c = getchar_unlocked();
  }
  return f * x;
}

static int* ScannerMulti(int n) {
  int* res = (int *)malloc(n*sizeof(int));
  for (int i=0;i<n;++i) res[i] = Scanner();
  return res;
}

static char* ScannerString(int n) {
  char* res = (char *)malloc(n*sizeof(char));
  char c = getchar_unlocked();
  while (c < 32) c = getchar_unlocked();
  int i = 0;
  while (c >= 32) {
    res[i] = c;
    c = getchar_unlocked();
    i++;
  }
  res[i] = '\0';
  return res;
}

static void Printer(int64_t x) {
  if (x < 0) {
    putchar_unlocked('-');
    x = -x;
  }
  if (x >= 10) {
    Printer(x / 10);
  }
  putchar_unlocked(x - x / 10 * 10 + 48);
}

static void PrinterOne(int64_t x) {
    Printer(x);
    putchar_unlocked('\n');
}

static void PrinterArray(int64_t *x, int n) {
    for (int i=0;i<n-1;++i) {
        Printer(x[0]);
        putchar_unlocked(' ');
    }
    Printer(x[n-1]);
    putchar_unlocked('\n');
}