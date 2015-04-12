#include <cstdio>

using namespace std;

int main(void) {
  unsigned test_cases;
  scanf("%u", &test_cases);

  for (unsigned i = 0; i < test_cases; ++i) {
    unsigned max_shyness;
    scanf("%u", &max_shyness);

    unsigned friends = 0;
    unsigned clapping_audience = 0;

    scanf(" ");
    for (unsigned j = 0; j <= max_shyness; ++j) {
      char current_count;
      scanf("%c", &current_count);
      current_count -= '0';

      unsigned additional_audience = 0;
      if (clapping_audience < j) {
        additional_audience = j - clapping_audience;
      }

      friends += additional_audience;
      clapping_audience += current_count + additional_audience;
    }

    printf("Case #%u: %u\n", i + 1, friends);
  }

  return 0;
}
