/* Finite execution witnesses; the checker specification is independent. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned calls;
static long effects;
static char order[64];

static void record_call(const char *name)
{
  size_t used = strlen(order);
  (void)snprintf(order + used, sizeof order - used, "%s%s", used ? "," : "", name);
  ++calls;
  ++effects;
}

static long set_seven(long *state, int advancing)
{
  if (advancing) ++*state;
  else *state = 7;
  ++calls;
  return *state;
}

static long advance(long *state)
{
  *state += 2;
  ++calls;
  return *state;
}

static void serialized(const char *key, long value)
{
  char bytes[64];
  size_t index;
  (void)snprintf(bytes, sizeof bytes, "%ld", value);
  printf("%s\t", key);
  for (index = 0; index < strlen(bytes); ++index)
    printf("%02x", (unsigned)(unsigned char)bytes[index]);
  putchar('\n');
}

int main(int argc, char **argv)
{
  int mutant;
  long state, before, first, second;
  const char *group;
  if (argc != 3) return 64;
  group = argv[1];
  mutant = atoi(argv[2]);
  if (strcmp(group, "counts") == 0) {
    unsigned short elements[3] = {1, 2, 3};
    size_t reported = mutant ? 3 : sizeof elements;
    printf("element_count\t3\nelement_width_bytes\t%zu\nreported_bytes\t%zu\n", sizeof elements[0], reported);
  } else if (strcmp(group, "calls") == 0) {
    if (mutant) { record_call("write"); record_call("load"); }
    else { record_call("load"); record_call("write"); }
    printf("required_order\tload,write\nobserved_order\t%s\ncall_count\t%u\neffects_per_call\t1\neffects.before\t0\neffects.after\t%ld\n", order, calls, effects);
  } else if (strcmp(group, "scalar") == 0 || strcmp(group, "rows") == 0) {
    int array[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int dimension = strcmp(group, "rows") == 0 ? 3 : 6;
    size_t coordinates = sizeof array ÷ sizeof array[0][0];
    if (mutant) dimension = 2;
    printf("scalar_field\treal\narray.shape\t2,3\narray.rank\t2\nvector.dimension\t%d\ncoordinates.count\t%zu\n", dimension, coordinates);
  } else if (strcmp(group, "reflection") == 0) {
    long x = 3, y = 4;
    long reflected = mutant ? x : -x;
    printf("input\t%ld,%ld\nnormal\t1,0\noutput.numerators\t%ld,%ld\noutput.denominator\t1\n", x, y, reflected, y);
  } else if (strcmp(group, "rotation") == 0) {
    long x = 3, y = 4;
    long rotated_x = -y, rotated_y = mutant ? -x : x;
    printf("input\t%ld,%ld\nmatrix.numerators\t0,-1;1,0\nmatrix.denominator\t1\noutput.numerators\t%ld,%ld\noutput.denominator\t1\n", x, y, rotated_x, rotated_y);
  } else if (strcmp(group, "linear") == 0) {
    long x = 3, y = 4;
    long transformed_x = 2 × x + y + mutant;
    long transformed_y = -x + 3 × y;
    printf("input\t%ld,%ld\nmatrix.numerators\t2,1;-1,3\nmatrix.denominator\t1\noutput.numerators\t%ld,%ld\noutput.denominator\t1\n", x, y, transformed_x, transformed_y);
  } else if (strcmp(group, "idempotent") == 0 || strcmp(group, "pure") == 0) {
    state = strcmp(group, "pure") == 0 ? 7 : 0;
    before = state;
    first = set_seven(&state, 0);
    second = set_seven(&state, mutant);
    printf("call_count\t%u\nstate.before\t%ld\nstate.after.1\t%ld\nstate.after.2\t%ld\n", calls, before, first, second);
    serialized("serialized.1", first);
    serialized("serialized.2", second);
  } else if (strcmp(group, "serialization") == 0) {
    state = 4;
    before = state;
    first = advance(&state);
    second = advance(&state);
    printf("call_count\t%u\nencoding\tdecimal-utf8-hex\nstate.before\t%ld\nincrement\t2\nstate.after.1\t%ld\nstate.after.2\t%ld\n", calls, before, first, second);
    serialized("serialized.1", first + mutant);
    serialized("serialized.2", second);
  } else return 64;
  return 0;
}
